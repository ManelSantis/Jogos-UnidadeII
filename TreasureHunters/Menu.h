#ifndef _MENU_H_
#define _MENU_H_

#include "Game.h"
#include "Sprite.h"
#include "TileSet.h"
#include "Animation.h"
#include "Mouse.h"
#include "Buttons.h"

class Menu : public Game {
	private:
		Sprite* background = nullptr;
		TileSet* tileset = nullptr;
		Animation* animacao = nullptr;
		Buttons* play = nullptr;
		Mouse* mouse = nullptr;

	public:
		void Init();
		void Update();
		void Draw();
		void Finalize();
};


#endif
