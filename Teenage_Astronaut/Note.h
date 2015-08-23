//
//  Note.h
//  Teenage_Astronaut
//
//  Created by Jacob Lashner on 8/17/15.
//  Copyright (c) 2015 Teenage_Astronaut. All rights reserved.
//

#ifndef __Teenage_Astronaut__Note__
#define __Teenage_Astronaut__Note__

#include <iostream>
#include <SDL2/SDL.h>

class Note{
public:
    Note(double t);
    
    double getTimePlayed(){return time_played;}
    void Draw(SDL_Renderer* renderer, int x, int y);
    bool hit = false;
    bool missed = false;
    
private:
    double time_played;
};

#endif /* defined(__Teenage_Astronaut__Note__) */
