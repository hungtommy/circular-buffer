#include "circularBuffer.h"

void cbInit(circularBuffer * cb, elemType * elems, uint32_t size)
{
	cb->size = size;
	cb->write = 0;
	cb->read = 0;
	cb->count = 0;
	cb->elems = elems;
}

uint8_t cbIsEmpty(circularBuffer * cb)
{
	if (cb->count == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

uint8_t cbIsFull(circularBuffer * cb)
{	
	if (cb->count == cb->size)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

cbStatus cbWrite(circularBuffer * cb, elemType elem)
{
	if (cbIsFull(cb))
	{
		return CIRCULAR_BUFFER_IS_FULL;
	}
	else
	{
		cb->count++;
		
		cb->elems[cb->write++] = elem;
		
		//handle buffer overflow
		if (cb->write >= cb->size)
		{
			cb->write = 0;
		}
		
		return SUCCESS;
	}
}

cbStatus cbRead(circularBuffer * cb, elemType * elem)
{
	// check if empty
	if (cbIsEmpty(cb)) 
	{
		// case if the buffer is empty
		return CIRCULAR_BUFFER_IS_EMPTY;		
	}
	else 
	{
		// case if the buffer is not empty
		cb->count--;
		
		elem = &cb->elems[cb->read++];		// 

		// handle buffer overflow
		if (cb->read >= cb->size) 
		{
			cb->read = 0;
		}
		
		return SUCCESS;
	}
}

