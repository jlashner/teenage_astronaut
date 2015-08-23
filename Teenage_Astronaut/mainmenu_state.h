//
//  mainmenu_state.h
//  Teenage_Astronaut
//
//  Created by Jacob Lashner on 8/5/15.
//  Copyright (c) 2015 Teenage_Astronaut. All rights reserved.
//

#ifndef __Teenage_Astronaut__mainmenu_state__
#define __Teenage_Astronaut__mainmenu_state__

#include <iostream>


#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include <SDL2/SDL.h>
#include "gamestate.h"
#include "LTexture.h"

class MainMenuState : public GameState
{
public:
	void Init(Engine* game);
	void Cleanup();
    
	void Pause();
	void Resume();
    
	void HandleEvents(Engine* game, SDL_Event event);
	void Update(Engine* game);
	void Draw(Engine* game);
    
	static MainMenuState* Instance() {
		return &m_MainMenuState;
	}
    
protected:
	MainMenuState() { }
    
private:
	static MainMenuState m_MainMenuState;
    
    LTexture text1,text2;
	int alpha;
};

#endif

#endif /* defined(__Teenage_Astronaut__mainmenu_state__) */
