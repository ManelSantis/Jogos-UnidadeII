#include "Engine.h"
#include "TreasureHunters.h"
#include "Menu.h"
#include "Level2.h"
#include "Block.h"
#include "Diamond.h"
#include "Spike.h"
#include "Score.h"
#include "Background.h"
#include "GameOver.h"
#include "Door.h"

void Level2::Init() {
	scene = new Scene();

	//Mouse e Botões
	mouse = new Mouse();
	pause = new Buttons(594.0f - 22, 424.0f, PAUSE);
	restart = new Buttons(594.0f + 22, 424.0f, RESTART);

	//Player
	player = new Player(24.0f, 350.0f);
	scene->Add(player, MOVING);

	//Background
	Background* bg = new Background(BGFOREST);
	scene->Add(bg, STATIC);

	//Primeira plataforma
	Block* block = new Block(SOLOG, 1, 24.0f, 424.0f, true, 15);
	scene->Add(block, STATIC);

	block = new Block(SOLOG, 2, 72.0f, 424.0f, false, 0);
	scene->Add(block, STATIC);

	block = new Block(SOLOG, 2, 120.0f, 424.0f, false, 0);
	scene->Add(block, STATIC);

	block = new Block(SOLOG, 2, 168.0f, 424.0f, false, 0);
	scene->Add(block, STATIC);

	block = new Block(SOLOG, 2, 216.0f, 424.0f, false, 0);
	scene->Add(block, STATIC);

	block = new Block(SOLOG, 2, 264.0f, 424.0f, false, 0);
	scene->Add(block, STATIC);

	block = new Block(SOLOG, 2, 312.0f, 424.0f, false, 0);
	scene->Add(block, STATIC);

	block = new Block(SOLOG, 2, 360.0f, 424.0f, false, 0);
	scene->Add(block, STATIC);

	block = new Block(SOLOG, 2, 408.0f, 424.0f, false, 0);
	scene->Add(block, STATIC);

	block = new Block(SOLOG, 2, 456.0f, 424.0f, false, 0);
	scene->Add(block, STATIC);

	block = new Block(SOLOG, 2, 504.0f, 424.0f, false, 0);
	scene->Add(block, STATIC);

	block = new Block(SOLOG, 2, 552.0f, 424.0f, false, 0);
	scene->Add(block, STATIC);

	block = new Block(SOLOG, 2, 600.0f, 424.0f, false, 0);
	scene->Add(block, STATIC);

	block = new Block(SOLOG, 3, 648.0f, 424.0f, false, 0);
	scene->Add(block, STATIC);

	//Espinhos sobre primeira plataforma

	Spike* spike = new Spike(120.0f, 396.0f, T);
	scene->Add(spike, STATIC);
	spike = new Spike(136.0f, 396.0f, T);
	scene->Add(spike, STATIC);

	spike = new Spike(464.0f, 396.0f, T);
	scene->Add(spike, STATIC);
	spike = new Spike(480.0f, 396.0f, T);
	scene->Add(spike, STATIC);

	spike = new Spike(560.0f, 396.0f, T);
	scene->Add(spike, STATIC);
	spike = new Spike(576.0f, 396.0f, T);
	scene->Add(spike, STATIC);

	//Segunda plataforma
	block = new Block(SOLOG, 1, 424.0f, 278.0f, true, 5);
	scene->Add(block, STATIC);

	block = new Block(SOLOG, 2, 472.0f, 278.0f, false, 0);
	scene->Add(block, STATIC);

	block = new Block(SOLOG, 2, 520.0f, 278.0f, false, 0);
	scene->Add(block, STATIC);

	block = new Block(SOLOS, 2, 568.0f, 278.0f, false, 0);
	scene->Add(block, STATIC);

	block = new Block(SOLOS, 3, 616.0f, 278.0f, false, 0);
	scene->Add(block, STATIC);

	block = new Block(CONTINUOG, 1, 568.0f, 230.0f, true, 2);
	scene->Add(block, STATIC);

	block = new Block(CONTINUOG, 3, 616.0f, 230.0f, false, 0);
	scene->Add(block, STATIC);
	//Espinhos sobre a segunda plataforma
	//Embaixo
	spike = new Spike(416.0f, 306.0f, B);
	scene->Add(spike, STATIC);
	spike = new Spike(432.0f, 306.0f, B);
	scene->Add(spike, STATIC);

	spike = new Spike(512.0f, 306.0f, B);
	scene->Add(spike, STATIC);
	spike = new Spike(528.0f, 306.0f, B);
	scene->Add(spike, STATIC);

	spike = new Spike(608.0f, 306.0f, B);
	scene->Add(spike, STATIC);
	spike = new Spike(624.0f, 306.0f, B);
	scene->Add(spike, STATIC);

	//Terceira plataforma

	block = new Block(SOLOG, 1, 24.0f, 278.0f, true, 3);
	scene->Add(block, STATIC);

	block = new Block(SOLOG, 2, 72.0f, 278.0f, false, 0);
	scene->Add(block, STATIC);

	block = new Block(SOLOG, 3, 120.0f, 278.0f, false, 0);
	scene->Add(block, STATIC);

	//Quarta plataforma
	block = new Block(SOLOG, 0, 272.0f, 326.0f);
	scene->Add(block, STATIC);

	//Espinhos sobre a quarta plataforma
	//Embaixo
	spike = new Spike(280.0f, 354.0f, B);
	scene->Add(spike, STATIC);

	spike = new Spike(264.0f, 354.0f, B);
	scene->Add(spike, STATIC);

	//Direita
	spike = new Spike(300.0f, 319.0f, R);
	scene->Add(spike, STATIC);

	spike = new Spike(300.0f, 335.0f, R);
	scene->Add(spike, STATIC);

	//Esquerda
	spike = new Spike(244.0f, 319.0f, L);
	scene->Add(spike, STATIC);

	spike = new Spike(244.0f, 335.0f, L);
	scene->Add(spike, STATIC);


	//Quinta plataforma

	block = new Block(SOLOG, 1, 176.0f, 130.0f, true, 5);
	scene->Add(block, STATIC);

	block = new Block(SOLOG, 2, 224.0f, 130.0f, false, 0);
	scene->Add(block, STATIC);

	block = new Block(SOLOG, 2, 272.0f, 130.0f, false, 0);
	scene->Add(block, STATIC);

	block = new Block(SOLOG, 2, 320.0f, 130.0f, false, 0);
	scene->Add(block, STATIC);

	block = new Block(SOLOG, 3, 368.0f, 130.0f, false, 0);
	scene->Add(block, STATIC);

	//Sexta plataforma

	block = new Block(SOLOG, 1, 568.0f, 102.0f, true, 2);
	scene->Add(block, STATIC);

	block = new Block(SOLOG, 3, 616.0f, 102.0f, false, 0);
	scene->Add(block, STATIC);

	//Portal
	Door* portal = new Door(592.0f, 46.0f, PORTAL);
	scene->Add(portal, STATIC);

	//Diamentes sobre a primeira plataforma
	Diamond* diamond = new Diamond(BLUE, 472.0f, 350.0f);
	scene->Add(diamond, STATIC);

	diamond = new Diamond(GREEN, 568.0f, 350.0f);
	scene->Add(diamond, STATIC);

	//Diamantes sobre a terceira plataforma
	diamond = new Diamond(GREEN, 48.0f, 179.0f);
	scene->Add(diamond, STATIC);

	diamond = new Diamond(BLUE, 98.0f, 129.0f);
	scene->Add(diamond, STATIC);

	diamond = new Diamond(GREEN, 148.0f, 79.0f);
	scene->Add(diamond, STATIC);

	//Diamantes sobre a quarta plataforma
	diamond = new Diamond(BLUE, 592.0f, 179.0f);
	scene->Add(diamond, STATIC);

	//Diamante perto do portal
	diamond = new Diamond(BLUE, 469.0f, 56.0f);
	scene->Add(diamond, STATIC);

	TreasureHunters::audio->Play(FOREST, true);
}

void Level2::Update() {
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
		TreasureHunters::NextLevel<Level2>();
	} else if (!pausou) {
		if (player->alive) {
			if (player->nextLevel) {
				TreasureHunters::audio->Stop(FOREST);
				Score::level = 2;
				Score::score = (100 * player->score) / 7;
				TreasureHunters::NextLevel<Score>();
			} else {
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
			GameOver::level = 2;
			GameOver::score = (100 * player->score) / 7;
			TreasureHunters::audio->Stop(FOREST);
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
		TreasureHunters::audio->Stop(FOREST);
		TreasureHunters::NextLevel<Menu>();
	}
}

void Level2::Draw() {
	Color white(1.0f, 1.0f, 1.0f, 1.0f);
	scene->Draw();
	pause->Draw();
	restart->Draw();
	TreasureHunters::arcade15->Draw(150.0f, 278.0f, "Cuidado  com  as  armadilhas", white, Layer::UPPER);

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

void Level2::Finalize() {
	delete mouse;
	delete restart;
	delete pause;
	delete scene;
}