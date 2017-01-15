#include "stdafx.h"
#include "TCPSocket.h"

#include <iostream>



TCPSocket::TCPSocket() {
	m_Socket = NULL;
	set = SDLNet_AllocSocketSet(1);
}

TCPSocket::~TCPSocket() {
	if (!(m_Socket == NULL)) {
		SDLNet_TCP_DelSocket(set, m_Socket);
		SDLNet_FreeSocketSet(set);
		SDLNet_TCP_Close(m_Socket);
	}
}

void TCPSocket::SetSocket(TCPsocket the_sdl_socket) {
	if (!(m_Socket == NULL)) {
		SDLNet_TCP_DelSocket(set, m_Socket);
		SDLNet_TCP_Close(m_Socket);
	}
	m_Socket = the_sdl_socket;
	if (SDLNet_TCP_AddSocket(set, m_Socket) == -1) {
		std::cerr << "SDLNet_TCP_AddSocket: " << SDLNet_GetError() << std::endl;
		m_Socket = NULL;
	}
}

bool TCPSocket::Ok() const {
	return !(m_Socket == NULL);
}

bool TCPSocket::Ready() const {
	bool rd = false;
	int numready = SDLNet_CheckSockets(set, 0);
	if (numready == -1)
		std::cerr << "SDLNet_CheckSockets: " << SDLNet_GetError() << std::endl;
	else
		if (numready)
			rd = SDLNet_SocketReady(m_Socket);
	return rd;
}

void TCPSocket::OnReady() {

}