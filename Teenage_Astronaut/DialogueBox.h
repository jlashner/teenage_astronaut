//
//  DialogueBox.h
//  Teenage_Astronaut
//
//  Created by Jacob Lashner on 8/22/15.
//  Copyright (c) 2015 Teenage_Astronaut. All rights reserved.
//

#ifndef __Teenage_Astronaut__DialogueBox__
#define __Teenage_Astronaut__DialogueBox__
#include <iostream>
#include "LTexture.h"
#include "TextBox.h"
#include "Engine.h"

using namespace std;

class DialogueBox{
public:
    void Init(Engine* game);
    
    void SetText(Engine* game, string text);
    void SetSpeaker(string speaker);
    void SetPhoto(string file_path);
    
    void SetDisplay(bool d){display = d;}
    void Draw(Engine* game);
    
private:
    
    LTexture bg, speaker_tex, photo_tex;
    TextBox text_box;
    bool display;
    
    SDL_Rect dialogue_rect;
};

#endif /* defined(__Teenage_Astronaut__DialogueBox__) */
