#pragma once
#include "SDLSession.h"
#include <memory>
#include "SDLNetMessage.h"
#include "ClientSocket.h"

class IPAddressWrapper;
class ClientSocket;

class SDLSessionClient //: public SDLSession
{
public:
	SDLSessionClient();
	~SDLSessionClient();

	//bool Init() override;
	void OnLoop() ;
	bool InitConnection() ;
	void sendtest() {
		charbuf test = "c";
		msg.LoadBytes(test, 1);
		tcpclient->Send(msg);
	}
	
private:

	bool connected;
	std::unique_ptr<IPAddressWrapper> remoteIp;
	std::unique_ptr<ClientSocket> tcpclient;
	SDLNetMessage msg;
};

