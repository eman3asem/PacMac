#include "stdafx.h"
#include "Game.h"


Game::Game()
{
	state = MENU;
	// Settings For BackGround Pictures
	{

		if (!BG1.loadFromFile("forest2.png"))
		{
			cout << "error";
		}
		background[0].setTexture(BG1);
		background[0].setScale(Vector2f(1.5f, 2.5f));
		background[0].setPosition(Vector2f(0, 0));


		if (!BG2.loadFromFile("fireBG.png"))
		{
			cout << "error";
		}
		background[1].setTexture(BG2);
		background[1].setScale(Vector2f(0.7f, 1.0f));
		background[1].setPosition(Vector2f(0, 0));


		if (!BG3.loadFromFile("aqua.png"))
		{
			cout << "error";
		}
		background[2].setTexture(BG3);
		background[2].setScale(Vector2f(2.5f, 3.50f));
		background[2].setPosition(Vector2f(0, 0));


		if (!BG4.loadFromFile("snow.png"))
		{
			cout << "error";
		}
		background[3].setTexture(BG4);
		background[3].setScale(Vector2f(0.5f, 0.5f));
		background[3].setPosition(Vector2f(0, 0));


		if (!BG5.loadFromFile("desert.png"))
		{
			cout << "error";
		}
		background[4].setTexture(BG5);
		background[4].setScale(Vector2f(1.5f, 1.5f));
		background[4].setPosition(Vector2f(0, 0));
	}

	// Map Settings
	{
		srand(time(NULL));
		Tile.setSize(Vector2f(30, 30));
		Tile.setFillColor(Color(21, 0, 146));
		Tile.setOutlineColor(Color::Blue);
		Tile.setOutlineThickness(-4);
		space.setSize(Vector2f(30, 30));
		space.setFillColor(Color(135, 206, 250));
		Space = Color(135, 206, 250);
	}

	// Score Settings
	{
		Lives.resize(3);
		font.loadFromFile("comic.ttf");
		if (!font.loadFromFile("comic.ttf"))
		{
			cout << "error" << endl;
		}

		score.setFont(font);
		score.setColor(Color::Yellow);
		score.setCharacterSize(35);
		score.setStyle(Text::Bold | Text::Italic);
		score.setPosition(Vector2f(320, 0));

	}

	// Sound On & Off Small Icons
	{
		if (!mute.loadFromFile("SoundOff.png"))
		{
			cout << "error";
		}
		if (!soundon.loadFromFile("SoundOn.png"))
		{
			cout << "error";
		}
		SoundOffSmall.setScale(0.22, 0.22);
		SoundOffSmall.setPosition(900, 50);
		SoundOffSmall.setTexture(mute);

		SoundOnSmall.setScale(0.25, 0.25);
		SoundOnSmall.setPosition(800, 50);
		SoundOnSmall.setTexture(soundon);
	}

	// Lives Settings 
	{
		if (!pacmanstexture.loadFromFile("pac.png"))
		{
			cout << "error";
		}
		for (int i = 0; i < Lives.size(); i++)
		{
			Lives[i].setTexture(pacmanstexture);
			Lives[i].setScale(Vector2f(0.01f, 0.01f));
			Lives[i].setPosition(Vector2f((200 + (i * 30)), 60));
		}
		addlive.setTexture(pacmanstexture);
		addlive.setScale(Vector2f(0.01f, 0.01f));

	}

	// Collectables (Coins)
	{
		if (!coin.loadFromFile("myCoin.png"))
			cout << "Error" << endl;

		if (!bonuslive.loadFromFile("bonus.png"))
			cout << "Error" << endl;
		 
		if (!firep.loadFromFile("fire.png"))
			cout << "Error" << endl;

		PacmnI = 1, PacmanJ = 1;
	}

	// Coin Sound Settings
	{
		if (!coinbuffer.loadFromFile("CoinSound.ogg"))
			cout << " COIN SOUND ERROR" << endl;
		CoinSound.setBuffer(coinbuffer);
	}

	// LOSE Sound Settings
	{
		if (!Losebuffer.loadFromFile("PacmanLose.ogg"))
			cout << " COIN SOUND ERROR" << endl;
		PacmanLose.setBuffer(Losebuffer);
	}

	// Set Sprites & Shapes for the Game items
	{
		file.open("Level1.txt");
		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 20; j++)
			{
				file >> c;
				map[i][j] = c;

				if (c == '#')
					Map[i][j] = Tile;

				else
				{
					//random function to Decide collectable type
					tmp.x = i;
					tmp.y = j;

					tmp.sp.setTexture(coin);
					int r = rand() % 32;

					if (r < 29)
					{
						tmp.type = small;
						tmp.sp.setScale(0.01f, 0.01f);
					}
					else if (r >= 29 && r < 30)
					{
						tmp.type = big;
						tmp.sp.setScale(0.02f, 0.02f);
					}

					else if (r == 30)
					{
						tmp.type = fire;
						tmp.sp.setTexture(firep);
						tmp.sp.setScale(0.04, 0.04);
						//
					}
					else if (r == 31)
					{
						tmp.type = livebonus;
						tmp.sp.setTexture(bonuslive);
						tmp.sp.setScale(0.08f, 0.08f);
					}

					if (i != 1 || j != 1)
						collectables.push_back(tmp);

					Map[i][j] = space;
				}

				Map[i][j].setPosition((i * 30) + 145, (j * 30) + 145);
			}
		}
		file.close();

		Levelcnt = 1;
	}
}

void Game::GameLoop(RenderWindow& window)
{
	bool inlevel = false;

	if (state != MUTE)
		menu.PlayGameMusic(window);

	while (window.isOpen())
	{

		if (state == MENU || state == OPTIONS || state == INSTRUCTIONS || state == CONTINUE || state == GAMEOVER || state == YOUWIN)
		{
			inlevel = false;
			// Reintialize Game 
			if (state == GAMEOVER || state ==YOUWIN)
			{
				Levelcnt = 1;
				s = 0;
				con = "";
				score.setString(con);
			}

			menu.DrawBlocks(window, state);
		}

		else if (state == GAME)
		{
			//menu.CheckMusic();

			if (!inlevel)
			{
				inlevel = true;
				switch (Levelcnt)
				{
				case 1:
					SetLevel(Levelcnt, window);
					break;
				case 2:
					SetLevel(Levelcnt, window);
					break;
				case 3:
					SetLevel(Levelcnt, window);
					break;
				case 4:
					SetLevel(Levelcnt, window);
					break;
				case 5:
					SetLevel(Levelcnt, window);
					break;
				}
			}

			if (clockimune.getElapsedTime().asSeconds() > 5)
				ghosts.setghostdead(7);

			//menu.PlayGameMusic(window);
			Event event;
			while (window.pollEvent(event))
			{
				// Sond On & Off Icons
				if (Mouse::isButtonPressed(Mouse::Left))
				{
					if (SoundOffSmall.getGlobalBounds().contains(Vector2f(Mouse::getPosition(window))))
					{
						menu.StopGameMusic(window);
						PacmanLose.stop();
						CoinSound.stop();
					}

					else
						if (SoundOnSmall.getGlobalBounds().contains(Vector2f(Mouse::getPosition(window))))
						{
							menu.PlayGameMusic(window);
							PacmanLose.play();
							CoinSound.play();
						}
				}
				if (event.type == Event::Closed)
					window.close();

				// Pacman Movement
				if (event.type == Event::KeyPressed)
				{
					switch (event.key.code)
					{
					case Keyboard::Down:
					{//if(Collision(Vector2f(pacman.getposition().x,pacman.getposition().y+30)))
					//if (clock.getElapsedTime().asMilliseconds() >600 )
						if (map[PacmnI][PacmanJ + 1] == '-')
						{//pacman.move('D', 30);
							//PacmanJ++;
							direction = down;
						}
						break;
					}

					case Keyboard::Up:
					{//if (pacman.getSprite().getLocalBounds().intersects(space.getLocalBounds()))
						//if (Collisikkpokvpfkv lpon(Vector2f(pacman.getposition().x, pacman.getposition().y - 30)))
						if (map[PacmnI][PacmanJ - 1] == '-')
						{	//pacman.move('U', 30);
							//PacmanJ--;
							direction = up;
						}
						break;
					}
					case Keyboard::Right:
					{	//if (pacman.getSprite().getLocalBounds().intersects(space.getLocalBounds()))
						//if (Collision(Vector2f(pacman.getposition().x+30, pacman.getposition().y )))
						if (map[PacmnI + 1][PacmanJ] == '-')
						{
							//pacman.move('R', 30);
							//PacmnI++;
							direction = right;

						}
						break;
					}
					case Keyboard::Left:
					{	//if (pacman.getSprite().getLocalBounds().intersects(space.getLocalBounds()))
						//if (Collision(Vector2f(pacman.getposition().x-30, pacman.getposition().y )))
						if (map[PacmnI - 1][PacmanJ] == '-')
						{
							//pacman.move('L', 30);
							//PacmnI--;
							direction = left;
						}
						break;
					}

					}
				}

			}

			// Pacman Continue Motion
			if (clock1.getElapsedTime().asMilliseconds() >= 300)
			{
				isdead(pacman, ghosts, window, state);

				if (direction == up && map[PacmnI][PacmanJ - 1] == '-')
				{
					pacman.move('U', 30);
					//direction = up;
					PacmanJ--;
				}

				else  if (direction == down && map[PacmnI][PacmanJ + 1] == '-')
				{
					pacman.move('D', 30);
					//direction = down;
					PacmanJ++;
				}

				else if (direction == right && map[PacmnI + 1][PacmanJ] == '-')
				{
					pacman.move('R', 30);
					//direction = right;
					PacmnI++;
				}

				else if (direction == left && map[PacmnI - 1][PacmanJ] == '-')
				{
					pacman.move('L', 30);
					//direction = left;
					PacmnI--;
				}


				// Ghosts Movement 
				if (clockimune.getElapsedTime().asSeconds() > 5)
				{

					ghosts.changeTexture(0, 0);
					imune = false;
				}


				for (int i = 0; i < 4; i++)
				{
					bool flag = true;

					while (flag)
					{
						int r = rand() % 80;

						if (((0 < r) && (r < 20)) && Collision(Vector2f(ghosts.getposition(i).x, ghosts.getposition(i).y - 30)) == false)
						{
							ghosts.moveghost(Vector2f(0, -30), i);
							flag = false;
							if (imune) {
								ghosts.imuneGhosts();
							}
						}

						else if (((20 < r) && (r < 40)) && Collision(Vector2f(ghosts.getposition(i).x + 30, ghosts.getposition(i).y)) == false)
						{
							ghosts.moveghost(Vector2f(30, 0), i);
							flag = false;
							if (imune) {
								ghosts.imuneGhosts();
							}
							else ghosts.changeTexture(0, 60);
						}

						else if (((40 < r) && (r < 60)) && Collision(Vector2f(ghosts.getposition(i).x, ghosts.getposition(i).y + 30)) == false)
						{
							ghosts.moveghost(Vector2f(0, 30), i);
							flag = false;
							if (imune) {
								ghosts.imuneGhosts();
							}
							else
								ghosts.changeTexture(0, 20);
						}

						else  if (((60 < r) && (r < 80)) && Collision(Vector2f(ghosts.getposition(i).x - 30, ghosts.getposition(i).y)) == false)
						{
							ghosts.moveghost(Vector2f(-30, 0), i);
							flag = false;
							if (imune) {
								ghosts.imuneGhosts();
							}
							else
								ghosts.changeTexture(0, 40);
						}

					}

				}
				clock1.restart();
			}
			window.clear();


			//Draw the Map & The BackGround Picture
			{
				switch (Levelcnt)
				{
				case 1:
					window.draw(background[0]);
					break;
				case 2:
					window.draw(background[1]);
					break;
				case 3:
					window.draw(background[2]);
					break;
				case 4:
					window.draw(background[3]);
					break;
				case 5:
					window.draw(background[4]);
					break;
				default:
					break;
				}

				for (int i = 0; i < 20; i++)
				{
					for (int j = 0; j < 20; j++)
					{
						window.draw(Map[i][j]);

					}
				}
			}

			//Delete the Coins & Bonus
			for (int k = 0; k < collectables.size(); k++)
			{
				if (pacman.getSprite().getGlobalBounds().intersects(collectables[k].sp.getGlobalBounds()) && collectables[k].type == small)
				{
					CoinSound.play();
					collectables.erase(collectables.begin() + k);
					s += 10;
					con = to_string(s);
					score.setString(con);
				}
				else if (pacman.getSprite().getGlobalBounds().intersects(collectables[k].sp.getGlobalBounds()) && collectables[k].type == big)
				{
					clockimune.restart();
					imune = true;
					ghosts.imuneGhosts();
					CoinSound.play();
					collectables.erase(collectables.begin() + k);
					s += 50;
					con = to_string(s);
					score.setString(con);
				}
				else if (pacman.getSprite().getGlobalBounds().intersects(collectables[k].sp.getGlobalBounds()) && collectables[k].type == livebonus)
				{
					collectables.erase(collectables.begin() + k);
					lives++;
					Lives.push_back(addlive);
					Lives[Lives.size() - 1].setTexture(pacmanstexture);
					Lives[Lives.size() - 1].setScale(Vector2f(0.01f, 0.01f));
					Lives[Lives.size() - 1].setPosition(Vector2f((200 + ((Lives.size() - 1) * 30)), 60));
				}
				else if (pacman.getSprite().getGlobalBounds().intersects(collectables[k].sp.getGlobalBounds()) && collectables[k].type == fire)
				{
					collectables.erase(collectables.begin() + k);
					s += 100;

				}
			}

			// Up to the Next Level
			if (collectables.size() == 0)
			{
				Levelcnt++;
				if (Levelcnt <= 5)
					state = CONTINUE;

				else
				{
					state = YOUWIN;
					menu.DrawBlocks(window, state);
				}
			}

			// Eat Ghosts During Imune
			for (int i = 0; i < 4; i++)
			{
				if (pacman.getSprite().getGlobalBounds().intersects(ghosts.ghostbound(i)))
				{
					ghosts.setghostdead(i);
					s += 200;
				}
			}


			//Set Positions for the Collectables & Draw 
			for (int o = 0; o < collectables.size(); o++) {
				collectables[o].sp.setPosition(Vector2f(collectables[o].x * 30 + 150, collectables[o].y * 30 + 150));
				window.draw(collectables[o].sp);
			}

			// Draw everything
			{
				ghosts.DrawGhost(window);
				pacman.DrawPacman(window);
				window.draw(score);
				window.draw(SoundOffSmall);
				window.draw(SoundOnSmall);
				pacman.DrawScore(window);
				for (int i = 0; i < Lives.size(); i++)
					window.draw(Lives[i]);
			}

			//Dispaly Everything
			window.display();

		}
	}
}

void Game::SetLevel(int L, RenderWindow& window)
{
	lives = 3;
	Lives.resize(3);
	for (int i = 0; i < Lives.size(); i++)
	{
		Lives[i].setTexture(pacmanstexture);
		Lives[i].setScale(Vector2f(0.01f, 0.01f));
		Lives[i].setPosition(Vector2f((200 + (i * 30)), 60));
	}
	PacmanJ = 1; PacmnI = 1;
	pacman.setPosition(Vector2f(180, 180));
	//pacman.set
	window.clear();
	collectables.clear();
	switch (L)
	{
	case 1:
	{

		Tile.setSize(Vector2f(30, 30));
		Tile.setFillColor(Color(20, 90, 50));
		Tile.setOutlineColor(Color(39, 174, 96));
		Tile.setOutlineThickness(-4);
		space.setSize(Vector2f(30, 30));
		space.setFillColor(Color(130, 224, 170));
		Space = Color(13, 206, 250);
		file.open("level1.txt");
		break;
	}
	case 2:
	{
		Tile.setFillColor(Color(160, 64, 0));
		Tile.setOutlineColor(Color(211, 84, 0));
		space.setFillColor(Color(229, 152, 102));
		file.open("level2.txt");
		break;
	}

	case 3:
	{
		Tile.setFillColor(Color(133, 193, 233));
		Tile.setOutlineColor(Color(174, 214, 241));
		space.setFillColor(Color(40, 116, 166));
		file.open("Level3.txt");
		break;
	}

	case 4:
	{
		Tile.setFillColor(Color(234, 234, 234));
		Tile.setOutlineColor(Color(209, 227, 255));
		space.setFillColor(Color(255, 255, 255));
		file.open("Level4.txt");
		break;
	}

	case 5:
		Tile.setFillColor(Color(212, 172, 13));
		Tile.setOutlineColor(Color(224, 208, 63));
		space.setFillColor(Color(249, 231, 159));
		file.open("Map.txt");
		break;
	}

	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			file >> c;
			map[i][j] = c;

			if (c == '#')
				Map[i][j] = Tile;

			else
			{
				//random function to Decide collectable type
				tmp.x = i;
				tmp.y = j;

				tmp.sp.setTexture(coin);
				int r = rand() % 32;

				if (r < 29)
				{
					tmp.type = small;
					tmp.sp.setScale(0.01f, 0.01f);
				}
				else if (r >= 29 && r < 30)
				{
					tmp.type = big;
					tmp.sp.setScale(0.02f, 0.02f);
				}

				else if (r == 30)
				{
					tmp.type = fire;
					tmp.sp.setTexture(firep);
					tmp.sp.setScale(0.04, 0.04);
					//
				}
				else if (r == 31)
				{
					tmp.type = livebonus;
					tmp.sp.setTexture(bonuslive);
					tmp.sp.setScale(0.08f, 0.08f);
				}

				if (i != 1 || j != 1)
					collectables.push_back(tmp);

				Map[i][j] = space;
			}

			Map[i][j].setPosition((i * 30) + 145, (j * 30) + 145);
		}
	}
	file.close();
}

RectangleShape Game::getTile()
{
	return Tile;
}

RectangleShape Game::getSpace()
{
	return space;
}

bool Game::Collision(Vector2f pos)
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
			if (Map[i][j].getGlobalBounds().contains(pos) && map[i][j] == '#')
				return true;
	}
	return false;
}

void Game::isdead(Player& pacman, Ghosts ghosts, RenderWindow&window, State& state)
{
	for (int i = 0; i < 4; i++)
	{
		if (pacman.getSprite().getGlobalBounds().intersects(ghosts.ghostbound(i)))
		{
			if (imune==false)
			   PacmanLose.play();
			if (lives > 1)
			{
				if (!imune)
				{
					lives--;
					Lives.pop_back();
					pacman.setPosition(Vector2f(180, 180));
					PacmnI = 1, PacmanJ = 1;
				}
			}
			else
			{
				cout << "GAMEOVER" << endl;
				state = GAMEOVER;


			}
		}

	}
}


Sprite Game::getBGSprite(int b) {
	switch (b)
	{
	case 1:
		return background[1];
		break;
	case 2:
		return background[2];
		break;
	case 3:
		return background[3];
		break;
	case 4:
		return background[4];
		break;
	case 5:
		return background[5];
		break;
	}

}
