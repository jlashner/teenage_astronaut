/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
 and may not be redistributed without written permission.*/

//Using SDL and standard IO

#include "Engine.h"
#include "mainmenu_state.h"

int main ( int argc, char *argv[] )
{
	Engine game;
    
	// initialize the engine
	game.Init( "Engine Test v1.0" );
    
	// load the intro
	game.ChangeState( MainMenuState::Instance());
    
	// main loop
	while ( game.Running() )
	{
		game.HandleEvents();
		game.Update();
		game.Draw();
	}
    
	// cleanup the engine
	game.Cleanup();
    
	return 0;
}
