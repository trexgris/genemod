#pragma once
#include <memory>
class Renderer;
class SDLSessionClient;
class SDLSessionHost;

class SDLSession
{
public:
	SDLSession();
	~SDLSession();
	virtual bool Init();
	void Close();
	std::shared_ptr<Renderer> GetRenderer() { return renderer; }
	void InitRenderer();
	virtual void OnLoop() {};
	virtual bool InitConnection() { return true; };
	void InitHostSession();
	void InitClientSession();

	std::shared_ptr<SDLSessionClient> GetsessionClient();
	std::shared_ptr<SDLSessionHost> GetsessionHost();
protected:
	bool connected;
private:
	std::shared_ptr<Renderer> renderer;
	std::shared_ptr<SDLSessionClient> sessionClient;
	std::shared_ptr<SDLSessionHost> sessionHost;
};

