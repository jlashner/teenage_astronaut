//
//  Entity.h
//  Teenage_Astronaut
//
//  Created by Jacob Lashner on 8/21/15.
//  Copyright (c) 2015 Teenage_Astronaut. All rights reserved.
//

#ifndef __Teenage_Astronaut__Entity__
#define __Teenage_Astronaut__Entity__

#include <iostream>

#include "LTexture.h"
#include "Engine.h"
#include "Tilemap.h"
class Camera;
#include "Camera.h"
#include <cmath>

enum Direction{UP, DOWN, LEFT, RIGHT,NONE};

class Entity{
    
protected:
    double x, y;
    double vx,vy,vmax;
    Direction dir;
    int width, height;
    LTexture spritesheet;
    
    bool paused = true;
    double desired_x, desired_y;
    
public:

    virtual void Init(Engine* game, Tilemap* tm, double x, double y) = 0;
    virtual void Update(Engine* game) = 0;
    virtual void HandleInput(SDL_Event e) = 0;
    virtual void Draw(Engine* game, Camera* camera) = 0;
    
    bool force_move = false;
    double getX(){return x;}
    double getY(){return y;}
    double getWidth(){return width;}
    double getHeight(){return height;}
    
    void Pause(){
//        paused = true;
        vx = 0;
        vy = 0;
    }
    void Unpause(){
//        paused = false;
    }
    
    void moveToXPos(int d_x){
        if (abs(x - d_x) > 1){
        force_move = true;
        desired_x = d_x;
        desired_y = y;
        vy = 0;
        if (desired_x < x){
            vx = -vmax;
            dir = LEFT;
        }else{
            vx = vmax;
            dir= RIGHT;
        }
    }
    }
    
    void moveToYPos(int d_y){
        force_move = true;
        desired_y = d_y;
        desired_x = x;
        vx = 0;
        if (desired_y < y){
            vy = -vmax;
            dir = UP;
        } else{
            vy = vmax;
            dir = DOWN;
        }
        vy = (desired_y < y) ? -vmax : vmax;
    }
    
    SDL_Rect getHitbox(){
        SDL_Rect hitbox = {(int)x,(int)y,(int)width,(int)height};
        return hitbox;
    }
};


#endif /* defined(__Teenage_Astronaut__Entity__) */
