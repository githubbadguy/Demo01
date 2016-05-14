#ifndef _IDB_WRITE_H
#define _IDB_WRITE_H
#include <string>

class idb_write
{
public:
	virtual ~idb_write(){};
	virtual bool write(const std::string& sql) = 0;
};
#endif // _IDB_WRITE_H

