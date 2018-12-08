
#pragma once

#include <assert.h>
//Memory impl file


struct LinearMemory
{
	bool IsInit;

	char * data;
	int index;
	int size;
};

LinearMemory* mem;

void initLinearMemory(LinearMemory* lm, int slotSize, void* baseAdress = 0)
{
	if (baseAdress)
	{
		//lm->data = (char*)VirtualAlloc();

	}

	assert(lm->data);

	

}







