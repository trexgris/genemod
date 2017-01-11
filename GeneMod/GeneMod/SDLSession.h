#pragma once
#include <memory>
class Renderer;

class SDLSession
{
public:
	SDLSession();
	~SDLSession();
	bool Init();
	void Close();
	std::shared_ptr<Renderer> GetRenderer() { return renderer; }
private:
	std::shared_ptr<Renderer> renderer;
};

