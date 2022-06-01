#include "Engine.h"
#include "TreasureHunters.h"
#include "Menu.h"
#include "Level3_1.h"
#include "Level3_2.h"
#include "Level3_3.h"
#include "Block.h"
#include "Diamond.h"
#include "Spike.h"
#include "Shadow.h"
#include "Background.h"
#include "GameOver.h"
#include "Door.h"

int Level3_2::pegados = NULL;

void Level3_2::Init() {
	scene = new Scene();

	//Mouse e Botões
	mouse = new Mouse();
	pause = new Buttons(594.0f - 22, 424.0f, PAUSE);
	restart = new Buttons(594.0f + 22, 424.0f, RESTART);

	//Player
	player = new Player(24.0f, 46.0f);
	scene->Add(player, MOVING);

	//Background
	Background* bg = new Background(BGCAVE);
	scene->Add(bg, STATIC);

	//Sombra
	Shadow* shadow = new Shadow(player, SHADOW);
	scene->Add(shadow, STATIC);

	//Primeira plataforma
	Block* block = new Block(CAVESOLO, 0, 24.0f, 120.0f);
	scene->Add(block, STATIC);

	block = new Block(CAVESOLO, 0, 168.0f, 120.0f);
	scene->Add(block, STATIC);

	block = new Block(CAVESOLO, 0, 312.0f, 120.0f);
	scene->Add(block, STATIC);

	block = new Block(CAVESOLO, 0, 456.0f, 120.0f);
	scene->Add(block, STATIC);

	//Espinhos primeira plataforma

	//Esquerda
	Spike* spike = new Spike(140.0f, 112.0f, L);
	scene->Add(spike, STATIC);
	spike = new Spike(140.0f, 128.0f, L);
	scene->Add(spike, STATIC);

	spike = new Spike(284.0f, 112.0f, L);
	scene->Add(spike, STATIC);
	spike = new Spike(284.0f, 128.0f, L);
	scene->Add(spike, STATIC);

	spike = new Spike(428.0f, 112.0f, L);
	scene->Add(spike, STATIC);
	spike = new Spike(428.0f, 128.0f, L);
	scene->Add(spike, STATIC);

	//Direita
	spike = new Spike(52.0f, 112.0f, R);
	scene->Add(spike, STATIC);
	spike = new Spike(52.0f, 128.0f, R);
	scene->Add(spike, STATIC);

	spike = new Spike(196.0f, 112.0f, R);
	scene->Add(spike, STATIC);
	spike = new Spike(196.0f, 128.0f, R);
	scene->Add(spike, STATIC);

	spike = new Spike(340.0f, 112.0f, R);
	scene->Add(spike, STATIC);
	spike = new Spike(340.0f, 128.0f, R);
	scene->Add(spike, STATIC);

	spike = new Spike(484.0f, 112.0f, R);
	scene->Add(spike, STATIC);
	spike = new Spike(484.0f, 128.0f, R);
	scene->Add(spike, STATIC);

	//Segunda plataforma

	block = new Block(CAVESOLO, 1, 24.0f, 217.0f, true, 11);
	scene->Add(block, STATIC);

	block = new Block(CAVESOLO, 2, 72.0f, 217.0f, false, 0);
	scene->Add(block, STATIC);

	block = new Block(CAVESOLO, 2, 120.0f, 217.0f, false, 0);
	scene->Add(block, STATIC);

	block = new Block(CAVESOLO, 2, 168.0f, 217.0f, false, 0);
	scene->Add(block, STATIC);

	block = new Block(CAVESOLO, 2, 216.0f, 217.0f, false, 0);
	scene->Add(block, STATIC);

	block = new Block(CAVESOLO, 2, 264.0f, 217.0f, false, 0);
	scene->Add(block, STATIC);

	block = new Block(CAVESOLO, 2, 312.0f, 217.0f, false, 0);
	scene->Add(block, STATIC);

	block = new Block(CAVESOLO, 2, 360.0f, 217.0f, false, 0);
	scene->Add(block, STATIC);

	block = new Block(CAVESOLO, 2, 408.0f, 217.0f, false, 0);
	scene->Add(block, STATIC);

	block = new Block(CAVESOLO, 2, 456.0f, 217.0f, false, 0);
	scene->Add(block, STATIC);

	block = new Block(CAVESOLO, 3, 504.0f, 217.0f, false, 0);
	scene->Add(block, STATIC);

	//Espinhos Segunda plataforma

	float aux = 8.0f;
	spike = new Spike(aux, 189.0f, T);
	scene->Add(spike, STATIC);

	for (int i = 1; i <= 32; i++) {
		aux += 16;
		spike = new Spike(aux, 189.0f, T);
		scene->Add(spike, STATIC);
	}

	aux = 8.0f;
	spike = new Spike(aux, 245.0f, B);
	scene->Add(spike, STATIC);

	for (int i = 1; i <= 32; i++) {
		aux += 16;
		spike = new Spike(aux, 245.0f, B);
		scene->Add(spike, STATIC);
	}

	//Terceira plataforma

	block = new Block(CAVESOLO, 1, 552.0f, 424.0f, true, 3);
	scene->Add(block, STATIC);

	block = new Block(CAVESOLO, 2, 600.0f, 424.0f, false, 0);
	scene->Add(block, STATIC);

	block = new Block(CAVESOLO, 3, 648.0f, 424.0f, false, 0);
	scene->Add(block, STATIC);

	//Quarta plataforma

	block = new Block(CAVESOLO, 0, 408.0f, 376.0f);
	scene->Add(block, STATIC);

	//Quinta plataforma

	block = new Block(CAVESOLO, 1, 216.0f, 376.0f, true, 2);
	scene->Add(block, STATIC);

	block = new Block(CAVESOLO, 3, 264.0f, 376.0f, false, 0);
	scene->Add(block, STATIC);
	
	//Sexta plataforma

	block = new Block(CAVESOLO, 1, 24.0f, 424.0f, true, 2);
	scene->Add(block, STATIC);

	block = new Block(CSSOLO, 3, 72.0f, 424.0f, false, 0);
	scene->Add(block, STATIC);

	//Segunda camada
	block = new Block(CSCONTINUO, 3, 72.0f, 376.0f);
	scene->Add(block, STATIC);

	//Terceira caamda
	block = new Block(CAVECONTINUO, 0, 72.0f, 328.0f);
	scene->Add(block, STATIC);

	//Portal
	Door* portal = new Door(24.0f, 368.0f, CAVE);
	scene->Add(portal, STATIC);

	//Diamantes sobre a primeira plataforma
	Diamond* diamond = new Diamond(YELLOW, 96.0f, 71.0f);
	scene->Add(diamond, STATIC);

	diamond = new Diamond(RED, 240.0f, 71.0f);
	scene->Add(diamond, STATIC);

	diamond = new Diamond(YELLOW, 384.0f, 71.0f);
	scene->Add(diamond, STATIC);

	//Diamantes sobre segunda plataforma
	diamond = new Diamond(RED, 588.0f, 120.0f);
	scene->Add(diamond, STATIC);

	diamond = new Diamond(YELLOW, 588.0f, 217.0f);
	scene->Add(diamond, STATIC);

	//Diamantes area de baixo
	diamond = new Diamond(RED, 336.0f, 352.0f);
	scene->Add(diamond, STATIC);

	diamond = new Diamond(YELLOW, 144.0f, 352.0f);
	scene->Add(diamond, STATIC);

}

void Level3_2::Update() {
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
				Level3_3::pegados = player->score + pegados;
				TreasureHunters::NextLevel<Level3_3>();
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

void Level3_2::Draw() {
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

void Level3_2::Finalize() {
	delete scene;
	delete restart;
	delete mouse;
	delete pause;
}