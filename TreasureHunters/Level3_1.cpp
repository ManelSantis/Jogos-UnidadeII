#include "Engine.h"
#include "TreasureHunters.h"
#include "Menu.h"
#include "Level3_1.h"
#include "Level3_2.h"
#include "Block.h"
#include "Diamond.h"
#include "Spike.h"
#include "Shadow.h"
#include "Background.h"
#include "GameOver.h"
#include "Door.h"

void Level3_1::Init() {
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

	//Sombra
	Shadow* shadow = new Shadow(player, FOG);
	scene->Add(shadow, MOVING);

	

	//Primeira plataforma
	Block* block = new Block(CAVESOLO, 1, 24.0f, 424.0f, true, 3);
	scene->Add(block, STATIC);

	block = new Block(CAVESOLO, 2, 72.0f, 424.0f, false, 0);
	scene->Add(block, STATIC);

	block = new Block(CAVESOLO, 3, 120.0f, 424.0f, false, 0);
	scene->Add(block, STATIC);

	//Segunda plataforma
	block = new Block(CAVESOLO, 0, 264.0f, 424.0f);
	scene->Add(block, STATIC);

	//Terceira plataforma
	block = new Block(CAVESOLO, 1, 408.0f, 424.0f, true, 6);
	scene->Add(block, STATIC);

	block = new Block(CAVESOLO, 2, 456.0f, 424.0f, false, 0);
	scene->Add(block, STATIC);

	block = new Block(CSSOLO, 2, 504.0f, 424.0f, false, 0);
	scene->Add(block, STATIC);

	block = new Block(CSSOLO, 2, 552.0f, 424.0f, false, 0);
	scene->Add(block, STATIC);

	block = new Block(CSSOLO, 2, 600.0f, 424.0f, false, 0);
	scene->Add(block, STATIC);

	block = new Block(CSSOLO, 3, 648.0f, 424.0f, false, 0);
	scene->Add(block, STATIC);

	//Segunda camada
	block = new Block(CAVECONTINUO, 1, 504.0f, 376.0f, true, 4);
	scene->Add(block, STATIC);

	block = new Block(CAVECONTINUO, 2, 552.0f, 376.0f, false, 0);
	scene->Add(block, STATIC);

	block = new Block(CSCONTINUO, 2, 600.0f, 376.0f, false, 0);
	scene->Add(block, STATIC);

	block = new Block(CSCONTINUO, 3, 648.0f, 376.0f, false, 0);
	scene->Add(block, STATIC);

	//Terceira camada

	block = new Block(CAVECONTINUO, 1, 600.0f, 328.0f, true, 2);
	scene->Add(block, STATIC);

	block = new Block(CAVECONTINUO, 3, 648.0f, 328.0f, false, 0);
	scene->Add(block, STATIC);

	//Espinhos sobre primeira plataforma

	Spike* spike = new Spike(456.0f, 396.0f, T);
	scene->Add(spike, STATIC);

	spike = new Spike(472.0f, 396.0f, T);
	scene->Add(spike, STATIC);

	//Quarta plataforma

	block = new Block(CAVESOLO, 1, 24.0f, 265.0f, true, 9);
	scene->Add(block, STATIC);

	block = new Block(CAVESOLO, 2, 72.0f, 265.0f, false, 0);
	scene->Add(block, STATIC);

	block = new Block(CAVESOLO, 2, 120.0f, 265.0f, false, 0);
	scene->Add(block, STATIC);

	block = new Block(CSSOLO, 2, 168.0f, 265.0f, false, 0);
	scene->Add(block, STATIC);

	block = new Block(CAVESOLO, 2, 216.0f, 265.0f, false, 0);
	scene->Add(block, STATIC);

	block = new Block(CAVESOLO, 2, 264.0f, 265.0f, false, 0);
	scene->Add(block, STATIC);

	block = new Block(CAVESOLO, 2, 312.0f, 265.0f, false, 0);
	scene->Add(block, STATIC);

	block = new Block(CAVESOLO, 2, 360.0f, 265.0f, false, 0);
	scene->Add(block, STATIC);

	block = new Block(CAVESOLO, 3, 408.0f, 265.0f, false, 0);
	scene->Add(block, STATIC);
	
	//Segunda camada

	block = new Block(CAVECONTINUO, 0, 168.0f, 217.0f);
	scene->Add(block, STATIC);

	//Espinhos quarta plataforma
	
	spike = new Spike(140.0f, 225.0f, L);
	scene->Add(spike, STATIC);
	spike = new Spike(140.0f, 209.0f, L);
	scene->Add(spike, STATIC);

	//Quinta plataforma
	block = new Block(CAVESOLO, 0, 24.0f, 120.0f);
	scene->Add(block, STATIC);

	block = new Block(CAVESOLO, 0, 168.0f, 120.0f);
	scene->Add(block, STATIC);

	block = new Block(CAVESOLO, 0, 312.0f, 120.0f);
	scene->Add(block, STATIC);

	//Espinhos quinta plataforma

	//Embaixo
	spike = new Spike(16.0f, 148.0f, B);
	scene->Add(spike, STATIC);
	spike = new Spike(32.0f, 148.0f, B);
	scene->Add(spike, STATIC);

	//Esquerda
	spike = new Spike(140.0f, 112.0f, L);
	scene->Add(spike, STATIC);
	spike = new Spike(140.0f, 128.0f, L);
	scene->Add(spike, STATIC);

	spike = new Spike(284.0f, 112.0f, L);
	scene->Add(spike, STATIC);
	spike = new Spike(284.0f, 128.0f, L);
	scene->Add(spike, STATIC);

	//Direita
	spike = new Spike(196.0f, 112.0f, R);
	scene->Add(spike, STATIC);
	spike = new Spike(196.0f, 128.0f, R);
	scene->Add(spike, STATIC);

	spike = new Spike(340.0f, 112.0f, R);
	scene->Add(spike, STATIC);
	spike = new Spike(340.0f, 128.0f, R);
	scene->Add(spike, STATIC);

	//Sexta plataforma

	block = new Block(CAVESOLO, 1, 520.0f, 120.0f, true, 2);
	scene->Add(block, STATIC);

	block = new Block(CAVESOLO, 3, 568.0f, 120.0f, false, 0);
	scene->Add(block, STATIC);

	//Portal
	Door* portal = new Door(544.0f, 64.0f, CAVE);
	scene->Add(portal, STATIC);

	//Diamantes sobre a primeira
	Diamond* diamond = new Diamond(RED, 192.0f, 350.0f);
	scene->Add(diamond, STATIC);

	diamond = new Diamond(YELLOW, 336.0f, 350.0f);
	scene->Add(diamond, STATIC);

	//Diamentes sobre a quarta plataforma
	diamond = new Diamond(YELLOW, 24.0f, 191.0f);
	scene->Add(diamond, STATIC);

	diamond = new Diamond(RED, 168.0f, 168.0f);
	scene->Add(diamond, STATIC);

	//Diamantes sobre a quinta plataforma
	diamond = new Diamond(RED, 96.0f, 71.0f);
	scene->Add(diamond, STATIC);

	diamond = new Diamond(YELLOW, 240.0f, 71.0f);
	scene->Add(diamond, STATIC);

	diamond = new Diamond(RED, 408.0f, 71.0f);
	scene->Add(diamond, STATIC);

	TreasureHunters::audio->Play(CAVES, true);
}

void Level3_1::Update() {
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
				Level3_2::pegados = player->score;
				TreasureHunters::NextLevel<Level3_2>();
			}
			else {
				mouse->Update();
				pause->Update();
				restart->Update();
				scene->CollisionDetection();
				scene->Update();
				string aux = std::to_string(player->score);
				TreasureHunters::arcade15->Draw(24.0f, 430.0f, "Score: " + aux, { 1.0f, 1.0f, 1.0f, 1.0f }, Layer::FRONT);
			}
		}
		else {
			GameOver::level = 3;
			GameOver::score = (100 * player->score) / 18;
			TreasureHunters::audio->Stop(CAVES);
			TreasureHunters::NextLevel<GameOver>();
		}
	} else {
		string aux = std::to_string(player->score);
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

void Level3_1::Draw() {
	scene->Draw();
	pause->Draw();
	restart->Draw();
	/*Engine::renderer->BeginPixels();

	ulong magenta = (255 << 24) + (255 << 16) + (0 << 8) + 255;

	scene->Begin();
	Object* obj = nullptr;
	while (obj = scene->Next())
	{
		if (obj->bbox)
			Engine::renderer->Draw(obj->bbox, magenta);
	}

	Engine::renderer->EndPixels();*/
}

void Level3_1::Finalize() {
	delete scene;
	delete restart;
	delete mouse;
	delete pause;
}