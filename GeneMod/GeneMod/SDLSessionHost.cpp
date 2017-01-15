#include "stdafx.h"
#include "SDLSessionHost.h"
#include "HostSocket.h"
#include "ClientSocket.h"
#include <iostream>
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
				charbuf t;
				//process msg
				msg.UnLoadBytes(t);
					std::cout << t;
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
