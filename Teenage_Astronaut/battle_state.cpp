//
//  battle_state.cpp
//  Teenage_Astronaut
//
//  Created by Jacob Lashner on 8/17/15.
//  Copyright (c) 2015 Teenage_Astronaut. All rights reserved.
//

#include "battle_state.h"
#include <SDL2_mixer/SDL_mixer.h>
#include <stdlib.h> 
#include <cmath>
#include "MidiFile.h"

BattleState BattleState::m_BattleState;

void BattleState::Init(Engine* game){
    song.Init(game,"assets/music/battle_test.ogg", 93.75, .1);
    
    song.Play();
    
};
void BattleState::Cleanup(){

};

void BattleState::Pause(){};
void BattleState::Resume(){};

void BattleState::HandleEvents(Engine* game, SDL_Event event){
    switch (event.type) {
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
                case SDLK_SPACE:
                    
                    for (int i = next_note;( i < next_note + 4 && i < song.notes.size()); i++){
                        if(abs((song.time - song.notes[i].getTimePlayed())) < allowed_error){
                            song.notes[i].hit = true;
                        }
                    }
                    break;
            }
            break;
    }
};


void BattleState::Update(Engine* game){
    song.time += game->getDelta();
    if (next_note < song.notes.size() && song.notes[next_note].getTimePlayed() - song.time < -allowed_error){
            if(!song.notes[next_note].hit)
                 printf("missed\n");
            next_note++;
        
    }
};


void BattleState::Draw(Engine* game){

    SDL_SetRenderDrawColor(game->renderer, 0, 0, 0, 255);
    SDL_RenderClear(game->renderer);
    
    song.Draw(game);
 };
