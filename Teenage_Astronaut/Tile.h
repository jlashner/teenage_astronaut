//
//  Tile.h
//  Teenage_Astronaut
//
//  Created by Jacob Lashner on 8/7/15.
//  Copyright (c) 2015 Teenage_Astronaut. All rights reserved.
//

#ifndef __Teenage_Astronaut__Tile__
#define __Teenage_Astronaut__Tile__

#include <iostream>
#include <SDL2/SDL.h>


class Tile{
public:
    Tile();
    void setClip(SDL_Rect c);
    void setLocation(int x, int y, int w, int h);
    
    SDL_Rect clip,location;
};


#endif /* defined(__Teenage_Astronaut__Tile__) */
