#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <SDL2/SDL.h>

#include <vector>
using namespace std;

#include <SDL2_TTF/SDL_ttf.h>
#include "Timer.h"



class GameState;

class Engine
{
public:
    
	void Init(const char* title, int width=640, int height=480,
		      int bpp=0, bool fullscreen=false);
	void Cleanup();
    
	void ChangeState(GameState* state);
	void PushState(GameState* state);
	void PopState();
    
	void HandleEvents();
	void Update();
	void Draw();
    
    int getWidth() {return width;}
    int getHeight() {return height;}
    double getDelta() {return delta;}
    
	bool Running() { return m_running; }
	void Quit() { m_running = false; }
    
	SDL_Window* window;
    SDL_Renderer* renderer;
    TTF_Font* font;
    
private:
	// the stack of states
	vector<GameState*> states;
    
    int width, height;
    double delta;
    
    Timer timer;
    
	bool m_running;
	bool m_fullscreen;
};

#endif
