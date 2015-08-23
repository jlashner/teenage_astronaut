//
//  LevelState.h
//  Teenage_Astronaut
//
//  Created by Jacob Lashner on 8/21/15.
//  Copyright (c) 2015 Teenage_Astronaut. All rights reserved.
//

#ifndef __Teenage_Astronaut__LevelState__
#define __Teenage_Astronaut__LevelState__

#include <iostream>
#include <vector>
#include "Entity.h"
#include "Camera.h"
class RunState;
#include "RunState.h"
class LevelState
{
public:
	virtual void Init(Engine* game, RunState* run_state) = 0;
	virtual void Cleanup() = 0;
    
	virtual void Pause() = 0;
	virtual void Resume() = 0;
    
	virtual void HandleEvents(Engine* game, SDL_Event event) = 0;
	virtual void Update(Engine* game) = 0;
	virtual void Draw(Engine* game) = 0;
    
	void ChangeState(Engine* game, GameState* state) {
		game->ChangeState(state);
	}
    
    vector<Entity*> entities;
    Camera camera;
    RunState* run_state;
    
protected:
	LevelState() { }
};

#endif /* defined(__Teenage_Astronaut__LevelState__) */
