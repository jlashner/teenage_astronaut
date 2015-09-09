//
//  Song.h
//  Teenage_Astronaut
//
//  Created by Jacob Lashner on 8/17/15.
//  Copyright (c) 2015 Teenage_Astronaut. All rights reserved.
//

#ifndef __Teenage_Astronaut__Song__
#define __Teenage_Astronaut__Song__

#include <iostream>
#include <vector>

#include <SDL2_mixer/SDL_mixer.h>
#include "Note.h"
#include "Engine.h"
using namespace std;

class Song{
    
public:
    double time;
    
    void Init(Engine* game, string file_name, double bpm, double delay);
    void LoadMidiFile(string filename);
    
    ~Song();
    
    void Play();
    void Pause();
    void Resume();

    void Draw(Engine* game);
    
    vector<Note> notes;
    

protected:
//    Song(){};
    
private:
    
    Mix_Music *music = NULL;
    double BPM;
    double vel = 100;
    int strum_y;
    
};

#endif /* defined(__Teenage_Astronaut__Song__) */
