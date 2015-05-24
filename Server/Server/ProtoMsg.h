#pragma once
#include <iostream>

class ProtoMsg
{
public:
	ProtoMsg();
	virtual ~ProtoMsg();
	void Serialize();
	void UnSerialize();
private:
	//std::streambuf _buf;
	//std::iostream _stream;
};

