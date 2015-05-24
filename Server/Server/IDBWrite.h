#pragma once

class IDBWrite
{
public:
	virtual ~IDBWrite(){};
	virtual bool Write(const std::string& sql) = 0;
};
