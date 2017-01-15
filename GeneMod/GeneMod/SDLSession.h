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

	void OnloopHost() { sessionHost->OnLoop(); }
	void OnloopClient() { sessionClient->OnLoop(); }

	std::shared_ptr<SDLSessionClient> getsessionClient() { return sessionClient; };
	std::shared_ptr<SDLSessionHost> getsessionHost() { return sessionHost; };

	
protected:
	bool connected;
private:
	std::shared_ptr<Renderer> renderer;
	std::shared_ptr<SDLSessionClient> sessionClient;
	std::shared_ptr<SDLSessionHost> sessionHost;
};

