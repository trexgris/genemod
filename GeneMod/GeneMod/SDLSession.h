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
protected:
	bool connected;
private:
	std::shared_ptr<Renderer> renderer;
	std::unique_ptr<SDLSessionClient> sessionClient;
	std::unique_ptr<SDLSessionHost> sessionHost;
};

