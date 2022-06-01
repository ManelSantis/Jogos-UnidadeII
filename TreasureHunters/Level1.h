#ifndef _LEVEL1_H_
#define _LEVEL1_H_

#include "Game.h"
#include "Scene.h"
#include "Player.h"
#include "Mouse.h"
#include "Buttons.h"

class Level1 : public Game {
	private:
		Scene* scene = nullptr;
		Player* player = nullptr;
		Mouse* mouse = nullptr;
		Buttons* pause = nullptr;
		Buttons* restart = nullptr;
		bool pausou = false;
		bool resetar = false;

	public:

		void Init();
		void Update();
		void Draw();
		void Finalize();
};

#endif
