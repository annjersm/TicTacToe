#include <SDL2/SDL.h>
#include <stdio.h>

#include "init.h"
#include "event.h"
#include "brett.h"

extern SDL_Window* window;
extern SDL_Surface* wSurface;
extern SDL_Surface* xBmp;
extern SDL_Surface* oBmp;
extern SDL_Rect t1, t2, t3, t4, t5, t6, t7, t8, t9;

void Log() {
	printf("Hello Darling\n");
}

void App() {
	LSD_Init();

	cleanBoard();
	spillBrett();
	SDL_FillRect(wSurface, NULL, SDL_MapRGB(wSurface->format, 0x42,0x42,0x42));
	SDL_Rect tiles[] = {t1, t2, t3, t4, t5, t6, t7, t8, t9};
	SDL_FillRects(wSurface, tiles, 9, SDL_MapRGB(wSurface->format, 0x69,0x69,0x69));


	// Main Loop
	bool running = true;
	while (running) {
		
		// Evemts
		running = event(running);

		// Brett
		spillBrett();

		// Update the window
		SDL_UpdateWindowSurface(window);

		// Sjekker om det er noen winner
		//checkBrett();
		// - Flyttet tile event.c
	}

	// End of application
	
	SDL_FreeSurface(xBmp);
	SDL_FreeSurface(oBmp);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
