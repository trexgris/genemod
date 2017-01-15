#include "stdafx.h"
#include "SDLSessionHost.h"
#include "HostSocket.h"
#include "ClientSocket.h"

SDLSessionHost::SDLSessionHost():
	tcplistener(nullptr)
{
}


bool SDLSessionHost::InitConnection()
{
	//SDLSession::Init();
	tcplistener = std::make_unique<HostSocket>(1234);
	if (!tcplistener->Ok())
		exit(EXIT_FAILURE);

	tcpclients.emplace_back(new ClientSocket());

}

void SDLSessionHost::OnLoop()
{
	auto tcpclient = tcpclients.front().get();
	//front
	if (!connected)
	{
		if (tcplistener->Accept(*tcpclient))
			connected = true;
	}
	else
	{
		if (tcpclient->Ready())
		{
			if (tcpclient->Receive(msg))
			{
				//process msg
			}
			else
			{
				connected = false;
			}
		}
	}
}



SDLSessionHost::~SDLSessionHost()
{
}
