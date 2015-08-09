
#ifndef INTROSTATE_H
#define INTROSTATE_H

#include <SDL2/SDL.h>
#include "gamestate.h"

class CIntroState : public GameState
{
public:
	void Init(Engine* game);
	void Cleanup();
    
	void Pause();
	void Resume();
    
	void HandleEvents(Engine* game);
	void Update(Engine* game);
	void Draw(Engine* game);
    
	static CIntroState* Instance() {
		return &m_IntroState;
	}
    
protected:
	CIntroState() { }
    
private:
	static CIntroState m_IntroState;
    
	SDL_Surface* bg;
	SDL_Surface* fader;
	int alpha;
};

#endif