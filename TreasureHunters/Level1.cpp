#include "Engine.h"
#include "TreasureHunters.h"
#include "Menu.h"
#include "Level1.h"
#include "Score.h"
#include "Block.h"
#include "Diamond.h"
#include "Door.h"
#include "Background.h"

void Level1::Init() {
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

	//Shadow
	//Shadow* shadow = new Shadow(player);
	//scene->Add(shadow, MOVING);

	//Primeira plataforma
	/*Block* block = new Block(SOLOG, 1, 24.0f, 424.0f);
	scene->Add(block, STATIC);

	block = new Block(SOLOG, 2, 72.0f, 424.0f);
	scene->Add(block, STATIC);

	block = new Block(SOLOG, 2, 120.0f, 424.0f);
	scene->Add(block, STATIC);

	block = new Block(SOLOG, 2, 168.0f, 424.0f);
	scene->Add(block, STATIC);

	block = new Block(SOLOG, 2, 216.0f, 424.0f);
	scene->Add(block, STATIC);

	block = new Block(SOLOG, 2, 264.0f, 424.0f);
	scene->Add(block, STATIC);

	block = new Block(SOLOG, 2, 312.0f, 424.0f);
	scene->Add(block, STATIC);

	block = new Block(SOLOG, 2, 360.0f, 424.0f);
	scene->Add(block, STATIC);

	block = new Block(SOLOG, 2, 408.0f, 424.0f);
	scene->Add(block, STATIC);

	block = new Block(SOLOG, 2, 456.0f, 424.0f);
	scene->Add(block, STATIC);

	block = new Block(SOLOG, 2, 504.0f, 424.0f);
	scene->Add(block, STATIC);

	block = new Block(SOLOG, 2, 552.0f, 424.0f);
	scene->Add(block, STATIC);

	block = new Block(SOLOG, 2, 600.0f, 424.0f);
	scene->Add(block, STATIC);

	block = new Block(SOLOG, 3, 648.0f, 424.0f);
	scene->Add(block, STATIC);*/

	Block* block = new Block(SOLOG, 1, 24.0f, 424.0f, true, 14);
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

	//Segunda plataforma
	/*block = new Block(SOLOG, 1, 224.0f, 326.0f);
	scene->Add(block, STATIC);

	block = new Block(SOLOG, 2, 272.0f, 326.0f);
	scene->Add(block, STATIC);

	block = new Block(SOLOG, 2, 320.0f, 326.0f);
	scene->Add(block, STATIC);

	block = new Block(SOLOG, 2, 368.0f, 326.0f);
	scene->Add(block, STATIC);

	block = new Block(SOLOG, 3, 416.0f, 326.0f);
	scene->Add(block, STATIC);*/

	block = new Block(SOLOG, 1, 224.0f, 326.0f, true, 5);
	scene->Add(block, STATIC);

	block = new Block(SOLOG, 2, 272.0f, 326.0f, false, 0);
	scene->Add(block, STATIC);

	block = new Block(SOLOG, 2, 320.0f, 326.0f, false, 0);
	scene->Add(block, STATIC);

	block = new Block(SOLOG, 2, 368.0f, 326.0f, false, 0);
	scene->Add(block, STATIC);

	block = new Block(SOLOG, 3, 416.0f, 326.0f, false, 0);
	scene->Add(block, STATIC);

	//Terceira plataforma
	/*block = new Block(SOLOG, 1, 24.0f, 228.0f);
	scene->Add(block, STATIC);

	block = new Block(SOLOG, 3, 72.0f, 228.0f);
	scene->Add(block, STATIC);*/

	block = new Block(SOLOG, 1, 24.0f, 228.0f, true, 2);
	scene->Add(block, STATIC);

	block = new Block(SOLOG, 3, 72.0f, 228.0f, false, 0);
	scene->Add(block, STATIC);

	//Quarta plataforma
	/*block = new Block(SOLOG, 1, 568.0f, 228.0f);
	scene->Add(block, STATIC);

	block = new Block(SOLOG, 3, 616.0f, 228.0f);
	scene->Add(block, STATIC);*/

	block = new Block(SOLOG, 1, 568.0f, 228.0f, true, 2);
	scene->Add(block, STATIC);

	block = new Block(SOLOG, 3, 616.0f, 228.0f, false, 0);
	scene->Add(block, STATIC);


	//Quinta plataforma
	/*block = new Block(SOLOG, 1, 224.0f, 130.0f);
	scene->Add(block, STATIC);

	block = new Block(SOLOG, 2, 272.0f, 130.0f);
	scene->Add(block, STATIC);

	block = new Block(SOLOG, 2, 320.0f, 130.0f);
	scene->Add(block, STATIC);

	block = new Block(SOLOG, 2, 368.0f, 130.0f);
	scene->Add(block, STATIC);

	block = new Block(SOLOG, 3, 416.0f, 130.0f);
	scene->Add(block, STATIC);*/

	block = new Block(SOLOG, 1, 224.0f, 130.0f, true, 5);
	scene->Add(block, STATIC);

	block = new Block(SOLOG, 2, 272.0f, 130.0f, false, 0);
	scene->Add(block, STATIC);

	block = new Block(SOLOG, 2, 320.0f, 130.0f, false, 0);
	scene->Add(block, STATIC);

	block = new Block(SOLOG, 2, 368.0f, 130.0f, false, 0);
	scene->Add(block, STATIC);

	block = new Block(SOLOG, 3, 416.0f, 130.0f, false, 0);
	scene->Add(block, STATIC);

	//Portal
	Door* portal = new Door(320.0f, 74.0f, PORTAL);
	scene->Add(portal, STATIC);

	//Diamentes sobre a primeira plataforma
	Diamond* diamond = new Diamond(BLUE, 219.0f, 375.0f);
	scene->Add(diamond, STATIC);

	diamond = new Diamond(BLUE, 319.0f, 375.0f);
	scene->Add(diamond, STATIC);

	diamond = new Diamond(BLUE, 419.0f, 375.0f);
	scene->Add(diamond, STATIC);

	//Diamantes sobre a segunda plataforma
	diamond = new Diamond(GREEN, 269.0f, 277.0f);
	scene->Add(diamond, STATIC);

	diamond = new Diamond(GREEN, 369.0f, 277.0f);
	scene->Add(diamond, STATIC);

	//Diamantes sobre a terceira plataforma
	diamond = new Diamond(BLUE, 48.0f, 179.0f);
	scene->Add(diamond, STATIC);

	//Diamantes sobre a quarta plataforma
	diamond = new Diamond(GREEN, 592.0f, 179.0f);
	scene->Add(diamond, STATIC);

	//Diamantes sobre a quinta plataforma
	diamond = new Diamond(GREEN, 219.0f, 81.0f);
	scene->Add(diamond, STATIC);

	diamond = new Diamond(BLUE, 419.0f, 81.0f);
	scene->Add(diamond, STATIC);

	TreasureHunters::audio->Play(FOREST, true);
}

void Level1::Update() {

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
		TreasureHunters::NextLevel<Level1>();
	} else if (!pausou){
		 if (player->nextLevel) {
			TreasureHunters::audio->Stop(FOREST);
			Score::level = 1;
			Score::score = (100 * player->score) / 9;
			TreasureHunters::NextLevel<Score>();
		 }
		 else {
			 mouse->Update();
			 pause->Update();
			 restart->Update();
			 scene->CollisionDetection();
			 scene->Update();
			 string aux = std::to_string(player->score);
			 TreasureHunters::arcade15->Draw(24.0f, 430.0f, "Score: " + aux, {1.0f, 1.0f, 1.0f, 1.0f}, Layer::FRONT);
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

void Level1::Draw() {
	Color white(1.0f, 1.0f, 1.0f, 1.0f);

	TreasureHunters::arcade15->Draw(140.0f, 25.0f, "Chegue  em  uma  porta   e   use  'F'  para  entrar", white, Layer::UPPER);

	TreasureHunters::arcade15->Draw(15.0f, 277.0f, "Use   'W'  junto  de  'A'  ou  'D'", white, Layer::UPPER);
	TreasureHunters::arcade15->Draw(15.0f, 293.0f, "para  poder  pular  ate  2x", white, Layer::UPPER);
	TreasureHunters::arcade15->Draw(15.0f, 308.0f, "no  chao  ou  no  ar", white, Layer::UPPER);

	TreasureHunters::arcade15->Draw(216.0f, 424.0f, "Use   'A'  ou  'D'  para  correr");

	TreasureHunters::arcade15->Draw(236.0f, 326.0f, "Pegue  os  diamantes");


	scene->Draw();
	pause->Draw();
	restart->Draw();
	/*Engine::renderer->BeginPixels();

	ulong magenta = (255 << 24) + (255 << 16) + (0 << 8) + 255;

	//scene->Begin();
	//Object* obj = nullptr;
	//while (obj = scene->Next())
	//{
		//if (obj->BBox())
			Engine::renderer->Draw(pause->BBox(), magenta);
	//}

	Engine::renderer->EndPixels();*/
}

void Level1::Finalize() {
	delete scene;
	delete restart;
	delete mouse;
	delete pause;
}