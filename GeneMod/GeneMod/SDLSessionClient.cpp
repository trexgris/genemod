#include "stdafx.h"
#include "SDLSessionClient.h"
#include "ClientSocket.h"
#include <iostream>
SDLSessionClient::SDLSessionClient()
	:
	tcpclient(nullptr),
	remoteIp(nullptr)
{
}


SDLSessionClient::~SDLSessionClient()
{
}


bool SDLSessionClient::InitConnection()
{
	//SDLSession::Init();
	tcpclient = std::make_unique<ClientSocket>();
	remoteIp = std::make_unique<IPAddressWrapper>("195.132.100.229", 1234);
	return true;
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
		charbuf t;
		if (tcpclient->Ready())
		{
			if (tcpclient->Receive(msg))
			{
				//process msg
				 msg.UnLoadBytes(t);
				 std::cout << t;
			}
		}
		else
		{
			connected = false;
		}
	}
}
