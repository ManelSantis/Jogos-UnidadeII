#ifndef _TREASUREHUNTERS_H_
#define _TREASUREHUNTERS_H_

#include "Game.h"
#include "Audio.h"
#include "Font.h"
//#include "Resources.h"

enum Sounds {GAMESTART, BUTTONDOWN, FOREST, CATCHDIAMOND, CAVES, NEXTLEVEL, 
				JUMP, DOUBLEJUMP, OPENDOOR, CLOSEDOOR, PLAYERHIT, GAMEOVER};
enum GameObjects {PLAYER, BLOCK, DIAMOND, TRAP, LVLUP, NEXTCAVE};

class TreasureHunters : public Game {
	private:
		static Game* level;
	public:
		static Font* arcade15;
		static Font* arcade30;
		static Font* arcade55;
		static Audio* audio;
		static bool viewBBox;

		template<class T>
		static void NextLevel() {
			if (level) {
				level->Finalize();
				delete level;
				level = new T();
				level->Init();
			}
		};

		void Init();
		void Update();
		void Draw();
		void Finalize();
};

#endif
