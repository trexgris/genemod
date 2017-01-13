#include "stdafx.h"
#include "SDLSessionClient.h"


SDLSessionClient::SDLSessionClient()
	:
	connected(false),
	tcpclient(nullptr),
	remoteIp(nullptr)
{
}


SDLSessionClient::~SDLSessionClient()
{
}


bool SDLSessionClient::Init()
{
	SDLSession::Init();
	tcpclient = std::make_unique<ClientSocket>();
	remoteIp = std::make_unique<IPAddressWrapper>("195.132.100.229", 1234);
}