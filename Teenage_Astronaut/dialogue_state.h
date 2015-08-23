//
//  dialogue_state.h
//  Teenage_Astronaut
//
//  Created by Jacob Lashner on 8/9/15.
//  Copyright (c) 2015 Teenage_Astronaut. All rights reserved.
//

#ifndef __Teenage_Astronaut__dialogue_state__
#define __Teenage_Astronaut__dialogue_state__

#include <iostream>
#include "Engine.h"
#include "GameState.h"
#include "LTexture.h"
#include "TextBox.h"
#include "tinyxml2.h"

using namespace tinyxml2;

class DialogueState : public GameState
{
public:
	void Init(Engine* game);
	void Cleanup();
    
	void Pause();
	void Resume();
    
    void nextLine(SDL_Renderer* renderer);
    
	void HandleEvents(Engine* game, SDL_Event event);
	void Update(Engine* game);
	void Draw(Engine* game);
    
	static DialogueState* Instance() {
		return &m_DialogueState;
	}
    
protected:
	DialogueState() { }
    
private:
	static DialogueState m_DialogueState;
    
    SDL_Rect dialogue_box, name_box, prof_box;
    TextBox text_box;
    string remaining_text;
    
    LTexture name_tex, prof_text;
    
    tinyxml2::XMLDocument doc;
    XMLElement * cur_line;
    
};


#endif /* defined(__Teenage_Astronaut__dialogue_state__) */
