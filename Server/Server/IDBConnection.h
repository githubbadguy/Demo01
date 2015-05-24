#pragma once
#include <string>


class IDBConnection
{
public:
	virtual ~IDBConnection(){};
	virtual bool Connect(const std::string& dbName, const std::string& userName, const std::string& password) = 0;
	virtual bool DisConnect() = 0;
	virtual bool Open() = 0;
	virtual bool Close() = 0;
};

