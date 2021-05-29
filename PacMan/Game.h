#pragma once
#ifndef GAME_H
#define GAME_H
#include <SFML\Graphics.hpp>
#include <fstream>
#include <iostream>
#include <string>
#include <cctype>
#include "stdafx.h"
#include "Player.hpp"
#include "Ghosts.h"
#include "Menu.h"
#include <vector>
#include <stdlib.h>
using namespace sf;
using namespace std;
class Game
{
private:
	Sprite background[5];
	Texture BG1;
	Texture BG2;
	Texture BG3;
	Texture BG4;
	Texture BG5;
	enum directions { up, down, right, left };
	directions direction;
	RectangleShape Map[20][20];
	char map[20][20];
	Menu menu;
	RectangleShape Tile;
	RectangleShape space;
	Color Space;
	Ghosts ghosts;
	char c;
	long s;
	Font font;
	string con;
	Text score;
	int lives=5;
	Texture pacmanstexture;
	vector<Sprite> Lives;
	ifstream file;
	Player pacman;
	int PacmnI, PacmanJ;
	enum coll_type { small, big, livebonus, scorebonus, fire };
	Texture coin;

	Texture bonuslive;
	Texture bonusscore;
	Texture firep;
	Sprite addlive;

	Clock clock,clock1,clockimune;
	bool imune = false;
	State state;
	int Levelcnt = 1;
	Text Press;
	struct collectable 
	{
		Sprite sp;
		coll_type type;
		int x, y;
	};
	collectable tmp;
	vector <collectable> collectables;
	SoundBuffer coinbuffer;
	Sound CoinSound;

	SoundBuffer Losebuffer;
	Sound PacmanLose;

	Texture soundon;
	Texture mute;
	Sprite SoundOnSmall;
	Sprite SoundOffSmall;
	
public:
	Game();
	void GameLoop(RenderWindow&);
	void SetLevel(int,RenderWindow&);
	RectangleShape getTile();
	RectangleShape getSpace();
	bool Collision(Vector2f pos);
	void isdead(Player&, Ghosts, RenderWindow&, State&);
	void GetLevelcnt(int&);
	Sprite getBGSprite(int);


};
#endif

