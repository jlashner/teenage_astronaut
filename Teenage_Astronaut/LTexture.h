//
//  LTexture.h
//  Teenage_Astronaut
//
//  Created by Jacob Lashner on 8/6/15.
//  Copyright (c) 2015 Teenage_Astronaut. All rights reserved.
//

#ifndef __Teenage_Astronaut__LTexture__
#define __Teenage_Astronaut__LTexture__

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_ttf/SDL_ttf.h>

class LTexture{
public:
    LTexture();
    ~LTexture();
    
    //Loads image from path
    bool loadFromFile(std::string path, SDL_Renderer* renderer);
    
    //Creates image from font string
    bool loadFromRenderedText(std::string textureText, SDL_Color textColor, SDL_Renderer* renderer);
    
    void loadRectangle(SDL_Rect rect, SDL_Renderer* renderer, SDL_Color color = {0,0,0});
    
    //Deallocates texture
    void free();
    
    //Set color modulation
    void setColor( Uint8 red, Uint8 green, Uint8 blue );
    
    //Set blending
    void setBlendMode( SDL_BlendMode blending );
    
    //Set alpha modulation
    void setAlpha( Uint8 alpha );
    
    void setFontSize(int size);
    
    
    //Renders texture at given point
    void render(int x, int y,  SDL_Renderer* renderer, SDL_Rect* clip = NULL, SDL_Rect* dest = NULL,double angle = 0.0,
                SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE , bool printErrors = false);
    
    
    
    //Gets image dimensions
    int getWidth();
    int getHeight();
    
    
private:
    //The texture
    SDL_Texture* mTexture;
    
    int mWidth;
    int mHeight;
    
    TTF_Font* font;
    std::string font_path;
};

#endif /* defined(__Teenage_Astronaut__LTexture__) */
