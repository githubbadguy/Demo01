#ifndef _IDB_RESULT_H
#define _IDB_RESULT_H
#include <typeinfo>

class idb_result
{
public:
	virtual ~idb_result(){};
	virtual unsigned long count() = 0;
	virtual void* get_row_at(unsigned long index) = 0;
};

#endif

