//
//  Tile.cpp
//  Teenage_Astronaut
//
//  Created by Jacob Lashner on 8/7/15.
//  Copyright (c) 2015 Teenage_Astronaut. All rights reserved.
//



#include "Tile.h"
#include <SDL2/SDL.h>

Tile::Tile(){}

void Tile::setClip(SDL_Rect c){clip = c;}

void Tile::setLocation(int x, int y, int w, int h){
    location = {x,y,w,h};
}




