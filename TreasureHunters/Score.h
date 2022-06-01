#ifndef _SCORE_H_
#define _SCORE_H_

#include "Game.h"
#include "Sprite.h"
#include "Mouse.h"
#include "Buttons.h"

class Score : public Game {
private:
	Sprite* background = nullptr;
	Sprite* starsEffect = nullptr;
	Mouse* mouse = nullptr;
	Buttons* restart = nullptr;
	Buttons* menu = nullptr;
	Buttons* next = nullptr;
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

