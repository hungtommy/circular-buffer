#ifndef __CIRCULARBUFFER_H
#define __CIRCULARBUFFER_H

#include "stdint.h"

typedef uint8_t elemType;		// define the element type of the buffer

typedef struct {
	uint32_t size;		// size of the buffer
	uint32_t write;		// write position
	uint32_t read;		// read position
	uint32_t count;		// number of data existed in the buffer
	elemType * elems;		// start address of the buffer
}circularBuffer;

typedef enum {
	CIRCULAR_BUFFER_SUCCESS,
	CIRCULAR_BUFFER_IS_EMPTY,
	CIRCULAR_BUFFER_IS_FULL
}cbStatus;
	
void cbInit(circularBuffer * cb, elemType * elems, uint32_t size);
uint8_t cbIsEmpty(circularBuffer * cb);
uint8_t cbIsFull(circularBuffer * cb);
cbStatus cbWrite(circularBuffer * cb, elemType elem);
cbStatus cbRead(circularBuffer * cb, elemType * elem);

#endif
