#pragma once
#include <iostream>

class proto_message
{
public:
	proto_message();
	virtual ~proto_message();
	void serialize();
	void unserialize();
private:
	//std::streambuf _buf;
	//std::iostream _stream;
};

