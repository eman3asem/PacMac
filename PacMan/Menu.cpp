#include "stdafx.h"
#include "Menu.h"

Menu::Menu()
{
	// Main Menu Icons
	{
		Start.setSize(Vector2f(200, 100));
		Start.setFillColor(Color::Black);
		Start.setOutlineColor(Color::Yellow);
		Start.setOutlineThickness(-4);
		Start.setPosition(400, 350);

		Options.setSize(Vector2f(200, 100));
		Options.setFillColor(Color::Black);
		Options.setOutlineColor(Color::Yellow);
		Options.setOutlineThickness(-4);
		Options.setPosition(400, 500);

		Instructions.setSize(Vector2f(200, 100));
		Instructions.setFillColor(Color::Black);
		Instructions.setOutlineColor(Color::Yellow);
		Instructions.setOutlineThickness(-4);
		Instructions.setPosition(400, 650);

		Exit.setSize(Vector2f(200, 100));
		Exit.setFillColor(Color::Black);
		Exit.setOutlineColor(Color::Yellow);
		Exit.setOutlineThickness(-4);
		Exit.setPosition(400, 800);

	}

	//Main Menu Texts
	{
		//Font Settings

		font.loadFromFile("comic.ttf");
		if (!font.loadFromFile("comic.ttf"))
		{
			cout << "error" << endl;
		}

		start.setFont(font);
		start.setString("Start");
		start.setCharacterSize(24);
		start.setColor(Color::Yellow);
		start.setStyle(Text::Bold | Text::Italic);
		start.setPosition(430, 390);

		options.setFont(font);
		options.setString("Settings");
		options.setCharacterSize(24);
		options.setColor(Color::Yellow);
		options.setStyle(Text::Bold | Text::Italic);
		options.setPosition(430, 540);

		instructions.setFont(font);
		instructions.setString("Instructions");
		instructions.setCharacterSize(24);
		instructions.setColor(Color::Yellow);
		instructions.setStyle(Text::Bold | Text::Italic);
		instructions.setPosition(430, 690);


		exist.setFont(font);
		exist.setString("Exit");
		exist.setCharacterSize(24);
		exist.setColor(Color::Yellow);
		exist.setStyle(Text::Bold | Text::Italic);
		exist.setPosition(450, 840);
	}

	// Game Instructions
	{
		{
			if (!instructionspic.loadFromFile("Instructions.png"))
				cout << "Error" << endl;
		}
		Instructionstxt.setTexture(instructionspic);
		Instructionstxt.setScale(Vector2f(1,1.5 ));
		Instructionstxt.setPosition(Vector2f(0, 0));
	}


	// Game Picture
	{
		if (!gamepic.loadFromFile("gamepic.png"))
			cout << "Error" << endl;
		GameSprite.setScale(1.0f, 1.0f);
		GameSprite.setPosition(150, 50);
		GameSprite.setTexture(gamepic);
	}

	// Back To Menu
	{
		if (!BackMenupic.loadFromFile("Back_To_Menu.png"))
		{
			cout << "error";
		}
		BackToMenu.setScale(0.5, 0.5);
		BackToMenu.setPosition(800, 50);
		BackToMenu.setTexture(BackMenupic);
	}

	// Game Over Settings
	{
		if (!GameOver.loadFromFile("GameOver.png"))
		{
			cout << "error";
		}
		gameover.setPosition(200, 100);
		gameover.setScale(1.0f, 1.0f);
		gameover.setTexture(GameOver);
	}

	// Music Settings
	{
		if (!gamemusic.openFromFile("gamemusic.ogg"))
			cout << " MUISC LOADING ERROR" << endl;

		gamemusic.setLoop(true);
	}

	// Next Level Picture Settings
	{
		if (!nextpic.loadFromFile("LevelUP (1).png"))
			cout << "Error" << endl;

		NextLevel.setTexture(nextpic);
		NextLevel.setPosition(200, 100);
		NextLevel.setScale(1.0f, 1.0f);

		if (!continuepic.loadFromFile("click_here_to_contine.png"))
		{
			cout << "error";
		}
		Continue.setScale(0.5, 0.5);
		Continue.setPosition(500, 800);
		Continue.setTexture(continuepic);
	}

	// Mute Picture's Settings 
	{
		if (!mute.loadFromFile("SoundOff.png"))
		{
			cout << "error";
		}
		Mute.setScale(0.5, 0.5);
		Mute.setPosition(400, 600);
		Mute.setTexture(mute);
	}

	// UnMute Picture's Settings 
	{
		if (!soundon.loadFromFile("SoundOn.png"))
		{
			cout << "error";
		}
		SoundOn.setScale(0.6, 0.6);
		SoundOn.setPosition(400,350);
		SoundOn.setTexture(soundon);
	}

	// YOU WIN
	{
		if (!youwin.loadFromFile("youwin.png"))
		{
			cout << "error";
		}
		YouWin.setScale(2.0, 2.0);
		YouWin.setPosition(200, 200);
		YouWin.setTexture(youwin);
	}
}

Menu::~Menu()
{
}

void Menu::DrawBlocks(RenderWindow& window, State& state)
{
	//Event event;
	//while (window.pollEvent(event))
	//{
	//	switch (event.type)
	//	{
	//	case  Event::Closed:
	//	{
	//		window.close();
	//		break;
	//	}

	//	case Event::Resized:
	//	{
	//		// We need to adjust the settings of the window
	//		cout << event.size.width << " : " << event.size.height << endl;
	//		break;
	//	}

	//	/*case Event::EventType::MouseButtonPressed:
	//	if (BackToMenu.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
	//	{
	//	state = MENU;
	//	}*/
	//	}

	//}

	if (state == MENU)
	{	// Draw the RectangleShapes
		{
			window.clear();
			window.draw(GameSprite);
			window.draw(Start);
			window.draw(Options);
			window.draw(Instructions);
			window.draw(Exit);
		}

		// Draw the Texts 
		{
			window.draw(start);
			window.draw(options);
			window.draw(exist);
			window.draw(instructions);
			window.display();
		}

		//Mouse Events
		Event eventMenu;
		while (window.pollEvent(eventMenu))
		{
			if (eventMenu.type == Event::Closed)
				window.close();
			else if (eventMenu.type == Event::MouseButtonPressed)
			{
				if (Start.getGlobalBounds().contains(Vector2f(Mouse::getPosition(window))))
				{
					state = GAME;
					cout << "Game" << endl;
				}
				else
					if (Options.getGlobalBounds().contains(Vector2f(Mouse::getPosition(window))))
					{
						state = OPTIONS;
						cout << "Optionss" << endl;
					}
					else
						if (Instructions.getGlobalBounds().contains(Vector2f(Mouse::getPosition(window))))
						{
							state = INSTRUCTIONS;
							cout << "Instructions" << endl;
						}
						else
							if (Exit.getGlobalBounds().contains(Vector2f(Mouse::getPosition(window))))
							{

								cout << "Exit" << endl;;
								window.close();
							}

			}
		}
	}

	else if (state == GAMEOVER)
	{

		window.clear();
		window.draw(gameover);
		window.draw(BackToMenu);
		window.display();
		Event e;
		while (window.pollEvent(e))
		{
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				if (BackToMenu.getGlobalBounds().contains(Vector2f(Mouse::getPosition(window))))
				{
					state = MENU;
				}
			}
			if (Event::Closed)
				window.close();

		}
	}

	else if (state == CONTINUE)

	{
		window.clear();
		window.draw(NextLevel);
		window.draw(Continue);
		window.display();
		Event e;
		while (window.pollEvent(e))
		{
			if (e.type == Event::MouseButtonPressed)
			{
				if (Continue.getGlobalBounds().contains(Vector2f(Mouse::getPosition(window))))
				{
					std::cout << "Change to GAME" << std::endl;
					state = GAME;
				}
			}
			if (Event::Closed)
				window.close();
		}

	}

	else if (state == INSTRUCTIONS)
	{
		window.clear();
		window.draw(Instructionstxt);
		window.draw(BackToMenu);
		window.display();
		Event e;
		while (window.pollEvent(e))
		{
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				if (BackToMenu.getGlobalBounds().contains(Vector2f(Mouse::getPosition(window))))
				{
					state = MENU;
				}
			}
			else if (e.type == Event::Closed)
				window.close();

		}
	}

	else if (state == OPTIONS)
	{
		window.clear();
		window.draw(Mute);
		window.draw(SoundOn);
		window.draw(BackToMenu);
		window.display();
		Event e;
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
				window.close();

			if (Mouse::isButtonPressed(Mouse::Left))
			{
				if (Mute.getGlobalBounds().contains(Vector2f(Mouse::getPosition(window))))
				{
					PlayGameMusic(window);
					gamemusic.stop();
				}

				else
					if (SoundOn.getGlobalBounds().contains(Vector2f(Mouse::getPosition(window))))
					{
						PlayGameMusic(window);
						gamemusic.play();
					}
					else
						if (BackToMenu.getGlobalBounds().contains(Vector2f(Mouse::getPosition(window))))
						{
							state = MENU;
						}

			}

		}
	}

	else if (state == YOUWIN)
	{
		window.clear();
		window.draw(YouWin);
		window.draw(BackToMenu);
		window.display();
		Event e;
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
				window.close();
			else
				if (BackToMenu.getGlobalBounds().contains(Vector2f(Mouse::getPosition(window))))
				{
					state = MENU;
				}
		}
	}
}


void Menu::ButtonsClick(RenderWindow& window)
{
	Event event;
	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case Event::Closed:
			window.close();
			break;

		case Event::Resized:
			cout << event.size.width << " : " << event.size.height << endl;
			break;

		case Event::LostFocus:  // This can be used to pause the Game
			cout << "Lost Focus" << endl;
			break;

		case Event::GainedFocus: //  This can be used to Resume the Game
			cout << "Gained Focus" << endl;
			break;
			/*
			case Event::TextEntered:
				if (event.text.unicode < 128)
					cout << static_cast<char> (event.text.unicode) << endl;
				break;*/

				/*case Event:: EventType::MouseButtonPressed:
					if (Mouse::Button::Left == event.mouseButton.button)
						cout << "Left Mouse Button Pressed" << endl;
					break;*/

		case Event::EventType::MouseButtonPressed:
			if (Start.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
			{

			}


			break;

		}
	}
}

void Menu::PlayGameMusic(RenderWindow& window)
{
	gamemusic.play();

}

/*void Menu::CheckMusic()
{
	   if (gamemusic.Stopped(0))
		gamemusic.setLoop(true);
}*/

void Menu::PauseGameMusic(RenderWindow& window)
{
	gamemusic.pause();

}

void Menu::DrawNextLevelPic(RenderWindow& window)
{
	Event event;

	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case  Event::Closed:
		{
			window.close();
			break;
		}
		}
	}


}

State Menu::getContinueButton()
{
	return CONTINUE;
}

State Menu::drawYouWin(RenderWindow& window)
{
	window.clear();
	window.draw(YouWin);
	window.draw(BackToMenu);
	window.display();

	if (Mouse::isButtonPressed(Mouse::Left))
	{
		if (BackToMenu.getGlobalBounds().contains(Vector2f(Mouse::getPosition(window))))
			return  MENU;
	}
	else
		return YOUWIN;

}

void Menu::StopGameMusic(RenderWindow& window)
{
	gamemusic.stop();
}

void Menu::DrawBacktoMenu(RenderWindow& window)
{
	window.draw(BackToMenu);
}