#ifndef GHOSTS_H
#define GHOSTS_H
#include "Player.hpp"
#include <SFML/Graphics.hpp>
#include "stdafx.h"
#include<string>
using namespace std;
using namespace sf;

//enum symbols { space, player, ghosts, wall };
//enum movement { UP, DOWN, LEFT, RIGHT };

class Ghosts
{
private:

	Sprite ghosts [4];
	Texture Gpic1;
	Texture Gpic2;
	Texture Gpic3;
	Texture Gpic4;
	int G1x, G2x, G3x, G4x;
	int G1y, G2y, G3y, G4y;
	double Gdirection;
	bool ghostdead[4];
	
	

public:
	Ghosts();
	Sprite getSprite(int);
//	void setGx(int x);
//	int getGx();
//	void setGy(int y);
//	int getGy();
	void setGDirection(int d);
	int getGDirection();
//	bool Position(int x, int y);
	void DrawGhost(RenderWindow&);
//	bool WallCollision(Sprite);
	Vector2f getposition(int);
	FloatRect ghostbound(int);
	void moveghost(Vector2f, int );
	void imuneGhosts();
	void changeTexture(float , float );
	void drawghostsinimunity(RenderWindow&,int);
	void setghostdead(int i);


 
};
#endif
