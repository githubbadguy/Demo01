#pragma once
#include <typeinfo>

class IDBResult
{
public:
	virtual ~IDBResult(){};
	virtual unsigned long Count() = 0;
	virtual void* GetRowAt(unsigned long index) = 0;
};
