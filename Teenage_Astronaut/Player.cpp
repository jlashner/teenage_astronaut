
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
    
    this->game = game;

    width = 32;
    height = 32;
    
    this->tm = t;
    
    move_dir = DOWN;
    move_type = IDLE;
    
    if (game!= NULL){
        spritesheet = LTexture();
        spritesheet.loadFromFile("assets/sprites/astronaut_sprite.png", game->renderer);
    }
    
    vx = 0;
    vy = 0;
    vmax = 200;
    
    string animation_sprites  ="assets/sprites/player_spritesheet.png";
    
    LoadAnimation(animation_sprites, 1, 0, 32, 32, 6, &walk_down_anim);
    LoadAnimation(animation_sprites, 2, 0, 32, 32, 6, &walk_up_anim);
    LoadAnimation(animation_sprites, 3, 0, 32, 32, 6, &walk_left_anim);
    LoadAnimation(animation_sprites, 3, 0, 32, 32, 8, &walk_right_anim, true, true);
    
    LoadAnimation(animation_sprites, 0, 0, 32, 32, 1, &idle_down_anim);
    LoadAnimation(animation_sprites, 0, 1, 32, 32, 1, &idle_up_anim);
    LoadAnimation(animation_sprites, 0, 2, 32, 32, 1, &idle_left_anim);
    LoadAnimation(animation_sprites, 0, 3, 32, 32, 1, &idle_right_anim, true, true);
    
    cur_animation = &idle_down_anim;
    }

void Player::setAnimation(){
    switch(move_dir){
        case UP:
            switch(move_type){
                case WALK:
                    cur_animation = &walk_up_anim;
                    break;
                case IDLE:
                    cur_animation = &idle_up_anim;
                    break;
            }
            break;
        case DOWN:
            switch(move_type){
                case WALK:
                    cur_animation = &walk_down_anim;
                    break;
                case IDLE:
                    cur_animation = &idle_down_anim;
                    break;
            }
            break;
        case LEFT:
            switch(move_type){
                case WALK:
                    cur_animation = &walk_left_anim;
                    break;
                case IDLE:
                    cur_animation = &idle_left_anim;
                    break;
            }
            break;
        case RIGHT:
            switch(move_type){
                case WALK:
                    cur_animation = &walk_right_anim;
                    break;
                case IDLE:
                    cur_animation = &idle_right_anim;
                    break;
            }
            break;
    }
    
}

void Player::Update(){
    
    setAnimation();
    cur_animation->Update(game);

    double delta = game->getDelta();
    double  new_x, new_y;
    
    new_x  = x + vx * delta;
    new_y  = y + vy * delta;
    
    if (move_dir == RIGHT && move_type == WALK)
        printf("Moving right\n");

    if (move_dir == DOWN && move_type == WALK)
        printf("Moving down\n");
    
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
            move_type = IDLE;
            vx = 0;
            vy = 0;
        }
    }
    
}

void Player::Draw(Camera* camera){
    
    
    SDL_Rect clip;
    switch (move_dir){
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
    
//    spritesheet.render((int)x, (int)y, game->renderer, &clip, &dest);
//    walk_down_anim.Draw(game, dest.x, dest.y);
    cur_animation->Draw(game, dest.x, dest.y);
    
}

void Player::HandleInput(SDL_Event e){
    if (!force_move){
        if (e.type == SDL_KEYDOWN){
            switch (e.key.keysym.sym){
                    
                case SDLK_UP:
                    this->vy = -vmax;
                    move_dir = UP;
                    move_type = WALK;
                    vx = 0;
                    break;
                case SDLK_DOWN:
                    this->vy = vmax;
                    move_dir = DOWN;
                    move_type = WALK;
                    vx = 0;

                    break;
                case SDLK_RIGHT:
                    this->vx = vmax;
                    move_dir = RIGHT;
                    move_type = WALK;
                    vy = 0;
                    break;
                case SDLK_LEFT:
                    this->vx = -vmax;
                    move_dir = LEFT;
                    move_type = WALK;
                    vy = 0;
                    break;
                
            }
        }
        if (e.type == SDL_KEYUP){
            switch (e.key.keysym.sym){
                    
                case SDLK_UP:
                    if (this->vy < 0){
                        move_type = IDLE;
                        this->vy = 0;
                    }
                    break;
                case SDLK_DOWN:
                    if (this->vy > 0){
                        move_type = IDLE;
                        this->vy = 0;
                    }
                    break;
                case SDLK_RIGHT:
                    if (this->vx > 0){
                        move_type = IDLE;
                        this->vx = 0;
                    }
                    break;
                case SDLK_LEFT:
                    if (this->vx < 0){
                        move_type = IDLE;
                        this->vx = 0;
                    }
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

void Player::LoadAnimation(string file_path, int row, int col_start, int width, int height, int frames, Animation* a, bool loop, bool flip){
    
    vector<SDL_Rect> animation_clips;
    SDL_Rect clip;
    
    for (int i = col_start; i < frames + col_start;i++) {
        clip = {i*width, row * height, width, height};
        animation_clips.push_back(clip);
    }
    
    a->Init(game, file_path, animation_clips, true, flip);
    a->Play();
}
