//
//  TextBox.cpp
//  Teenage_Astronaut
//
//  Created by Jacob Lashner on 8/10/15.
//  Copyright (c) 2015 Teenage_Astronaut. All rights reserved.
//

#include "TextBox.h"
#include <sstream>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2_ttf/SDL_ttf.h>

using namespace std;

TextBox::TextBox(){
    
    mTexture = NULL;
    box = {0,0,0,0};
    
    line_textures.resize(numLines);
    line_boxes.resize(numLines);
    
    string font_path = "assets/fonts/SourceSansPro-Bold.otf";
    font = TTF_OpenFont(font_path.c_str(), 32);
}

TextBox::~TextBox(){
    free();
}

void TextBox::free(){
    if (mTexture != NULL){
        SDL_DestroyTexture(mTexture);
        mTexture = NULL;
    }
}

string TextBox::loadText(SDL_Renderer* renderer, string text){
    vector<string> lines (numLines, "");

    istringstream text_stream(text);
    
    string word, remaining_text = "";
    int textHeight, textWidth;
    int lineHeight = box.h / numLines;

    
    int cur_line = 0, cur_pos = 0;
    while(getline(text_stream, word, ' ')){
        
        TTF_SizeText(font, (lines[cur_line] + " " + word).c_str() , &textWidth, &textHeight);
        
        if(textWidth * lineHeight / textHeight > box.w){
            cur_line++;
        }
        if (cur_line == numLines){
            remaining_text = text.substr(cur_pos);
            break;
        }
        lines[cur_line].append(word);
        lines[cur_line].append(" ");
        cur_pos += word.length() + 1;
    }
    
    
    SDL_Surface* line_surface = NULL;
    
//    SDL_SetRenderTarget(renderer, mTexture);
    
    for (int i = 0; i < numLines; i++){
        TTF_SizeText(font, lines[i].c_str(), &textWidth, &textHeight);
        line_boxes[i] = {box.x, box.y + lineHeight * i, textWidth * lineHeight/textHeight, lineHeight};
        
        line_surface = TTF_RenderText_Solid( font, lines[i].c_str(), text_color );
        line_textures[i] = SDL_CreateTextureFromSurface( renderer, line_surface );
        
    }
    
    if (line_surface != NULL)
        SDL_FreeSurface(line_surface);
    
    return remaining_text;
}

bool TextBox::render(SDL_Renderer* renderer){
    for (int i = 0; i < numLines; i++){
        SDL_RenderCopy(renderer, line_textures[i], NULL, &line_boxes[i]);
    }
    
    return true;
}