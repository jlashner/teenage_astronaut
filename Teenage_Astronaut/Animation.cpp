//
//  Animation.cpp
//  Teenage_Astronaut
//
//  Created by Jacob Lashner on 8/24/15.
//  Copyright (c) 2015 Teenage_Astronaut. All rights reserved.
//

#include "Animation.h"
#include "LTexture.h"

void Animation::Init(Engine* game, string spritesheet_path, vector<SDL_Rect> clips, bool loop, bool flip){
    this->loop = loop;
    this->flip = flip;
    
    clip_array = clips;
    num_frames = clips.size();
    
    sprite_sheet = LTexture();
    sprite_sheet.loadFromFile(spritesheet_path, game->renderer);
    printf("%d\n", num_frames);
    
    should_play = false;
    frame = 0;
}

void Animation::Play(){
    should_play = true;
}

void Animation::Pause(){
    should_play = false;
}

void Animation::Update(Engine* game){
    if (should_play){
        if (time_since_last_frame > time_between_frames){
            if (frame < num_frames - 1){
                frame++;
            }
            else{
                frame = 0;
                if (!loop){
                    should_play = false;
                }
            }
            time_since_last_frame = 0;
        } else{
            time_since_last_frame += game->getDelta();
        }
    }
}

void Animation::Draw(Engine* game, int x, int y){
    SDL_Rect clip = clip_array[frame];
    if (flip){
        sprite_sheet.render(x,y,game->renderer, &clip, NULL, 0, NULL, SDL_FLIP_HORIZONTAL);
    }else{
    sprite_sheet.render(x, y, game->renderer, &clip);
    }
}