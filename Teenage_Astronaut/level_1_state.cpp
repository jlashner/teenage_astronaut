
//  level_1_state.cpp
//  Teenage_Astronaut
//
//  Created by Jacob Lashner on 8/6/15.
//  Copyright (c) 2015 Teenage_Astronaut. All rights reserved.
//

#include "level_1_state.h"
#include "RunState.h"
#include "Cutscene.h"
using namespace std;

Level1State Level1State::m_Level1State;

void Level1State::Init(Engine* game, RunState* run_state){
    this->run_state = run_state;
    
    string tilesheet_path = "assets/Tilesprites/tilesheet.png";
    string tilemap_path = "assets/Tilemaps/level_1.tmx";
    

    tm.loadSpriteSheet(tilesheet_path, game);
    tm.loadTilemap(tilemap_path);
    
    level_width = tm.width;
    level_height = tm.height;
    
    player.Init(game, &tm, 0, 0);
    
    entities.push_back(&player);
    
    camera.Init(game);
    camera.SetMap(&tm);
    camera.follow(&player);
}

void Level1State::Cleanup(){}

void Level1State::Pause(){
    player.Pause();
}
void Level1State::Resume(){}

void Level1State::HandleEvents(Engine *game, SDL_Event event){
    switch (event.type) {
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
                case SDLK_SPACE:
                    player.Pause();
                    
                    Cutscene* cs = Cutscene::Instance();
                    cs->Init(game, this, "assets/dialogue/test3.diag");
                    run_state->PlayCutscene(cs);
                    break;
                    
            }
            break;
    }

    player.HandleInput(event);
}

void Level1State::Update(Engine *game){
    player.Update(game);
    camera.Update(game);
}

void Level1State::Draw(Engine *game){

    SDL_SetRenderDrawColor(game->renderer, 0, 0, 0, 0);
    SDL_RenderClear(game->renderer);
    
    tm.draw(game, camera.getView());
    player.Draw(game, &camera);
}



