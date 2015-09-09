//
//  Animation.h
//  Teenage_Astronaut
//
//  Created by Jacob Lashner on 8/24/15.
//  Copyright (c) 2015 Teenage_Astronaut. All rights reserved.
//

#ifndef __Teenage_Astronaut__Animation__
#define __Teenage_Astronaut__Animation__

#include <iostream>
#include <SDL2/SDL.h>
#include <vector>
#include "Engine.h"
#include "LTexture.h"

using namespace std;



class Animation{
public:
    
    void Init(Engine* game, string spritesheet_path, vector<SDL_Rect> clips, bool loop = false, bool flip = false);
    void Play();
    void Pause();
    void Update(Engine* game);
    bool IsFinished();
    
    void Draw(Engine* game, int x, int y);
    
    
private:
    LTexture sprite_sheet;
    vector<SDL_Rect> clip_array;
    int width, height;
    int frame, num_frames;
    int numLoops;
    double time_between_frames = .15;
    double time_since_last_frame = 0;
    bool loop, should_play, flip;
    
};
#endif /* defined(__Teenage_Astronaut__Animation__) */