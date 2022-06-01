#include "Diamond.h"
#include "TreasureHunters.h"

Diamond::Diamond(uint tipo, float posx, float posy) {

	if (tipo == BLUE) {
		tileset[0] = new TileSet("Resources/Diamonds/BlueDiamond.png", 24, 24, 4, 4);
	}

	if (tipo == GREEN) {
		tileset[0] = new TileSet("Resources/Diamonds/GreenDiamond.png", 24, 24, 4, 4);
	}

	if (tipo == RED) {
		tileset[0] = new TileSet("Resources/Diamonds/RedDiamond.png", 24, 24, 4, 4);
	}

	if (tipo == YELLOW) {
		tileset[0] = new TileSet("Resources/Diamonds/YellowDiamond.png", 24, 24, 4, 4);
	}

	tileset[1] = new TileSet("Resources/Diamonds/DiamondEffect.png", 24, 24, 5, 5);

	BBox(new Rect(-6, -6, 6, 6));
	animacao[0] = new Animation(tileset[0], 0.1f, true);
	animacao[1] = new Animation(tileset[1], 0.1f, false);
	aAtual = animacao[0];
	MoveTo(posx, posy);
	type = DIAMOND;
}

Diamond::~Diamond() {
	TreasureHunters::audio->Stop(CATCHDIAMOND);
	for (int i = 0; i < 2; i++) {
		delete animacao[i];
		delete tileset[i];
	}
}

void Diamond::Update() {
	aAtual->NextFrame();
}

int Diamond::Catch() {
	if (!pegou) {
		TreasureHunters::audio->Play(CATCHDIAMOND);
		pegou = true;
		return 1;
	}
	
	aAtual = animacao[1];
	return 0;
}

void Diamond::Draw() {
	aAtual->Draw(x, y, Layer::MIDDLE);
}