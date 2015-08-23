//
//  Cutscene.cpp
//  Teenage_Astronaut
//
//  Created by Jacob Lashner on 8/22/15.
//  Copyright (c) 2015 Teenage_Astronaut. All rights reserved.
//

#include "Cutscene.h"
#include "tinyxml2.h"
#include <string>

using namespace std;

Cutscene Cutscene::m_Cutscene;


void Cutscene::Init(Engine *game, LevelState *cur_level, string cutscene_path){
    this->cur_level = cur_level;
    
    db.Init(game);
    doc.LoadFile("assets/dialogue/test.diag");
    NextLine(game);
}

void Cutscene::EndCutscene(){
    cur_level->run_state->EndCutscene();
}

void Cutscene::Pause(){}
void Cutscene::Resume(){}

command ParseCommand(string action){
    if (action=="Move To X")
        return MOVE_TO_X;
    if (action == "Move To Y")
        return MOVE_TO_Y;
    if (action == "Camera Follow")
        return CAMERA_FOLLOW;
    
    return END_CUTSCENE;
}

void Cutscene::NextLine(Engine* game){
    if (!cur_line){

        cur_line = doc.RootElement();
    }
    else{
        if (!cur_line->NextSibling()){
            cur_line = NULL;
            EndCutscene();
        }
        else
            cur_line = cur_line->NextSibling()->ToElement();
    }
    
    if(!cur_line){
        //End of cutscene;
    } else{

        if (strcmp(cur_line->Name(),"line")==0){
            cur_command = DISPLAY_LINE;
            db.SetText(game, cur_line->GetText());
            
            // Dialogue stuff
        }
        if (strcmp(cur_line->Name(), "command")==0){
            cur_command = ParseCommand(cur_line->Attribute("action"));
            switch(cur_command){
                    
                case MOVE_TO_X: {
                    int ent_index = cur_line->IntAttribute("entity_index");
                    int x_val = cur_line->IntAttribute("value");
                    cur_level->entities[ent_index]->moveToXPos(x_val);
                    break;
                }
                    
                case MOVE_TO_Y: {
                    int ent_index = cur_line->IntAttribute("entity_index");
                    int y_val = cur_line->IntAttribute("value");
                    cur_level->entities[ent_index]->moveToYPos(y_val);
                    break;
                }

                case CAMERA_FOLLOW:{
                    int ent_index = cur_line->IntAttribute("entity_index");
                    cur_level->camera.follow(cur_level->entities[ent_index]);
                    break;
                }

                case END_CUTSCENE:{
                    EndCutscene();
                    break;
                }

                case DISPLAY_LINE:{
                    break;
                }

                default:{
                    EndCutscene();
                    break;
                }
            }
        }
    }
}

void Cutscene::HandleEvents(Engine *game, SDL_Event event){
    switch(cur_command){
        case DISPLAY_LINE:
            switch(event.type){
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym) {
                        case SDLK_SPACE:
                            NextLine(game);
                    }
                    break;
            }
            break;
        default:
            break;
    }
    
}

void Cutscene::Update(Engine *game){
    cur_level->Update(game);
}

void Cutscene::Draw(Engine *game){
    cur_level->Draw(game);
    
    if (cur_command == DISPLAY_LINE)
        db.Draw(game);
}