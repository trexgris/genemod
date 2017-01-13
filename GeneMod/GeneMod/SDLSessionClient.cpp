#include "stdafx.h"
#include "SDLSessionClient.h"
#include "ClientSocket.h"

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

void SDLSessionClient::OnLoop()
{
	if (!connected)
	{
		if (tcpclient->Connect(*remoteIp))
		{
			if (tcpclient->Ok())
				connected = true;
		}
	}
	else
	{
		if (tcpclient->Ready())
		{
			if (tcpclient->Receive(msg))
			{
				//process msg
			}
		}
		else
		{
			connected = false;
		}
	}
}
