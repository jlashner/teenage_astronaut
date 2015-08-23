//
//  RunState.h
//  Teenage_Astronaut
//
//  Created by Jacob Lashner on 8/21/15.
//  Copyright (c) 2015 Teenage_Astronaut. All rights reserved.
//

#ifndef __Teenage_Astronaut__RunState__
#define __Teenage_Astronaut__RunState__

#include <iostream>
#include "GameState.h"
#include "LevelState.h"
class Cutscene;
#include "Cutscene.h"


enum Levels{
    LEVEL_1_STATE,
    LEVEL_2_STATE,
    NUM_STATES
};

class RunState : public GameState{
public:
    void Init(Engine* game);
	void Cleanup();
    
	void Pause();
	void Resume();
    
	void HandleEvents(Engine* game, SDL_Event event);
	void Update(Engine* game);
	void Draw(Engine* game);
    
    void PlayCutscene(Cutscene* cs);
    void EndCutscene();
    
	static RunState* Instance() {
		return &m_RunState;
	}
    
protected:
	RunState() { }
    
private:
	static RunState m_RunState;
    std::vector<LevelState*> states;
    int cur_level = LEVEL_1_STATE;
    bool play_cutscene= false;
    Cutscene* cur_cutscene = NULL;
    
};

#endif /* defined(__Teenage_Astronaut__RunState__) */
