#include "Engine.h"
#include "Menu.h"
#include "GameOver.h"
#include "TreasureHunters.h"
#include "Level1.h"
#include "Level2.h"
#include "Level3_1.h"

int GameOver::level = NULL;
int GameOver::score = NULL;

void GameOver::Init() {
	background = new Sprite("Resources/GameOver/GameOver.png");
	starsEffect = new Sprite("Resources/GameOver/StarsEffect.png");
	
	mouse = new Mouse();

	restart = new Buttons(window->CenterX() + 22.0f, 320.0f, RESTART);
	menu = new Buttons(window->CenterX() - 22.0f, 320.0f, MENU);

	TreasureHunters::audio->Play(GAMEOVER);
}

void GameOver::Update() {

	if (!restart->MouseOver() && restart->MouseOver(mouse->Over(restart))) {
		TreasureHunters::audio->Play(BUTTONDOWN);
	}

	if (!menu->MouseOver() && menu->MouseOver(mouse->Over(menu))) {
		TreasureHunters::audio->Play(BUTTONDOWN);
	}


	menu->MouseOver(mouse->Over(menu));

	if ((menu->MouseOver() && mouse->Clicked()) || window->KeyPress(VK_ESCAPE)) {
		TreasureHunters::audio->Stop(GAMEOVER);
		TreasureHunters::NextLevel<Menu>();
	} else {

		restart->MouseOver(mouse->Over(restart));

		if (restart->MouseOver() && mouse->Clicked()) {
			TreasureHunters::audio->Stop(GAMEOVER);

			if (level == 1) {
				TreasureHunters::NextLevel<Level1>();
			}

			if (level == 2) {
				TreasureHunters::NextLevel<Level2>();
			}

			if (level == 3) {
				TreasureHunters::NextLevel<Level3_1>();
			}
		}
		else {

			if (contador != score * 2) {
				contador++;
				Sleep(10);
			}

			starsEffect->Draw(223.0f + contador, 203.0f, Layer::UPPER);

			restart->Update();
			mouse->Update();
			menu->Update();
		}

	}

}

void GameOver::Draw() {
	background->Draw(window->CenterX(), window->CenterY(), Layer::FRONT);
	restart->Draw();
	menu->Draw();
}

void GameOver::Finalize() {
	delete mouse;
	delete background;
	delete starsEffect;
	delete restart;
	delete menu;
}
