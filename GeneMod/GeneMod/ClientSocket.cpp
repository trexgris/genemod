#include "stdafx.h"
#include "ClientSocket.h"
#include <iostream>
#include "TCPSocket.h"
#include "DefUtils.h"
#include "SDLNetMessage.h"
ClientSocket::ClientSocket() {
	TCPSocket::TCPSocket();
}

ClientSocket::ClientSocket(std::string host, Uint16 port) {
	IPAddressWrapper remoteip(host.c_str(), port);
	if (!remoteip.Ok()) {
		m_Socket = NULL;
	}
	else {
		TCPSocket::TCPSocket();
		Connect(remoteip);
	}
}

bool ClientSocket::Connect(HostSocket& the_listener_socket) {
	return false;
}

bool ClientSocket::Connect(IPAddressWrapper& remoteip) {
	TCPsocket cs;
	IPaddress ip = remoteip.GetIpAddress();
	
	if ((cs = SDLNet_TCP_Open(&ip)))
	{
		SetSocket(cs);
		return true;
	}
	else {
		std::cerr << "SDLNet_TCP_Open: " << SDLNet_GetError() << std::endl;
		return false;
	}
}

void ClientSocket::SetSocket(TCPsocket the_sdl_socket) {
	TCPSocket::SetSocket(the_sdl_socket);
	IPaddress* ips;
	if ((ips = SDLNet_TCP_GetPeerAddress(m_Socket))) {
		/* Print the address, converting it onto the host format */
		m_RemoteIp.SetIp(*ips);
		Uint32 hbo = m_RemoteIp.GetHost();
		Uint16 pbo = m_RemoteIp.GetPort();
		std::cout << "Client connected: " << SDLNet_Read32(&hbo) << ' '
			<< SDLNet_Read16(&pbo) << std::endl;
	}
	else
		std::cerr << "SDLNet_TCP_GetPeerAddress: " << SDLNet_GetError() << std::endl;
}

IPAddressWrapper ClientSocket::getIpAddress() const {
	return m_RemoteIp;
}

bool ClientSocket::Receive(SDLNetMessage& rData) {
	//Firstly, check if there is a socket
	if (m_Socket == NULL)
		return false;
	charbuf buf;

	//Check if the instance can receive bytes, if it can, load the number of bytes specified by NumToLoad() virtual function
	while (rData.NumToLoad() > 0) {
		if (SDLNet_TCP_Recv(m_Socket, buf, rData.NumToLoad()) > 0) {
			rData.LoadBytes(buf, rData.NumToLoad());
		}
		else {
			return false;
		}
	}
	rData.Finish();
	return true;
}

bool ClientSocket::Send(SDLNetMessage& sData) {
	//check if there is a socket
	if (m_Socket == NULL)
		return false;
	charbuf buf;
	int len;

	//Check if the instance can send bytes, if it can, unload the number of bytes specified by NumToLoad() virtual function
	while ((len = sData.NumToUnLoad()) > 0) {
		sData.UnLoadBytes(buf);
		if (SDLNet_TCP_Send(m_Socket, (void *)buf, len) < len) {
			std::cerr << "SDLNet_TCP_Send: " << SDLNet_GetError() << std::endl;
			return false;
		}
	}
	return true;
}

void ClientSocket::OnReady() {

}