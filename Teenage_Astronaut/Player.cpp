
//  Player.cpp
//  Teenage_Astronaut
//
//  Created by Jacob Lashner on 8/5/15.
//  Copyright (c) 2015 Teenage_Astronaut. All rights reserved.
//

#include "Player.h"
#include <SDL2/SDL.h>
#include "Engine.h"
#include "Tilemap.h"
#include "Camera.h"
#include <cmath>

SDL_Rect    up_clip = {16,0,16,16},
left_clip = {0,32,16,16},
down_clip = {16,32,16,16},
right_clip = {32,32,16,16};


void Player::Init(Engine* game, Tilemap* t, double x, double y){
    this->x = x;
    this->y = y;

    
    width = 32;
    height = 32;
    
    this->tm = t;
    
    dir = DOWN;
    
    if (game!= NULL){
        spritesheet = LTexture();
        spritesheet.loadFromFile("assets/sprites/astronaut_sprite.png", game->renderer);
    }
    
    vx = 0;
    vy = 0;
    vmax = 300;
}

void Player::Update(Engine* game){
    
    double delta = game->getDelta();
    double  new_x, new_y;
    
    new_x  = x + vx * delta;
    new_y  = y + vy * delta;

    if (new_x >= 0  && new_x + width <= tm->width){
        x = new_x;
    }
    if (new_y >= 0 && new_y + height <= tm->height){
        y = new_y;
    }
    
    if (force_move){
        if(abs(desired_x - x) < 1 && abs(desired_y - y) <1){
            x = desired_x;
            y = desired_y;
            force_move = false;
            vx = 0;
            vy = 0;
            printf("HERE");
        }
    }
    
}

void Player::Draw(Engine* game, Camera* camera){
    
    
    SDL_Rect clip;
    switch (dir){
        case UP:
            clip = up_clip; break;
        case DOWN:
            clip = down_clip; break;
        case RIGHT:
            clip = right_clip; break;
        case LEFT:
            clip = left_clip; break;
        default:
            clip = down_clip; break;
    }
    SDL_Rect view = camera->getView();
    
    SDL_Rect dest = {(int) x - view.x, (int) y - view.y, width, height};
    
    spritesheet.render((int)x, (int)y, game->renderer, &clip, &dest);
    
}

void Player::HandleInput(SDL_Event e){
    if (!force_move){
        if (e.type == SDL_KEYDOWN){
            switch (e.key.keysym.sym){
                    
                case SDLK_UP:
                    this->vy = -vmax;
                    dir = UP;
                    vx = 0;
                    break;
                case SDLK_DOWN:
                    this->vy = vmax;
                    dir = DOWN;
                    vx = 0;
                    break;
                case SDLK_RIGHT:
                    this->vx = vmax;
                    dir = RIGHT;
                    vy = 0;
                    break;
                case SDLK_LEFT:
                    this->vx = -vmax;
                    dir = LEFT;
                    vy = 0;
                    break;
                
            }
        }
        if (e.type == SDL_KEYUP){
            switch (e.key.keysym.sym){
                    
                case SDLK_UP:
                    if (this->vy < 0)
                        this->vy = 0;
                    break;
                case SDLK_DOWN:
                    if (this->vy > 0)
                        this->vy = 0;
                    break;
                case SDLK_RIGHT:
                    if (this->vx > 0)
                        this->vx = 0;
                    break;
                case SDLK_LEFT:
                    if (this->vx < 0)
                        this->vx = 0;
                    break;
                    
            }
    }
    }
}


void Player::Pause(){
    vx = 0;
    vy = 0;
    x = (int)x;
    y = (int)y;
    
}

