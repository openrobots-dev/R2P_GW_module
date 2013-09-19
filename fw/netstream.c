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

static size_t write(void *ip, const uint8_t *bp, size_t n) {
	NetStream *sp = ip;

	return netconn_write_partly(sp->conn, bp, n, NETCONN_COPY, NULL);
}

static size_t read(void *ip, uint8_t *bp, size_t n) {
	NetStream *sp = ip;
	struct netbuf *inbuf;
	err_t err;
	size_t w ;

	/* Check if there is still data from last packet. */
	if (sp->in_offset == 0) {
		/* Wait for new packet. */
		do {
			err = netconn_recv(sp->conn, &inbuf);
		} while (err != ERR_OK);
	}

	chSysLock();
	w = netbuf_copy_partial(inbuf, bp, n, sp->in_offset);
	sp->in_offset += w;
	if (sp->in_offset >= netbuf_len(inbuf)) {
		netbuf_free(inbuf);
		sp->in_offset = 0;
	}
	chSysUnlock();

	/*
	 netbuf_data(inbuf, (void **) &buf, &buflen);
	 while (n-- && buflen--) {
	 *bp++ = *buf++;
	 w++;
	 }
	 */

	return w;
}

static msg_t put(void *ip, uint8_t b) {
	return (write(ip, &b, 1) == 1 ? Q_OK : Q_RESET);
}

static msg_t get(void *ip) {
	uint8_t b;

	return (read(ip, &b, 1) == 1 ? b : Q_RESET);
}

static const struct NetStreamVMT vmt = { write, read, put, get };

uint8_t buffer[64];

void nsObjectInit(NetStream *sp, struct netconn * conn) {

	sp->vmt = &vmt;
	sp->conn = conn;
	sp->in_offset = 0;
}
