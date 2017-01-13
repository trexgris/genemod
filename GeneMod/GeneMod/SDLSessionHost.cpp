#include "stdafx.h"
#include "SDLSessionHost.h"
#include "HostSocket.h"
#include "ClientSocket.h"

SDLSessionHost::SDLSessionHost()
	:connected(false)
	, tcplistener(nullptr)
{
}


bool SDLSessionHost::Init()
{
	SDLSession::Init();
	tcplistener = std::make_unique<HostSocket>(1234);
	if (!tcplistener->Ok())
		exit(EXIT_FAILURE);

	tcpclients.emplace_back(new ClientSocket());

}


SDLSessionHost::~SDLSessionHost()
{
}
