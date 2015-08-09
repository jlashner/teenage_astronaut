
//  level_1_state.cpp
//  Teenage_Astronaut
//
//  Created by Jacob Lashner on 8/6/15.
//  Copyright (c) 2015 Teenage_Astronaut. All rights reserved.
//

#include "level_1_state.h"
using namespace std;

Level1State Level1State::m_Level1State;

void Level1State::Init(Engine* game){

    tm.loadSpriteSheet("/Users/jacoblashner/Teenage_Astronaut/assets/tilesheet.png", game);
    tm.loadTilemap("/Users/jacoblashner/Teenage_Astronaut/assets/tm.tmx");
    
    level_width = tm.width;
    level_height = tm.height;
    
    camera = {0,0,game->getWidth(), game->getHeight()};
    
    
    player.Init(game, &tm);
    
}

void Level1State::Cleanup(){}

void Level1State::Pause(){}
void Level1State::Resume(){}

void Level1State::HandleEvents(Engine *game, SDL_Event event){
    player.handleInput(event);
}

void Level1State::Update(Engine *game){
    player.update(game);
    
    camera.x = player.getX() - camera.w/2 + player.width/2;
    if(camera.x < 0)
        camera.x = 0;
    else if(camera.x + camera.w > level_width)
        camera.x = level_width - camera.w;
    
    camera.y = player.getY() - camera.h/2 + player.height/2;
    if(camera.y < 0)
        camera.y = 0;
//    else if(camera.y + camera.h > level_height)
//        camera.y = level_height - camera.h;

}

void Level1State::Draw(Engine *game){

    SDL_SetRenderDrawColor(game->renderer, 0, 0, 0, 0);
    SDL_RenderClear(game->renderer);
    
    tm.draw(game, camera);
    player.draw(game, camera);
    
    SDL_RenderPresent(game->renderer); 
}



