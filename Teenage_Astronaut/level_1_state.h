//
//  mainmenu_state.h
//  Teenage_Astronaut
//
//  Created by Jacob Lashner on 8/5/15.
//  Copyright (c) 2015 Teenage_Astronaut. All rights reserved.
//


#include <SDL2/SDL.h>
#include "gamestate.h"
#include <iostream>

#include "Player.h"
#include "Tilemap.h"
#include "Camera.h"
#include "LevelState.h"
#include "RunState.h"

#ifndef LEVEL1_H
#define LEVEL1_H



class Level1State : public LevelState
{
public:
	void Init(Engine* game, RunState* run_state);
	void Cleanup();
    
	void Pause();
	void Resume();
    
	void HandleEvents(Engine* game, SDL_Event event);
	void Update(Engine* game);
	void Draw(Engine* game);
    
	static Level1State* Instance() {
		return &m_Level1State;
	}
    
    Player player;

    int level_width, level_height;
    
protected:
	Level1State() {}
    
private:
	static Level1State m_Level1State;
    Tilemap tm;
};

#endif
