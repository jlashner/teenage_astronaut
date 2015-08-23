//
//  DialogueBox.cpp
//  Teenage_Astronaut
//
//  Created by Jacob Lashner on 8/22/15.
//  Copyright (c) 2015 Teenage_Astronaut. All rights reserved.
//

#include "DialogueBox.h"
#include "Engine.h"

using namespace std;

void DialogueBox::Init(Engine* game){
    bg = LTexture();
    printf("%d", bg.loadFromFile("assets/images/dialogue_bg4.png", game->renderer));
    
    dialogue_rect.w = game->getWidth() * .8;
    dialogue_rect.x = game->getWidth()/2 - dialogue_rect.w / 2;
    dialogue_rect.h = game->getHeight() * .4;
    dialogue_rect.y = game->getHeight() * .97 - dialogue_rect.h;
    
    int text_margin = 20;
    SDL_Rect text_rect;
    text_rect.w = dialogue_rect.w * .6;
    text_rect.x = dialogue_rect.x + (dialogue_rect.w - text_rect.w - text_margin);
    text_rect.h = dialogue_rect.h - 2* text_margin;
    text_rect.y = dialogue_rect.y +text_margin;
 
    text_box.setRect(text_rect);
}

void DialogueBox::SetText(Engine* game, string text){
    text_box.loadText(game->renderer, text);
}

void DialogueBox::SetSpeaker(string speaker){}
void DialogueBox::SetPhoto(string file_path){}

void DialogueBox::Draw(Engine* game){
    bg.render(0,0,game->renderer, NULL, &dialogue_rect);
    text_box.render(game->renderer);
}

