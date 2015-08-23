//
//  RunState.cpp
//  Teenage_Astronaut
//
//  Created by Jacob Lashner on 8/21/15.
//  Copyright (c) 2015 Teenage_Astronaut. All rights reserved.
//

#include "RunState.h"
#include <vector>
#include "level_1_state.h"
RunState RunState::m_RunState;



void RunState::Init(Engine *game){
    states.resize(NUM_STATES);
    states[0] = Level1State::Instance();
    states[0]->Init(game, this);
    
    cur_level = 0;
}

void RunState::Cleanup(){
    for(LevelState *state : states){
        if (state!=NULL)
            state->Cleanup();
    }
}

void RunState::Pause(){}
void RunState::Resume(){}

void RunState::PlayCutscene(Cutscene *cs){
    cur_cutscene = cs;
}
void RunState::EndCutscene(){
    cur_cutscene = NULL;
}

void RunState::HandleEvents(Engine* game, SDL_Event event){
    if (cur_cutscene)
        cur_cutscene->HandleEvents(game, event);
    else
        states[cur_level]->HandleEvents(game, event);
}

void RunState::Update(Engine* game){
    if (cur_cutscene)
        cur_cutscene->Update(game);
    else
        states[cur_level]->Update(game);
}

void RunState::Draw(Engine* game){
    if (cur_cutscene)
        cur_cutscene->Draw(game);
    else
        states[cur_level]->Draw(game);
}
