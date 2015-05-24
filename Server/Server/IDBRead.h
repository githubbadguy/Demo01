#pragma once
#include <string>

class IDBRead
{
public:
	virtual ~IDBRead(){};
	virtual bool Read(const std::string& sql, void** result) = 0;
};