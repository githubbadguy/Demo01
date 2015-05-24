#pragma once
#include <typeinfo>

class IDBResult
{
public:
	virtual ~IDBResult(){};
	virtual unsigned long Count() = 0;
	virtual void* GetRowAt(unsigned long index) = 0;
	virtual void f()
	{
		const type_info& info = typeid(1);
		info.name();
	}
};
