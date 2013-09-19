#ifndef NETSTREAM_H_
#define NETSTREAM_H_

#include "ch.h"

#define _net_stream_data \
  _base_sequential_stream_data \
  struct netconn * conn; \
  size_t in_offset;

struct NetStreamVMT {
	_base_sequential_stream_methods
};

/**
 * @extends BaseSequentialStream
 *
 * @brief Memory stream object.
 */
typedef struct {
	const struct NetStreamVMT *vmt;_net_stream_data
} NetStream;

#ifdef __cplusplus
extern "C" {
#endif
void nsObjectInit(NetStream *sp, struct netconn * conn);
#ifdef __cplusplus
}
#endif

#endif /* NETSTREAM_H_ */
