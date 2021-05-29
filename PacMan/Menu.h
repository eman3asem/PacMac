#ifndef MENU_H
#define MENU_H
#include <SFML\Graphics.hpp>
#include <fstream>
#include <iostream>
#include <string>
#include <cctype>
#include <SFML/Audio.hpp>
using namespace sf;
using namespace std;
enum State { MENU, GAME, PAUSE, EXIT ,GAMEOVER , CONTINUE, OPTIONS, INSTRUCTIONS, MUTE, YOUWIN};
class Menu
{
private:

	RectangleShape Start ;
	RectangleShape Options;
	RectangleShape Instructions;
	RectangleShape Exit;
	

	Text start;
	Text options;
	Text exist;
	Text instructions;
	Text textoftheinstructions;
	string str;
	Font font;
	 

	Texture GameOver;
	Sprite gameover;
	Sprite BackToMenu;
	Texture BackMenupic;

	Sprite GameSprite;
	Texture gamepic;

	// Next Level
	Sprite NextLevel;
	Texture nextpic;
	Sprite Continue;
	Texture continuepic;
	Sprite YouWin;
	Texture youwin;

	// Music Variables 
	Music gamemusic;
	Sprite Mute;
	Texture mute;
	Sprite SoundOn;
	Texture soundon;
	 
	Sprite Instructionstxt;
	Texture instructionspic;

public:
	Menu();
	~Menu();
	void  DrawBlocks(RenderWindow&,State&);
	void ButtonsClick(RenderWindow&);
	void PlayGameMusic(RenderWindow&);
	void PauseGameMusic(RenderWindow&);
	void DrawNextLevelPic(RenderWindow&);
	State getContinueButton();
	void CheckMusic();
	State drawYouWin(RenderWindow&);
	void StopGameMusic(RenderWindow&);
	void DrawBacktoMenu(RenderWindow& );
};
#endif
