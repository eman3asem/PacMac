//
//  pacman.hpp
//  project
//
//  Created by Nour Mohamed on 4/25/18.
//  Copyright © 2018 Nour Mohamed. All rights reserved.
//

#ifndef pacman_hpp
#define pacman_hpp
#include <SFML/Graphics.hpp>
#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdio.h>
 using namespace sf;
using namespace std;


class Player
{
private:
    Sprite pacman;
    Texture pic;
    int lives;
	long scores;
	Text Scoretxt;
	Font font;
	Texture pacmanstexture;
	IntRect rectpacman;
	Sprite pacmans;

   IntRect rectpacmanup;
   IntRect rectpacmandown;
   IntRect rectpacmanright;
   IntRect rectpacmanleft;
   Clock clockanime;
  

public:
	Player();
    //void setposition(Vector2f);
    Vector2f getposition();
    void DrawPacman(RenderWindow&);
	void increasescore();
    void move(char,int);
    int getlives();
    long getscore();
    //void setscore(long);
    //bool isDead();
    void setlives(int);
	Sprite getSprite();
	bool WallCollision(RectangleShape);
	//bool checkmotion(char);
	void DrawScore(RenderWindow&);
	void setPosition(Vector2f);
	void deadanime();
};
#endif /* pacman_hpp */

