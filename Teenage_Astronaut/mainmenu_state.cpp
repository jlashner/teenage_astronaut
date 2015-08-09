//^{
//    {
//}
#include <stdio.h>

#include <SDL2/SDL.h>
#include <SDL2_ttf/SDL_ttf.h>
#include "Engine.h"
#include "GameState.h"
#include "mainmenu_state.h"
#include "LTexture.h"
#include "level_1_state.h"


MainMenuState MainMenuState::m_MainMenuState;



void MainMenuState::Init(Engine* game){

    text1 = LTexture();
    text1.setFontSize(40);
    
    text2 = LTexture();
    text2.setFontSize(20);
    text1.loadFromRenderedText("Teenage Astronaut", {255,255,255}, game->renderer);
    text2.loadFromRenderedText("SPACE TO START", {255,255,255}, game->renderer);
}

void MainMenuState::Cleanup(){}

void MainMenuState::Pause(){}
void MainMenuState::Resume(){}

void MainMenuState::HandleEvents(Engine* game, SDL_Event event)
{
	   
    switch (event.type) {
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
                case SDLK_SPACE:
                    game->ChangeState( Level1State::Instance() );
                    break;
                    
                case SDLK_ESCAPE:
                    game->Quit();
                    break;
            }
            break;
    }
	
}

void MainMenuState::Update(Engine* game){}

void MainMenuState::Draw(Engine*game){
    
    SDL_SetRenderDrawColor( game->renderer, 0, 0, 0, 0xFF );
    SDL_RenderClear(game->renderer); // Fill render with color
    SDL_SetRenderDrawColor( game->renderer, 255, 255, 255, 0xFF );

    text1.render(game->getWidth()/2 - text1.getWidth()/2, 0, game->renderer);
    text2.render(game->getWidth()/2 - text2.getWidth()/2, 100 , game->renderer);
    
    SDL_RenderPresent(game->renderer); // Show render on window

}