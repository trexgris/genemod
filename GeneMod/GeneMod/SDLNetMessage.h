#pragma once
#include "DefUtils.h"
class SDLNetMessage
{
public:
	SDLNetMessage();
	~SDLNetMessage();

protected:
	charbuf buffer; //message stored in buffer, limited to 256 bytes
	enum bufstates { //message states
		EMPTY,
		READING,
		WRITING,
		FULL
	};
	bufstates state; //the message state
	void Reset(); // reset message: fulfill it with zeroes and change its state to EMPTY
public:
				   //Virtual member function that indicates how many bytes may have to be loaded into the instance. By default, it works with strings that have a maximum
				   //of 255 characters.
	virtual int NumToLoad();

	//Virtual member function that indicates how many bytes may have to be downloaded from the instance.
	virtual int NumToUnLoad();

	void LoadBytes(charbuf& inputbuffer, int n); //Load a char set into the message buffer
	void UnLoadBytes(charbuf& destbuffer); //Unload a char set from the buffer
	void Finish(); //set the state object to full. No more data to be loaded
};

