#include "stdafx.h"
#include "Ghosts.h"

Ghosts::Ghosts()
{
	
	Gpic1.loadFromFile("textures/ghost1.png");
	if (!Gpic1.loadFromFile("textures/ghost1.png"))
	{
		cout << "error";
	}
	ghosts[0].setTexture(Gpic1);
	ghosts[0].setTextureRect(IntRect(0, 0, 20, 20));
	ghosts[0].setScale(Vector2f(1.5f, 1.5f));
	ghosts[0].setPosition(Vector2f(420, 390));

	Gpic2.loadFromFile("textures/ghost2.png");
	if (!Gpic2.loadFromFile("textures/ghost2.png"))
	{
		cout << "error";
	}
	ghosts[1].setTexture(Gpic2);
	ghosts[1].setTextureRect(IntRect(0, 0, 20, 20));
	ghosts[1].setScale(Vector2f(1.5f, 1.5f));
	ghosts[1].setPosition(Vector2f(420, 420));

	Gpic3.loadFromFile("textures/ghost3.png");
	if (!Gpic3.loadFromFile("textures/ghost3.png"))
	{
		cout << "error";
	}
	ghosts[2].setTexture(Gpic3);
	ghosts[2].setTextureRect(IntRect(0, 0, 20, 20));
	ghosts[2].setScale(Vector2f(1.5f, 1.5f));
	ghosts[2].setPosition(Vector2f(420, 450));

	Gpic4.loadFromFile("textures/ghost.png");
	if (!Gpic4.loadFromFile("textures/ghost4.png"))
	{
		cout << "error";
	}
	ghosts[3].setTexture(Gpic4);
	ghosts[3].setTextureRect(IntRect(0, 0, 20, 20));
	ghosts[3].setScale(Vector2f(1.5f, 1.5f));
	ghosts[3].setPosition(Vector2f(420, 480));

	for (int i = 0; i < 4; i++)
	{
		ghostdead[i] = false;
	}

}

Sprite Ghosts::getSprite(int c) {

	switch (c)
	{
	case 1:
		return ghosts[1];
		break;
	case 2:
		return ghosts[2];
		break;
	case 3:
		return ghosts[3];
		break;
	case 4:
		return ghosts[4];
		break;
	}

}



void Ghosts::setGDirection(int d) {
	Gdirection = d;
}

int Ghosts::getGDirection() {
	return Gdirection;
}

void Ghosts::DrawGhost(RenderWindow& window)
{
	for (int g = 0; g < 4; g++)
		if (ghostdead[g] == false)
		window.draw(ghosts[g]);

}

Vector2f Ghosts::getposition(int ghostNum)
{
	return(ghosts[ghostNum].getPosition());
}



void Ghosts::moveghost(Vector2f XY, int ghostNum)
{
	
	ghosts[ghostNum].move(XY);
}


FloatRect Ghosts::ghostbound(int ghostnum)
{
	return ghosts[ghostnum].getGlobalBounds();
}

void Ghosts::imuneGhosts()
{
	for (int i = 0; i < 4; i++)
	{
		ghosts[i].setTextureRect(IntRect(0, 80, 20, 20));
	}
}

void Ghosts::changeTexture(float a, float b)
{
	for (int i = 0; i < 4; i++)
	{
		ghosts[i].setTextureRect(IntRect(a, b, 20, 20));
	}
}

void Ghosts:: drawghostsinimunity(RenderWindow& window ,int g)
{
	for (int i = 0; i < 4; i++)
	{
		if (i != g )
			window.draw(ghosts[i]);

	}
}

void Ghosts::setghostdead(int i)
{
	for (int j = 0; j < 4; j++)
	{
		if (j == i)
		{
			ghostdead[j] = true;
		}
		else
			ghostdead[j] = false;

	}

}