#include "stdafx.h"
#include "IPAddress.h"

#include <iostream>

IPAddressWrapper::~IPAddressWrapper()
{
}


IPAddressWrapper::IPAddressWrapper(Uint16 port) {
	if (SDLNet_ResolveHost(&m_Ip, NULL, port) < 0) {
		std::cerr << "SDLNet_ResolveHost: " << SDLNet_GetError() << std::endl;
		m_Ip.host = 0;
		m_Ip.port = 0;
	}
}


IPAddressWrapper::IPAddressWrapper(std::string host, Uint16 port) {
	if (SDLNet_ResolveHost(&m_Ip, host.c_str(), port) < 0) {
		std::cerr << "SDLNet_ResolveHost: " << SDLNet_GetError() << std::endl;
		m_Ip.host = 0;
		m_Ip.port = 0;
	}
}

IPAddressWrapper::IPAddressWrapper() {
	m_Ip.host = 0;
	m_Ip.port = 0;
}

bool IPAddressWrapper::Ok() const {
	return !(m_Ip.port == 0);
}

void IPAddressWrapper::SetIp(IPaddress sdl_ip) { //sets a CTcpSocket object from a existing SDL socket
	m_Ip = sdl_ip;
}

IPaddress IPAddressWrapper::GetIpAddress() const {
	return m_Ip;
}

Uint32 IPAddressWrapper::GetHost() const {
	return m_Ip.host;
}

Uint16 IPAddressWrapper::GetPort() const {
	return m_Ip.port;
}