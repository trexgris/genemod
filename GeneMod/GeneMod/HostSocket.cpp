#include "stdafx.h"
#include "HostSocket.h"
#include "IPAddress.h"
#include "TCPSocket.h"
#include <iostream>
#include "ClientSocket.h"

HostSocket::~HostSocket()
{
}



HostSocket::HostSocket(IPAddressWrapper& the_ip_address) {
	TCPSocket::TCPSocket();
	IPaddress iph = the_ip_address.GetIpAddress();
	if (!(m_Socket = SDLNet_TCP_Open(&iph))) {
		SDLNet_FreeSocketSet(set);
		std::cerr << "SDLNet_TCP_Open: " << SDLNet_GetError() << std::endl;
	}
}

HostSocket::HostSocket(Uint16 port) {
	IPAddressWrapper iplistener(port);
	if (!iplistener.Ok()) {
		m_Socket = NULL;
	}
	else {
		TCPSocket::TCPSocket();
		IPaddress iph = iplistener.GetIpAddress();
		if (!(m_Socket = SDLNet_TCP_Open(&iph))) {
			SDLNet_FreeSocketSet(set);
			std::cerr << "SDLNet_TCP_Open: " << SDLNet_GetError() << std::endl;
		}
	}
}


bool HostSocket::Accept(ClientSocket& the_client_socket) {
	TCPsocket cs;
	if ((cs = SDLNet_TCP_Accept(m_Socket))) {
		the_client_socket.SetSocket(cs);
		return true;
	}
	else
		return false;
}

void HostSocket::OnReady() {

}