#include "netstream.h"
#include <lwip/api.h>

#include "ch.h"
#include "hal.h"

static size_t write(void *ip, const uint8_t *bp, size_t n) {
	NetStream *sp = ip;
	err_t err;

	err = netconn_write_partly(sp->conn, bp, n, NETCONN_COPY, NULL);

	if (err != ERR_OK) {
		/* Connection closed (or any other errors). */
		nsStop(sp);

		return Q_RESET;
	}

	return (err == ERR_OK ? n : 0);
}

static size_t read(void *ip, uint8_t *bp, size_t n) {
	NetStream *sp = ip;
	err_t err;

	if (sp->conn == NULL) return Q_RESET;

	/* If last input buffer was completely consumed, wait for a new packet. */
	while (sp->inbuf == NULL) {
		/* Wait for new packet. */
		err = netconn_recv(sp->conn, &sp->inbuf);
		if (err != ERR_OK) {
			/* Connection closed (or any other errors). */
			nsStop(sp);

			return Q_RESET;
		}
	}

	netbuf_copy_partial(sp->inbuf, bp, n, sp->in_offset);
	sp->in_offset += n;

	/* Check if there is more data to read. */
	if (sp->in_offset >= netbuf_len(sp->inbuf)) {
		n -= (sp->in_offset - netbuf_len(sp->inbuf));
		netbuf_delete(sp->inbuf);
		sp->in_offset = 0;
		sp->inbuf = NULL;
	}

	return n;
}

static msg_t put(void *ip, uint8_t b) {
	return (write(ip, &b, 1) == 1 ? Q_OK : Q_RESET);
}

static msg_t get(void *ip) {
	uint8_t b;

	return (read(ip, &b, 1) == 1 ? b : Q_RESET);
}

/* Channel put method with timeout specification.*/
static msg_t putt(void *ip, uint8_t b, systime_t time) {

	(void) time;

	return put(ip, b);
}

/* Channel get method with timeout specification.*/
static msg_t gett(void *ip, systime_t time) {

	(void) time;

	return get(ip);
}
/* Channel write method with timeout specification.*/
static size_t writet(void *ip, const uint8_t *bp, size_t n, systime_t time) {

	(void) time;

	return write(ip, bp, n);

}
/* Channel read method with timeout specification.*/
static size_t readt(void *ip, uint8_t *bp, size_t n, systime_t time) {

	(void) time;

	return read(ip, bp, n);

}



static const struct NetStreamVMT vmt = { write, read, put, get, putt, gett, writet, readt };

void nsObjectInit(NetStream *sp) {

	sp->vmt = &vmt;
	sp->inbuf = NULL;
	sp->in_offset = 0;
}

void nsStart(NetStream *sp, struct netconn * conn) {

	sp->conn = conn;
}

void nsStop(NetStream *sp) {
	netconn_close(sp->conn);
	netconn_delete(sp->conn);
	sp->conn = NULL;
}

