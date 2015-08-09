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

#ifndef __Teenage_Astronaut__Player__
#define __Teenage_Astronaut__Player__

enum Direction{UP, DOWN, LEFT, RIGHT,NONE};


class Player{
private:
    double x,y;
    double vx,vy,v = 300;
    SDL_Rect location;
    LTexture spritesheet;
    Direction dir;
    Tilemap* tm;
public:
    Player();
    ~Player();
    void Init(Engine* game,Tilemap* tm, double x = 0, double y = 0);
    double getX(){return x;};
    double getY(){return y;};
    void setX(double x){this->x = x;};
    void setY(double y){this->y = y;};
    
    void update(Engine* game);
    void handleInput(SDL_Event e);
    void draw(Engine* game, SDL_Rect camera);
    
    int height = 32,width = 32;
};

#include <iostream>

#endif /* defined(__Teenage_Astronaut__Player__) */
