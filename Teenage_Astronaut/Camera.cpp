//
//  Camera.cpp
//  Teenage_Astronaut
//
//  Created by Jacob Lashner on 8/21/15.
//  Copyright (c) 2015 Teenage_Astronaut. All rights reserved.
//

#include "Camera.h"
#include "Engine.h"
void Camera::Init(Engine* game){
    view = {0,0,game->getWidth(), game->getHeight()};
    following = NULL;
    tm = NULL;
}

void Camera::SetMap(Tilemap *tilemap){
    tm = tilemap;
}

void Camera::Update(Engine *game){
    if (following){
        SDL_Rect ent_box = following->getHitbox();
        
        view.x = ent_box.x - view.w/2 + ent_box.w/2;
        
        if (view.x < 0){
            view.x = 0;
        }
        else if (view.x + view.w > tm->width){
            view.x = tm->width - view.w;
        }
        
        view.y = ent_box.y - view.h / 2 + ent_box.h/2;
        if (view.y < 0){
            view.y = 0;
        }
//        else if (view.y + view.h > tm->height){
//            view.y = tm->height - view.h;
//        }
    }
}

void Camera::follow(Entity *ent){
    following = ent;
}