#include "Engine.h"
#include "Menu.h"
#include "Score.h"
#include "TreasureHunters.h"
#include "Level1.h"
#include "Level2.h"
#include "Level3_1.h"

int Score::level = NULL;
int Score::score = NULL;

void Score::Init() {

	background = new Sprite("Resources/Stars/Stars.png");
	starsEffect = new Sprite("Resources/Stars/StarsEffect.png");

	mouse = new Mouse();

	next = new Buttons(window->CenterX() + 60.0f, 320.0f, NEXT);
	restart = new Buttons(window->CenterX(), 320.0f, RESTART);
	menu = new Buttons(window->CenterX() - 60.0f, 320.0f, MENU);

	TreasureHunters::audio->Play(NEXTLEVEL);
}

void Score::Update() {

	if (!restart->MouseOver() && restart->MouseOver(mouse->Over(restart))) {
		TreasureHunters::audio->Play(BUTTONDOWN);
	}

	if (!menu->MouseOver() && menu->MouseOver(mouse->Over(menu))) {
		TreasureHunters::audio->Play(BUTTONDOWN);
	}

	if (!next->MouseOver() && next->MouseOver(mouse->Over(next))) {
		TreasureHunters::audio->Play(BUTTONDOWN);
	}

	menu->MouseOver(mouse->Over(menu));

	if ((menu->MouseOver() && mouse->Clicked()) || window->KeyPress(VK_ESCAPE)) {
		TreasureHunters::audio->Stop(GAMEOVER);
		TreasureHunters::NextLevel<Menu>();
	}
	else {

		restart->MouseOver(mouse->Over(restart));

		if (restart->MouseOver() && mouse->Clicked()) {

			if (level == 1) {
				TreasureHunters::NextLevel<Level1>();
			}

			if (level == 2) {
				TreasureHunters::NextLevel<Level2>();
			}

			if (level == 3) {
				TreasureHunters::NextLevel<Level3_1>();
			}
		} else {
			
			next->MouseOver(mouse->Over(next));

			if (next->MouseOver() && mouse->Clicked()) {

				if (level + 1 == 1) {
					TreasureHunters::NextLevel<Level1>();
				}

				if (level + 1 == 2) {
					TreasureHunters::NextLevel<Level2>();
				}

				if (level + 1 == 3) {
					TreasureHunters::NextLevel<Level3_1>();
				}

				if (level + 1 == 4) {
					TreasureHunters::NextLevel<Menu>();
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
				next->Update();
			}
			
		}

	}

}

void Score::Draw() {
	
	background->Draw(window->CenterX(), window->CenterY(), Layer::FRONT);
	//starsEffect->Draw(223.0f, 203.0f, Layer::UPPER);
	restart->Draw();
	menu->Draw();
	next->Draw();
}

void Score::Finalize() {
	delete mouse;
	delete background;
	delete starsEffect;
	delete next;
	delete restart;
	delete menu;
}
