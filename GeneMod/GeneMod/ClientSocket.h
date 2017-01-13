#pragma once
#include "IPAddress.h"

#include "TCPSocket.h"
class HostSocket;
class SDLNetMessage;
class ClientSocket : public TCPSocket
{
private:
	IPAddressWrapper m_RemoteIp; //the CIpAddress object corresponding to the remote host
public:
	ClientSocket(); //constructor
	ClientSocket(std::string host, Uint16 port); //Create the object and connect to a host, in a given port
	bool Connect(IPAddressWrapper& remoteip); //make a connection to communicate with a remote host
	bool Connect(HostSocket& the_listener_socket); //make a connection to communicate with a client
	void SetSocket(TCPsocket  the_sdl_socket); //set a CTcpSocket object from an existing SDL_net socket
	IPAddressWrapper getIpAddress() const; //return a CIpAddress object associated to the remote host
	virtual void OnReady(); //pure virtual
	bool Receive(SDLNetMessage& rData); //receive data and load it into a CNetMessage object
	bool Send(SDLNetMessage& sData); //send data from a CNetMessage object
};

