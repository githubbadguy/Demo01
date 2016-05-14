#pragma once
#include <string>

class base_exception
{
public:
	base_exception(const std::string& message){ this->_message = message; }
	virtual ~base_exception(){};

	virtual const std::string& what() const { return _message; }
	virtual void error(const std::string& message){ this->_message = message; }
	virtual void append(const std::string& message){ this->_message.append(message); }
	virtual const char* get_char() const{ return this->_message.c_str(); }
private:
	std::string _message;
};