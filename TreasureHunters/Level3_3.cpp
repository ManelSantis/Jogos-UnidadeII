#include "Engine.h"
#include "TreasureHunters.h"
#include "Menu.h"
#include "Level3_1.h"
#include "Level3_3.h"
#include "Block.h"
#include "Diamond.h"
#include "Spike.h"
#include "Shadow.h"
#include "Background.h"
#include "GameOver.h"
#include "Door.h"
#include "Saw.h"
#include "Score.h"

int Level3_3::pegados = NULL;

void Level3_3::Init() {
	scene = new Scene();

	//Mouse e Botões
	mouse = new Mouse();
	pause = new Buttons(594.0f - 22, 424.0f, PAUSE);
	restart = new Buttons(594.0f + 22, 424.0f, RESTART);

	//Player
	player = new Player(24.0f, 350.0f);
	scene->Add(player, MOVING);

	//Background
	Background* bg = new Background(BGCAVE);
	scene->Add(bg, STATIC);

	//Plataforma
	Block* block = new Block(CAVESOLO, 1, 24.0f, 424.0f, true, 14);
	scene->Add(block, STATIC);

	block = new Block(CAVESOLO, 2, 72.0f, 424.0f, false, 0);
	scene->Add(block, STATIC);

	block = new Block(CAVESOLO, 2, 120.0f, 424.0f, false, 0);
	scene->Add(block, STATIC);

	block = new Block(CAVESOLO, 2, 168.0f, 424.0f, false, 0);
	scene->Add(block, STATIC);

	block = new Block(CAVESOLO, 2, 216.0f, 424.0f, false, 0);
	scene->Add(block, STATIC);

	block = new Block(CAVESOLO, 2, 264.0f, 424.0f, false, 0);
	scene->Add(block, STATIC);

	block = new Block(CAVESOLO, 2, 312.0f, 424.0f, false, 0);
	scene->Add(block, STATIC);

	block = new Block(CAVESOLO, 2, 360.0f, 424.0f, false, 0);
	scene->Add(block, STATIC);

	block = new Block(CAVESOLO, 2, 408.0f, 424.0f, false, 0);
	scene->Add(block, STATIC);

	block = new Block(CAVESOLO, 2, 456.0f, 424.0f, false, 0);
	scene->Add(block, STATIC);

	block = new Block(CAVESOLO, 2, 504.0f, 424.0f, false, 0);
	scene->Add(block, STATIC);

	block = new Block(CAVESOLO, 2, 552.0f, 424.0f, false, 0);
	scene->Add(block, STATIC);

	block = new Block(CAVESOLO, 2, 600.0f, 424.0f, false, 0);
	scene->Add(block, STATIC);

	block = new Block(CAVESOLO, 3, 648.0f, 424.0f, false, 0);
	scene->Add(block, STATIC);

	// Serras sob a primeira plataforma
	Saw* saw = new Saw(120.0f, 400.0f, 0);
	scene->Add(saw, STATIC);

	saw = new Saw(312.0f, 400.0f, 6);
	scene->Add(saw, MOVING);

	//Segunda plataforma

	block = new Block(CAVESOLO, 1, 24.0f, 280.0f, true, 8);
	scene->Add(block, STATIC);

	block = new Block(CAVESOLO, 2, 72.0f, 280.0f, false, 0);
	scene->Add(block, STATIC);

	block = new Block(CAVESOLO, 2, 120.0f, 280.0f, false, 0);
	scene->Add(block, STATIC);

	block = new Block(CAVESOLO, 2, 168.0f, 280.0f, false, 0);
	scene->Add(block, STATIC);

	block = new Block(CAVESOLO, 2, 216.0f, 280.0f, false, 0);
	scene->Add(block, STATIC);

	block = new Block(CAVESOLO, 2, 264.0f, 280.0f, false, 0);
	scene->Add(block, STATIC);

	block = new Block(CAVESOLO, 2, 312.0f, 280.0f, false, 0);
	scene->Add(block, STATIC);

	block = new Block(CAVESOLO, 3, 360.0f, 280.0f, false, 0);
	scene->Add(block, STATIC);


	block = new Block(CAVESOLO, 1, 408.0f, 328.0f,true, 2);
	scene->Add(block, STATIC);
	block = new Block(CAVESOLO, 3, 456.0f, 328.0f, false, 0);
	scene->Add(block, STATIC);

	//Serras sob segunda plataforma

	saw = new Saw(24.0f, 256.0f, 4);
	scene->Add(saw, MOVING);

	saw = new Saw(72.0f, 256.0f, 4);
	scene->Add(saw, MOVING);

	saw = new Saw(360.0f, 256.0f, 0);
	scene->Add(saw, STATIC);

	

	//Terceira plataforma

	block = new Block(CAVESOLO, 1, 312.0f, 136.0f, true, 8);
	scene->Add(block, STATIC);

	block = new Block(CAVESOLO, 2, 360.0f, 136.0f, false, 0);
	scene->Add(block, STATIC);

	block = new Block(CAVESOLO, 2, 408.0f, 136.0f, false, 0);
	scene->Add(block, STATIC);

	block = new Block(CAVESOLO, 2, 456.0f, 136.0f, false, 0);
	scene->Add(block, STATIC);

	block = new Block(CAVESOLO, 2, 504.0f, 136.0f, false, 0);
	scene->Add(block, STATIC);

	block = new Block(CAVESOLO, 2, 552.0f, 136.0f, false, 0);
	scene->Add(block, STATIC);

	block = new Block(CAVESOLO, 2, 600.0f, 136.0f, false, 0);
	scene->Add(block, STATIC);

	block = new Block(CAVESOLO, 3, 648.0f, 136.0f, false, 0);
	scene->Add(block, STATIC);


	block = new Block(CAVESOLO, 3, 192.0f, 136.0f);
	scene->Add(block, STATIC);

	block = new Block(CAVESOLO, 1, 24.0f, 184.0f);
	scene->Add(block, STATIC);

	//Serras terceira camada

	saw = new Saw(48.0f, 184.0f, 0);
	scene->Add(saw, STATIC);

	saw = new Saw(312.0f, 112.0f, 0);
	scene->Add(saw, STATIC);

	saw = new Saw(408.0f, 112.0f, 0);
	scene->Add(saw, STATIC);

	Door* portal = new Door(600.0f, 80.0f, PORTAL);
	scene->Add(portal, STATIC);

	//Diamantes

	Diamond* diamond = new Diamond(RED, 216.0f, 375.0f);
	scene->Add(diamond, STATIC);

	diamond = new Diamond(YELLOW, 480.0f, 206.0f);
	scene->Add(diamond, STATIC);

	diamond = new Diamond(RED, 192.0f, 87.0f);
	scene->Add(diamond, STATIC);

	diamond = new Diamond(YELLOW, 360.0f, 87.0f);
	scene->Add(diamond, STATIC);


}

void Level3_3::Update() {
	if (!pause->MouseOver() && pause->MouseOver(mouse->Over(pause))) {
		TreasureHunters::audio->Play(BUTTONDOWN);
	}

	if (!restart->MouseOver() && restart->MouseOver(mouse->Over(restart))) {
		TreasureHunters::audio->Play(BUTTONDOWN);
	}

	pause->MouseOver(mouse->Over(pause));

	restart->MouseOver(mouse->Over(restart));

	if (pause->MouseOver() && mouse->Clicked()) {
		pausou = !pausou;
	}

	if (restart->MouseOver() && mouse->Clicked()) {
		resetar = true;
	}

	if (resetar) {
		TreasureHunters::NextLevel<Level3_1>();
	} else if (!pausou) {
		if (player->alive) {
			if (player->nextLevel) {
				TreasureHunters::audio->Stop(CAVES);
				Score::level = 3;
				Score::score = (100 * (player->score + pegados)) / 18;
				TreasureHunters::NextLevel<Score>();
			}
			else {
				string aux = std::to_string(player->score + pegados);
				TreasureHunters::arcade15->Draw(24.0f, 430.0f, "Score: " + aux, { 1.0f, 1.0f, 1.0f, 1.0f }, Layer::FRONT);
				mouse->Update();
				pause->Update();
				restart->Update();
				scene->CollisionDetection();
				scene->Update();
			}
		}
		else {
			GameOver::level = 3;
			GameOver::score = (100 * (player->score + pegados)) / 18;			
			TreasureHunters::audio->Stop(CAVES);
			TreasureHunters::NextLevel<GameOver>();
		}
	} else {
		string aux = std::to_string(player->score + pegados);
		TreasureHunters::arcade15->Draw(24.0f, 430.0f, "Score: " + aux, { 1.0f, 1.0f, 1.0f, 1.0f }, Layer::FRONT);
		mouse->Update();
		pause->Update();
		restart->Update();
	}

	if (window->KeyPress(VK_ESCAPE)) {
		TreasureHunters::audio->Stop(CAVES);
		TreasureHunters::NextLevel<Menu>();
	}
}

void Level3_3::Draw() {
	scene->Draw();
	pause->Draw();
	restart->Draw();
	/*Engine::renderer->BeginPixels();

	ulong magenta = (255 << 24) + (255 << 16) + (0 << 8) + 255;

	scene->Begin();
	Object* obj = nullptr;
	while (obj = scene->Next())
	{
		if (obj->BBox())
			Engine::renderer->Draw(obj->BBox(), magenta);
	}

	Engine::renderer->EndPixels();*/
}

void Level3_3::Finalize() {
	delete scene;
	delete restart;
	delete mouse;
	delete pause;
}