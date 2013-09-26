#ifndef NETSTREAM_H_
#define NETSTREAM_H_

#include "ch.h"
#include "hal.h"

#define _net_stream_data \
   _base_channel_data \
   struct netconn * conn; \
   struct netbuf * inbuf; \
   size_t in_offset;

struct NetStreamVMT {
	_base_channel_methods
};

/**
* @extends BaseSequentialStream
*/
typedef struct {
   const struct NetStreamVMT *vmt;
   _net_stream_data
} NetStream;

#ifdef __cplusplus
extern "C" {
#endif
void nsObjectInit(NetStream *sp);
void nsStart(NetStream *sp, struct netconn * conn);
void nsStop(NetStream *sp);
#ifdef __cplusplus
}
#endif

#endif /* NETSTREAM_H_ */
