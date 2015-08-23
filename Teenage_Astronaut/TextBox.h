//
//  TextBox.h
//  Teenage_Astronaut
//
//  Created by Jacob Lashner on 8/10/15.
//  Copyright (c) 2015 Teenage_Astronaut. All rights reserved.
//

#ifndef __Teenage_Astronaut__TextBox__
#define __Teenage_Astronaut__TextBox__

#include <iostream>
#include "LTexture.h"
#include <SDL2/SDL.h>
#include <vector>

using namespace std;

class TextBox{
public:
    TextBox();
    ~TextBox();
    
    void setRect(SDL_Rect rect){box = rect;}
    
    string loadText(SDL_Renderer* renderer, string text);
    
    bool render(SDL_Renderer* renderer);
    
    void free();
    
private:
    
    SDL_Rect box;
    SDL_Texture* mTexture;
    SDL_Color text_color = {255,255,255,255};
    
    int numLines = 5;
    int maxCharsPerLine = 20;
    
    vector<SDL_Texture*> line_textures;
    vector<SDL_Rect> line_boxes;
    
    TTF_Font* font;
    
};

#endif /* defined(__Teenage_Astronaut__TextBox__) */
