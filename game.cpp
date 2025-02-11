// Template, 2024 IGAD Edition
// Get the latest version from: https://github.com/jbikker/tmpl8
// IGAD/NHTV/BUAS/UU - Jacco Bikker - 2006-2024

#include "precomp.h"
#include "game.h"
#include <ctime> 
#include "imgui.h"

// -----------------------------------------------------------
// Initialize the application
// -----------------------------------------------------------
void Game::Init()
{
	//seed the random number generator
	time_t time_ptr;
	time_ptr = time(NULL);
	tm* tm_local = localtime(&time_ptr);
	InitSeed(static_cast<uint>(tm_local->tm_sec * tm_local->tm_min * tm_local->tm_hour * tm_local->tm_wday * tm_local->tm_year));

	//init sand grid
	for (int i = 0; i < SCRWIDTH; i++) {
		for (int j = 0; j < SCRHEIGHT; j++) {
			sand[i][j] = 0;

		}
	}
}

// -----------------------------------------------------------
// Main application tick function - Executed once per frame
// -----------------------------------------------------------
void Game::Tick( float  deltaTime  )
{
	deltaTime = min( deltaTime, 0.1f );
	screen->Clear( 0 );
#ifdef _DEBUG

#endif




}

