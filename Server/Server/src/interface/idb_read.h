#ifndef _IDB_READ_H
#define _IDB_READ_H
#include <string>

class idb_read
{
public:
	virtual ~idb_read(){};
	virtual bool read(const std::string& sql, void** result) = 0;
};

#endif
