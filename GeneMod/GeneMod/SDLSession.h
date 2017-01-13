#pragma once
#include <memory>
class Renderer;

class SDLSession
{
public:
	SDLSession();
	~SDLSession();
	virtual bool Init();
	void Close();
	std::shared_ptr<Renderer> GetRenderer() { return renderer; }
	void InitRenderer();

private:
	std::shared_ptr<Renderer> renderer;
};

