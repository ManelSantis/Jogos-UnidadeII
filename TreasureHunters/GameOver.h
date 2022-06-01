#ifndef _GAMEOVER_H_
#define _GAMEOVER_H_

#include "Game.h"
#include "Sprite.h"
#include "TileSet.h"
#include "Animation.h"
#include "Mouse.h"
#include "Buttons.h"

class GameOver : public Game {
private:
	Sprite* background = nullptr;
	Sprite* starsEffect = nullptr;

	Mouse* mouse = nullptr;
	Buttons* restart = nullptr;
	Buttons* menu = nullptr;

	int contador = 0;

public:
	static int score;
	static int level;

	void Init();
	void Update();
	void Draw();
	void Finalize();
};


#endif

