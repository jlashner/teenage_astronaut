//
//  battle_state.h
//  Teenage_Astronaut
//
//  Created by Jacob Lashner on 8/17/15.
//  Copyright (c) 2015 Teenage_Astronaut. All rights reserved.
//

#ifndef __Teenage_Astronaut__battle_state__
#define __Teenage_Astronaut__battle_state__

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_mixer/SDL_mixer.h>
#include "Engine.h"
#include "GameState.h"
#include "LTexture.h"
#include "TextBox.h"
#include "Song.h"

class BattleState : public GameState
{
public:
    void Init(Engine* game);
    void Cleanup();
    
    void Pause();
    void Resume();
    
	void HandleEvents(Engine* game, SDL_Event event);
	void Update(Engine* game);
	void Draw(Engine* game);
    
    static BattleState* Instance() {
		return &m_BattleState;
	}
    
protected:
    BattleState() {}
    
private:
    int next_note = 0;
    static BattleState m_BattleState;
    double allowed_error = .2; // in seconds
    
    Song song;

    
    
};

#endif /* defined(__Teenage_Astronaut__battle_state__) */
