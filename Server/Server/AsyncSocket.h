#pragma once
class AsyncSocket
{
public:
	AsyncSocket();
	~AsyncSocket();


	virtual void OnSendTo();
	virtual void OnReceiveFrom();
	virtual void ReceiveFrom();

	virtual void OnReceive();
	virtual void OnSend();
	virtual void SendTo();
};

