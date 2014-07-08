#include "ch.h"
#include "hal.h"

void *__dso_handle;
void __cxa_pure_virtual() {
	chSysHalt();
}
void _exit(int a) {
	(void)a;

	chSysHalt();
	for (;;) {
	}
}
int _kill(int a, int b) {
	(void)a;
	(void)b;

	chSysHalt();
	return -1;
}
int _getpid() {
	return 1;
}
