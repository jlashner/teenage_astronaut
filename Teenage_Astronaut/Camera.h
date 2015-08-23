//
//  Camera.h
//  Teenage_Astronaut
//
//  Created by Jacob Lashner on 8/21/15.
//  Copyright (c) 2015 Teenage_Astronaut. All rights reserved.
//

#ifndef __Teenage_Astronaut__Camera__
#define __Teenage_Astronaut__Camera__

#include <iostream>
#include <SDL2/SDL.h>
#include "Engine.h"
#include "Tilemap.h"
class Entity;
#include "Entity.h"

class Camera{
    
public:
    void Init(Engine* game);
    void SetMap(Tilemap* tilemap);
    void Update(Engine* game);
    void follow(Entity* ent);
    
    SDL_Rect getView(){return view;}
    
private:
    SDL_Rect view;
    Tilemap* tm;
    Entity* following;
    
};

#endif /* defined(__Teenage_Astronaut__Camera__) */
