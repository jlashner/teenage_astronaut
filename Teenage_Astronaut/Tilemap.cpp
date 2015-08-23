//
//  Tilemap.cpp
//  Teenage_Astronaut
//
//  Created by Jacob Lashner on 8/7/15.
//  Copyright (c) 2015 Teenage_Astronaut. All rights reserved.
//

int TILE_SIZE = 16;

#include <SDL2/SDL.h>
#include "Tilemap.h"
#include "Tile.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include "tinyxml2.h"

using namespace std;




char data[100];
Tile* tiles[16][16];



void Tilemap::loadSpriteSheet(std::string image_path, Engine* game){
    spritesheetTexture.loadFromFile(image_path, game->renderer);
}

void Tilemap::loadTilemap(string map_path){
    
    tinyxml2::XMLDocument doc;
    
    doc.LoadFile(map_path.c_str());
    
    tinyxml2::XMLElement* map = doc.RootElement();
    map_width = map->IntAttribute("width");
    map_height = map->IntAttribute("height");
    tile_width = map->IntAttribute("tilewidth");
    tile_height = map->IntAttribute("tileheight");
    
    width = map_width * draw_width;
    height = map_height* draw_height;
    
    tiles.resize(map_height);
    for (int i = 0; i < tiles.size(); i ++){
        tiles[i].resize(map_width);
    }

    tinyxml2::XMLElement* data_elem = map->FirstChildElement("layer")->FirstChildElement("data");
    string data = data_elem->GetText();
    
    readData(data);
        
}

void Tilemap::readData(string data){
    
    string line, item;
    istringstream data_stream(data);
    
    int num, sprite_row, sprite_col, row = 0, col = 0;
    while(getline(data_stream, line)){
        if (line == "")
            continue;
        col = 0;
        istringstream line_stream(line);
        while(getline(line_stream, item, ',')){
            num = std::stoi(item);
            sprite_row = (int)(num / 100);
            sprite_col = num % 100 -1;
            
            SDL_Rect clip = {tile_width*sprite_col,tile_height*sprite_row, tile_width, tile_height};
            tiles[row][col] = Tile();
            tiles[row][col].setLocation(draw_width * col, draw_height*row, draw_width, draw_height);
            tiles[row][col].setClip(clip);
            col++;
        }
        row++;
    }
}

void Tilemap::draw(Engine* game, SDL_Rect camera){
    int i = 0, j = 0;
    SDL_Rect relative_pos;
    for(i=0;i < map_height;i++){
        for (j=0;j<map_width;j++){
            if(SDL_HasIntersection(&camera, &tiles[i][j].location)){
                relative_pos = {tiles[i][j].location.x - camera.x,
                                tiles[i][j].location.y - camera.y,
                                tiles[i][j].location.w,
                                tiles[i][j].location.h};
                spritesheetTexture.render(0, 0, game->renderer, &tiles[i][j].clip, &relative_pos);
            }
            
        }
    }
    
    
}
