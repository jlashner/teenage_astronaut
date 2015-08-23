//
//  Engine.cpp
//  Teenage_Astronaut
//
//  Created by Jacob Lashner on 8/5/15.
//  Copyright (c) 2015 Teenage_Astronaut. All rights reserved.
//

#include <SDL2/SDL.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <SDL2_mixer/SDL_mixer.h>
#include <SDL2_image/SDL_image.h>

#include "Engine.h"
#include "GameState.h"
#include "Timer.h"



void Engine::Init(const char *title, int width, int height, int bpp, bool fullscreen){
    int flags = 0;

    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    TTF_Init();
    if(fullscreen)
        flags = SDL_WINDOW_FULLSCREEN;
    
    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
    {
        printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
    }
    
    window = SDL_CreateWindow(title,
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              width, height,
                              flags);
    
    
    renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
    SDL_SetRenderDrawColor( renderer, 0, 0, 0, 0xFF );
    
    SDL_GetWindowSize(window, &this->width, &this->height);
    
    
    
    m_fullscreen = fullscreen;
    m_running = true;
    
    timer = Timer();
    
    
    printf("Engine init\n");
}

void Engine::Cleanup(){
    // cleanup the all states
	while ( !states.empty() ) {
		states.back()->Cleanup();
		states.pop_back();
	}
    
	// switch back to windowed mode so other
	// programs won't get accidentally resized

	printf("CGameEngine Cleanup\n");
    
	// shutdown SDL
	SDL_Quit();
    Mix_Quit();
    IMG_Quit();
}

void Engine::ChangeState(GameState* state)
{
	// cleanup the current state
	if ( !states.empty() ) {
		states.back()->Cleanup();
		states.pop_back();
	}
    
	// store and init the new state
	states.push_back(state);
	states.back()->Init(this);
}

void Engine::PushState(GameState* state)
{
	// pause current state
	if ( !states.empty() ) {
		states.back()->Pause();
	}
    
	// store and init the new state
	states.push_back(state);
	states.back()->Init(this);
}

void Engine::PopState()
{
	// cleanup the current state
	if ( !states.empty() ) {
		states.back()->Cleanup();
		states.pop_back();
	}
    
	// resume previous state
	if ( !states.empty() ) {
		states.back()->Resume();
	}
}


void Engine::HandleEvents()
{
	// let the state handle events
    SDL_Event event;
    
    if (SDL_PollEvent(&event)){
        if (event.type == SDL_QUIT)
            this->Quit();
        else
            states.back()->HandleEvents(this, event);
    }
}

void Engine::Update()
{
    delta = timer.timeSinceLastFrame();
	// let the state update the game
	states.back()->Update(this);
}

void Engine::Draw()
{
	// let the state draw the screen
	states.back()->Draw(this);
}
