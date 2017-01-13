#include "stdafx.h"
#include "SDLNetMessage.h"
#include <cstring>


SDLNetMessage::SDLNetMessage()
{
	Reset();
}


SDLNetMessage::~SDLNetMessage()
{
}

void SDLNetMessage::Reset() {
	for (int i = 0; i < 256; i++)
		buffer[i] = 0;
	state = EMPTY;
}

void SDLNetMessage::Finish() {
	if (state == READING)
		state = FULL;
}

int SDLNetMessage::NumToLoad() {
	if (state == EMPTY)
		return 255;
	else
		return 0;
}

int SDLNetMessage::NumToUnLoad() {
	if (state == FULL)
		return strlen(buffer) + 1;
	else
		return 0;
}

void SDLNetMessage::LoadBytes(charbuf& inputbuffer, int n) {
	for (int i = 0; i < n; i++)
		buffer[i] = inputbuffer[i];
	state = READING;
}

void SDLNetMessage::UnLoadBytes(charbuf& destbuffer) {
	for (int i = 0; i < this->NumToUnLoad(); i++)
		destbuffer[i] = buffer[i];
	Reset();
}