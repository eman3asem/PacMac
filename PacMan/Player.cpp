//  pacman.cpp
//  Created by Nour Mohamed on 4/25/18.
//  Copyright © 2018 Nour Mohamed. All rights reserved.
#include "stdafx.h"
#include "Player.hpp"

Player::Player()
{
	//Pacman settings 
	/*if (!pic.loadFromFile("pac.png"))
	{
		cout << "error";
	}
	pacman.setTexture(pic);
	pacman.setScale(Vector2f(0.01f, 0.01f));
	pacman.setPosition(Vector2f(180, 180));
	*/

	pacmanstexture.loadFromFile("sheet.png");
	if (!pacmanstexture.loadFromFile("sheet.png"))
	{
		cout << "error";
	}

	// Score Settings
	font.loadFromFile("comic.ttf");
	if (!font.loadFromFile("comic.ttf"))
	{
		cout << "error" << endl;
	}
	Scoretxt.setFont(font);
	Scoretxt.setColor(Color::Red);
	Scoretxt.setCharacterSize(35);
	Scoretxt.setStyle(Text::Bold | Text::Italic);
	Scoretxt.setPosition(Vector2f(200, 0));
	Scoretxt.setString("Score");

	// Define a rectangle, located at (0, 0) with a size of 20x5
	pacman.setTexture(pacmanstexture);
	pacman.setTextureRect(IntRect(0, 20, 20, 20));
	pacman.setScale(Vector2f(1.5, 1.5));
	pacman.setPosition(Vector2f(180, 180));

	

}

void Player::DrawPacman(RenderWindow& window)
{
	window.draw(pacman);
}

/*
 void Pacman:: setscore(long score1)
{
	scores=score1;
}
 */

void Player::setlives(int live)
{
	lives = live;
}

void Player::increasescore()
{
	scores += 100;
}

int Player::getlives()
{
	return lives;
}

long Player::getscore()
{
	return scores;
}

Vector2f Player::getposition()
{
	return(pacman.getPosition());
}

/*
 void Pacman:: setposition(<#Vector2f#>)
 {
 pacman.setPosition();
 }
 */

/*void Player::move(char direction, int units)
{
	if (direction == 'U')
		pacman.move(0, -units);
	if (direction == 'D')
		pacman.move(0, units);
	if (direction == 'R')
		pacman.move(units, 0);
	if (direction == 'L')
		pacman.move(-units, 0);

}*/

void Player::move(char direction, int units)
{
	if (direction == 'U')
	{
		IntRect rectpacman(40, 40, 20, 20);
		//pacman.setTexture(pacmanstexture);
		pacman.setTextureRect(rectpacman);
		pacman.setScale(Vector2f(1.5, 1.5));
		if (clockanime.getElapsedTime().asSeconds() > 0.6f)
		{
			if (rectpacman.left == 40)
				rectpacman.left = 0;
			else
				rectpacman.left += 20;

			pacman.setTextureRect(rectpacman);

			clockanime.restart();
		}
		pacman.move(0, -units);

	}
	if (direction == 'D')
	{
		//animation
		IntRect rectpacman(40, 60, 20, 20);
		//pacman.setTexture(pacmanstexture);
		pacman.setTextureRect(rectpacman);
		pacman.setScale(Vector2f(1.5, 1.5));
		if (clockanime.getElapsedTime().asSeconds() > 0.6f)
		{
			if (rectpacman.left == 40)
				rectpacman.left = 0;
			else
				rectpacman.left += 20;

			pacman.setTextureRect(rectpacman);

			clockanime.restart();
		}

		pacman.move(0, units);
	}

	if (direction == 'R')
	{
		IntRect rectpacman(40, 20, 20, 20);
		//pacman.setTexture(pacmanstexture);
		pacman.setTextureRect(rectpacman);
		pacman.setScale(Vector2f(1.5, 1.5));
		if (clockanime.getElapsedTime().asSeconds() > 0.6f)
		{
			if (rectpacman.left == 40)
				rectpacman.left = 0;
			else
				rectpacman.left += 20;

			pacman.setTextureRect(rectpacman);

			clockanime.restart();
		}
		pacman.move(units, 0);
	}
	if (direction == 'L')
	{
		IntRect rectpacman(40, 0, 20, 20);
		//pacman.setTexture(pacmanstexture);
		pacman.setTextureRect(rectpacman);
		pacman.setScale(Vector2f(1.5, 1.5));
		if (clockanime.getElapsedTime().asSeconds() > 0.6f)
		{
			if (rectpacman.left == 40)
				rectpacman.left = 0;
			else
				rectpacman.left += 20;

			pacman.setTextureRect(rectpacman);

			clockanime.restart();
		}
		pacman.move(-units, 0);
	}

}

Sprite Player::getSprite() {
	return pacman;
}

bool Player::WallCollision(RectangleShape check)
{
	if (pacman.getLocalBounds().intersects(check.getLocalBounds()))
		return true;
	else
		return false;
}


void Player::DrawScore(RenderWindow& window)
{
	window.draw(Scoretxt);
}

void Player::setPosition(Vector2f pos)

{

	pacman.setPosition(pos);

}

void Player::deadanime()
{
	//    pacmanstexturedead.loadFromFile("Pacmandead.png");
	//    if (!pacmanstexturedead.loadFromFile("Pacmandead.png"))
	//    {
	//        cout << "error";
	//    }
	//    IntRect rectpacmandead(192, 128,32, 32);
	//    pacman.setTexture(pacmanstexturedead);
	//    pacman.setTextureRect(rectpacmandead);
	//    pacman.setScale(Vector2f(1, 1));
	//    if (clockanimedead.getElapsedTime().asSeconds() > 0.6f)
	//    {
	//        if (rectpacman.left == 256)
	//            rectpacman.left = 192;
	//        else
	//            rectpacman.left += 32;
	//
	//        pacman.setTextureRect(rectpacmandead);
	//
	//        clockanimedead.restart();
	//    }

}