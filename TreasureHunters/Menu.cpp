#include "Engine.h"
#include "Menu.h"
#include "TreasureHunters.h"
#include "Level1.h"
#include "Level3_3.h"


void Menu::Init() {
	background = new Sprite("Resources/Backgrounds/Menu.png");
	tileset = new TileSet("Resources/Logo.png", 436, 160, 1, 8);
	animacao = new Animation(tileset, 0.1f, true);

	mouse = new Mouse();
	play = new Buttons(window->CenterX(), 320.0F, PLAY);
	TreasureHunters::audio->Play(GAMESTART, true);
}

void Menu::Update() {
	
	if (!play->MouseOver() && play->MouseOver(mouse->Over(play))) {
		TreasureHunters::audio->Play(BUTTONDOWN);
	}

	play->MouseOver(mouse->Over(play));

	if (play->MouseOver() && mouse->Clicked()) {
		TreasureHunters::audio->Stop(GAMESTART);
		TreasureHunters::NextLevel<Level1>();
	}
	else {
		mouse->Update();
		play->Update();
		animacao->NextFrame();
	}
}

void Menu::Draw() {
	background->Draw(window->CenterX(), window->CenterY());
	animacao->Draw(window->CenterX(), 125.0f, Layer::FRONT);
	play->Draw();
	/*Engine::renderer->BeginPixels();

	ulong magenta = (255 << 24) + (255 << 16) + (0 << 8) + 255;

	
	Engine::renderer->Draw(mouse->BBox(), magenta);
	


	Engine::renderer->EndPixels();*/
}

void Menu::Finalize() {
	delete mouse;
	delete play;
	delete animacao;
	delete tileset;
	delete background;
}
	