#pragma once
#include "SDLSession.h"
#include <memory>
#include "SDLNetMessage.h"
#include <vector>

class HostSocket;
class ClientSocket;
class SDLSessionHost //: public SDLSession
{
public:
	SDLSessionHost();
	~SDLSessionHost();
	//bool Init() override;
	void OnLoop() ;
	bool InitConnection() ;

	//void Sendtest() {tcplistener->sen}

private:
	bool connected;
	std::unique_ptr<HostSocket> tcplistener;
	std::vector<std::unique_ptr<ClientSocket>> tcpclients;
	SDLNetMessage msg;
};

