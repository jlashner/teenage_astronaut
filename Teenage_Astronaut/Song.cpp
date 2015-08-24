//
//  Song.cpp
//  Teenage_Astronaut
//
//  Created by Jacob Lashner on 8/17/15.
//  Copyright (c) 2015 Teenage_Astronaut. All rights reserved.
//

#include "Song.h"
#include "Engine.h"
#include <SDL2_mixer/SDL_mixer.h>

using namespace std;

void Song::Init(Engine* game, string file_name, double bpm, double delay){
    BPM = bpm;
    time = delay;
    
    vel = 200;
    
    double beat_length = (double)(60/BPM);
    music = Mix_LoadMUS(file_name.c_str());
    
    strum_y = game->getHeight()*.8;
    
    for (int i = 0; i < 10; i++){
        notes.push_back(Note((i + 5)*beat_length));
    }
    
}

Song::~Song(){
    Mix_FreeMusic( music );
    music = NULL;
}

void Song::Play(){
    if( Mix_PlayingMusic() == 0 )
    {
        //Play the music
        Mix_PlayMusic( music, -1 );
    }
}

void Song::Pause(){ Mix_PauseMusic();}
void Song::Resume(){Mix_ResumeMusic();}

void Song::Draw(Engine* game){
    
    SDL_RenderClear(game->renderer);
    SDL_SetRenderDrawColor(game->renderer, 255, 255, 255, 255);
    SDL_RenderDrawLine(game->renderer, 0, strum_y, 640, strum_y);
    
    int note_y;
    for( int i = 0; i < notes.size(); i++){
        note_y = (double)(strum_y - (notes[i].getTimePlayed() - time)*vel);
        if (note_y > 0 && note_y < game->getHeight())
            notes[i].Draw(game->renderer, game->getWidth()/2, note_y);
    }
}

