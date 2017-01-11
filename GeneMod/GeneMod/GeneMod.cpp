// GeneMod.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SDL.h"
#include "SDLSession.h"
#include <thread>
#include "Renderer.h"
#include "Entity.h"

#undef main

int main()
{
	SDLSession session;
	//Start up SDL and create window
	if (!session.Init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		//Load media
		if (!session.GetRenderer()->LoadMedia())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;

			//The dot that will be moving around on the screen
			Entity dot;

			//The background scrolling offset
			int scrollingOffset = 0;

			//While application is running
			while (!quit)
			{
				//Handle events on queue
				while (SDL_PollEvent(&e) != 0)
				{
					//User requests quit
					if (e.type == SDL_QUIT)
					{
						quit = true;
					}

					//Handle input for the dot
					dot.handleEvent(e);
				}

				//Move the dot
				dot.move();

				//Scroll background
				--scrollingOffset;
				if (scrollingOffset < -session.GetRenderer()->GetBgTexture().getWidth())
				{
					scrollingOffset = 0;
				}

				//Clear screen
				SDL_SetRenderDrawColor(session.GetRenderer()->GetgRenderer(), 0xFF, 0xFF, 0xFF, 0xFF);
				SDL_RenderClear(session.GetRenderer()->GetgRenderer());

				//Render background
				session.GetRenderer()->GetBgTexture().render(scrollingOffset, 0);
				session.GetRenderer()->GetBgTexture().render(scrollingOffset + session.GetRenderer()->GetBgTexture().getWidth(), 0);

				//Render objects
				dot.render();

				//Update screen
				SDL_RenderPresent(session.GetRenderer()->GetgRenderer());
			}
		}
	}

	//Free resources and close SDL
	session.Close();
    return 0;
}

