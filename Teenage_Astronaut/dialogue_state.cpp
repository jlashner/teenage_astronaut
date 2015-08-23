//
//  dialogue_state.cpp
//  Teenage_Astronaut
//
//  Created by Jacob Lashner on 8/9/15.
//  Copyright (c) 2015 Teenage_Astronaut. All rights reserved.
//

#include "dialogue_state.h"
#include "Engine.h"
#include "LTexture.h"
#include "TextBox.h"
#include "tinyxml2.h"

using namespace tinyxml2;

DialogueState DialogueState::m_DialogueState;

void DialogueState::Init(Engine* game){

    dialogue_box.w = game->getWidth() * .8;
    dialogue_box.x = game->getWidth()/2 - dialogue_box.w / 2;
    dialogue_box.h = game->getHeight() * .4;
    dialogue_box.y = game->getHeight() * .97 - dialogue_box.h;
        
    
    SDL_Rect text_rect = SDL_Rect();
    text_rect.x = dialogue_box.x + .3 * dialogue_box.w;
    text_rect.w = dialogue_box.w - (text_rect.x - dialogue_box.x);
    text_rect.y = dialogue_box.y;
    text_rect.h = dialogue_box.h;
    

    doc.LoadFile("assets/dialogues/test.diag");
    cur_line = doc.FirstChild()->ToElement();

    name_tex.setFontSize(20);
    
    text_box = TextBox();
    text_box.setRect(text_rect);
    
    nextLine(game->renderer);
    
//    text_box.loadText(game->renderer, "Hello my name is Jack and I was born on September 23rd 1993. My home planet is Eldoon 5, and I am but a humble boon merchant. Would you like to view my stock? I think you'd really like this one.");
}

void DialogueState::nextLine(SDL_Renderer* renderer){
    if( cur_line){
        name_tex.loadFromRenderedText(cur_line->Name(), {0,0,0,0}, renderer);
        text_box.loadText(renderer, cur_line->GetText());
        }
    
}

void DialogueState::Cleanup(){
//    bg.free();
}
void DialogueState::Pause(){}
void DialogueState::Resume(){}

void DialogueState::HandleEvents(Engine *game, SDL_Event event){
    switch (event.type) {
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
                case SDLK_SPACE:
                    if (cur_line->NextSibling()){
                        cur_line = cur_line->NextSibling()->ToElement();
                        nextLine(game->renderer);
                    }
                    else
                        game->PopState();
                    break;
            }
            break;
    }

    
}

void DialogueState::Update(Engine* game){}

void DialogueState::Draw(Engine* game){
    
//    SDL_SetRenderDrawBlendMode(game->renderer, SDL_BLENDMODE_BLEND);
//    SDL_SetRenderDrawColor(game->renderer, 0, 0, 0, 1);
//    SDL_Rect rect = {0,0,game->getWidth(),game->getHeight()};
//    SDL_RenderFillRect(game->renderer, &rect);
    
    SDL_SetRenderDrawColor(game->renderer, 255, 255, 255, 0);
    SDL_RenderFillRect(game->renderer, &dialogue_box);

    
    name_tex.render(dialogue_box.x, dialogue_box.y, game->renderer);
    text_box.render(game->renderer);

    SDL_RenderPresent(game->renderer);
    
}

