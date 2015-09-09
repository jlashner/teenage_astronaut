//
//  Player.h
//  Teenage_Astronaut
//
//  Created by Jacob Lashner on 8/5/15.
//  Copyright (c) 2015 Teenage_Astronaut. All rights reserved.
//

#include <SDL2/SDL.h>
#include "Engine.h"
#include "LTexture.h"
#include "Tilemap.h"
#include "Entity.h"
#include "Animation.h"

#ifndef __Teenage_Astronaut__Player__
#define __Teenage_Astronaut__Player__


class Player : public Entity{
    
private:
    
    SDL_Rect location;
    LTexture spritesheet;
    bool player_control;
    
    
    Tilemap* tm;

public:
    
    void Init(Engine* game, Tilemap* tm, double x, double y);

    void LoadAnimation(string file_path, int row, int col_start, int width, int height,
                       int frames, Animation* a, bool loop = true, bool flip = false);
    void setAnimation();
    void Update();
    void HandleInput(SDL_Event e);
    void Draw(Camera* camera);
    
    void Pause();
};

#include <iostream>

#endif /* defined(__Teenage_Astronaut__Player__) */
