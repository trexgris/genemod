#pragma once
#include "TCPSocket.h"
class ClientSocket;
class IPAddress;

class HostSocket : public TCPSocket
{
public:
	HostSocket(IPAddressWrapper& the_ip_address); //create and open a new socket, with an existing CIpAddress object

	HostSocket(Uint16 port); //create and open a new socket with the desired port
	bool Accept(ClientSocket&); //set a client CTcpSocket object after listening to the port
	virtual void OnReady(); //pure virtual
};

