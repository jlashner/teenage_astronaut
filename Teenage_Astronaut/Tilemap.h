//
//  Tilemap.h
//  Teenage_Astronaut
//
//  Created by Jacob Lashner on 8/7/15.
//  Copyright (c) 2015 Teenage_Astronaut. All rights reserved.
//

#ifndef __Teenage_Astronaut__Tilemap__
#define __Teenage_Astronaut__Tilemap__

#include <iostream>
#include "LTexture.h"
#include "Engine.h"
#include "Tile.h"

using namespace std;

class Tilemap{
public:
    void loadTilemap(std::string map_path);
    void loadSpriteSheet(std::string image_path, Engine* game);
    void readData(string data);
    void draw(Engine* game, SDL_Rect camera);
    
    int getMapWidth(){return map_width;}
    int getMapHeight(){return map_height;}
    int getTileWidth(){return tile_width;}
    int getTileHeight(){return tile_height;}
    
    int width, height;
    
private:
    
    int draw_width = 32, draw_height = 32;
    int map_height = 32, map_width = 32;
    int tile_height, tile_width;
    
    int ss_width = 3,ss_height = 3;
    
    LTexture spritesheetTexture;
    
    vector<vector<Tile>> tiles;
    
    SDL_Rect* clips[16][16];
};

#endif /* defined(__Teenage_Astronaut__Tilemap__) */
