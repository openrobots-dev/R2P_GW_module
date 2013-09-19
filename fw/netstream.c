#include "netstream.h"
#include "lwip/api.h"

#include "ch.h"
#include "hal.h"

/*
 NetStream *mystream = NULL;

 static void event_callback(struct netconn *conn, enum netconn_evt evt, u16_t len) {
 struct netbuf *inbuf;
 char *buf;
 u16_t buflen;
 err_t err;

 (void) len;

 if (conn && mystream) {
 chSysLock()
 if (evt == NETCONN_EVT_RCVPLUS) {
 err = netconn_recv(conn, &inbuf);

 if (err != ERR_OK) {
 chSysUnlock();
 return;
 }

 netbuf_data(inbuf, (void **) &buf, &buflen);

 while (buflen--) {
 if (chIQIsEmptyI(&mystream->iqueue)) {
 chnAddFlagsI(mystream, CHN_INPUT_AVAILABLE);
 }
 if (chIQPutI(&mystream->iqueue, buf++) < Q_OK) {
 chnAddFlagsI(mystream, SD_OVERRUN_ERROR);
 break;
 }
 }
 chSysUnlock();
 }
 }
 }

 */

static size_t writes(void *ip, const uint8_t *bp, size_t n) {
	NetStream *sp = ip;

	return netconn_write_partly(sp->conn, bp, n, NETCONN_COPY, NULL);
}

static size_t reads(void *ip, uint8_t *bp, size_t n) {
	NetStream *sp = ip;
	struct netbuf *inbuf;
	uint8_t *buf;
	u16_t buflen;
	err_t err;

	if (!chIQIsEmptyI(&sp->iqueue))
		return chIQGetTimeout(&sp->iqueue, TIME_IMMEDIATE);

	err = netconn_recv(sp->conn, &inbuf);

	if (err != ERR_OK) {
		return 0;
	}

	netbuf_data(inbuf, (void **) &buf, &buflen);
	while (buflen--) {
		if (chIQPutI(&sp->iqueue, (uint8_t) buf++) < Q_OK) {
			break;
		}
	}

	return chIQGetTimeout(&sp->iqueue, TIME_IMMEDIATE);
}

static msg_t put(void *ip, uint8_t b) {
	return (writes(ip, &b, 1) == 1 ? Q_OK : Q_RESET);
}

static msg_t get(void *ip) {
	uint8_t b;

	return (reads(ip, &b, 1) == 1 ? b : Q_RESET);
}

static const struct NetStreamVMT vmt = { writes, reads, put, get };

uint8_t buffer[64];

void nsObjectInit(NetStream *sp, struct netconn * conn) {

	sp->vmt = &vmt;
	sp->conn = conn;

	chIQInit(&sp->iqueue, buffer, sizeof(buffer), NULL, sp);
}
