//
//  Note.cpp
//  Teenage_Astronaut
//
//  Created by Jacob Lashner on 8/17/15.
//  Copyright (c) 2015 Teenage_Astronaut. All rights reserved.
//

#include "Note.h"
#include <SDL2/SDL.h>


Note::Note(double t){
    time_played = t;
}


void Note::Draw(SDL_Renderer* renderer, int x, int y){
    if (hit)
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    else
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_Rect note_rect = {x - 10,y - 10,20,20};
    SDL_RenderDrawRect(renderer, &note_rect);
}