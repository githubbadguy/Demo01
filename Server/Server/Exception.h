#pragma once
#include <string>

class Exception
{
public:
	Exception(const std::string& message){ this->_message = message; }
	virtual ~Exception(){};

	virtual const std::string& What() const { return _message; }
	virtual void Error(const std::string& message){ this->_message = message; }
	virtual void Append(const std::string& message){ this->_message.append(message); }
	virtual const char* GetChar() const{ return this->_message.c_str(); }
private:
	std::string _message;
};