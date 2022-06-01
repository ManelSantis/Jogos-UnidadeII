#include "Engine.h"
#include "TreasureHunters.h"
#include "Menu.h"
#include "Resources.h"

Game* TreasureHunters::level = nullptr;
Audio* TreasureHunters::audio = nullptr;
bool TreasureHunters::viewBBox = false;
Font* TreasureHunters::arcade15 = nullptr;
Font* TreasureHunters::arcade30 = nullptr;
Font* TreasureHunters::arcade55 = nullptr;


void TreasureHunters::Init() {
	audio = new Audio();
	audio->Add(GAMESTART, "Resources/Sounds/Menu.wav");

	audio->Add(BUTTONDOWN, "Resources/Sounds/ButtonDown.wav");
	
	audio->Add(FOREST, "Resources/Sounds/Forest.wav");
	audio->Add(CAVES, "Resources/Sounds/Cave.wav");

	audio->Add(CATCHDIAMOND, "Resources/Sounds/CatchDiamond.wav", 7);

	audio->Add(NEXTLEVEL, "Resources/Sounds/NextLevel.wav");

	audio->Add(JUMP, "Resources/Sounds/Jump.wav");
	audio->Add(DOUBLEJUMP, "Resources/Sounds/DoubleJump.wav");
	audio->Add(PLAYERHIT, "Resources/Sounds/PlayerHit.wav");

	audio->Add(OPENDOOR, "Resources/Sounds/DoorOpen.wav");
	audio->Add(CLOSEDOOR, "Resources/Sounds/DoorClosed.wav");

	audio->Add(GAMEOVER, "Resources/Sounds/GameOver.wav");

	arcade15 = new Font("Resources/Fonts/Arcade15.png");
	arcade15->Spacing("Resources/Fonts/Arcade15.dat");

	arcade30 = new Font("Resources/Fonts/Arcade30.png");
	arcade30->Spacing("Resources/Fonts/Arcade30.dat");

	arcade55 = new Font("Resources/Fonts/Arcade55.png");
	arcade55->Spacing("Resources/Fonts/Arcade55.dat");

	viewBBox = false;
	level = new Menu();
	level->Init();
}

void TreasureHunters::Update() {
	level->Update();
}

void TreasureHunters::Draw() {
	level->Draw();
}

void TreasureHunters::Finalize() {
	level->Finalize();
	delete audio;
	delete arcade15;
	delete arcade30;
	delete arcade55;
	delete level;

}

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	Engine* engine = new Engine();

	// configura janela
	engine->window->Mode(WINDOWED);
	engine->window->Size(640, 448);
	engine->window->Color(30, 50, 80);
	engine->window->Title("Treasure Hunters");
	engine->window->Icon(IDI_ICON);
	//engine->window->Cursor(IDC_CURSOR);

	// configura dispositivo gráfico
	// engine->graphics->VSync(true);

	// inicia o jogo
	int status = engine->Start(new TreasureHunters());

	delete engine;
	return status;
}