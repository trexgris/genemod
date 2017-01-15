#pragma once
#include "SDLSession.h"
#include <memory>
#include "SDLNetMessage.h"

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
	
private:

	bool connected;
	std::unique_ptr<IPAddressWrapper> remoteIp;
	std::unique_ptr<ClientSocket> tcpclient;
	SDLNetMessage msg;
};
