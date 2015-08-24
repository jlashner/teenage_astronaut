//
//  Cutscene.h
//  Teenage_Astronaut
//
//  Created by Jacob Lashner on 8/22/15.
//  Copyright (c) 2015 Teenage_Astronaut. All rights reserved.
//

#ifndef __Teenage_Astronaut__Cutscene__
#define __Teenage_Astronaut__Cutscene__

#include <iostream>
#include "Engine.h"
#include "GameState.h"
#include "LTexture.h"
#include "TextBox.h"
#include "tinyxml2.h"
class LevelState;
#include "LevelState.h"
#include "DialogueBox.h"

using namespace tinyxml2;
using namespace std;

enum command{
    MOVE_TO_X,
    MOVE_TO_Y,
    CAMERA_FOLLOW,
    DISPLAY_LINE,
    END_CUTSCENE
};

class Cutscene
{
public:
	void Init(Engine* game, LevelState* cur_level, string cutscene_path);
    
	void Pause();
	void Resume();
    
    void NextLine(Engine* game);
    
	void HandleEvents(Engine* game, SDL_Event event);
	void Update(Engine* game);
	void Draw(Engine* game);
    
    void EndCutscene();
    
	static Cutscene* Instance() {
		return &m_Cutscene;
	}
    
protected:
	Cutscene() { }
    
private:
	static Cutscene m_Cutscene;
    
    LevelState* cur_level;
    
    command cur_command;
    Entity* moving_entity;
    
    DialogueBox db;
    
    XMLDocument doc;
    XMLElement * cur_line = NULL;
    
    bool cont = false;
    
};


#endif /* defined(__Teenage_Astronaut__Cutscene__) */
