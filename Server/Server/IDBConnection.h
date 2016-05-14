#ifndef _IDB_CONNECTION_H
#define _IDB_CONNECTION_H
#include <string>

class idb_connection
{
public:
	virtual ~idb_connection(){};
	virtual bool connect(const std::string& dbName, const std::string& userName, const std::string& password) = 0;
	virtual bool disconnect() = 0;
	virtual bool open() = 0;
	virtual bool close() = 0;
};
#endif





