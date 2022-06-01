#include "TreasureHunters.h"
#include "Saw.h"

Saw::Saw(float posx, float posy, int blocos) {

	if (blocos == 0) {
		tipo = IDDLE;
		velX = 0;
	}
	else {
		tipo = MOVE;
		velX = 80;
		xInit = posx;
		xEnd = posx + (blocos * 48);
	}

	tilesets[0] = new TileSet("Resources/Traps/SawLeft.png", 38, 38, 8, 8);
	animacoes[0] = new Animation(tilesets[0], 0.035f, true);
	tilesets[1] = new TileSet("Resources/Traps/SawRight.png", 38, 38, 8, 8);
	animacoes[1] = new Animation(tilesets[1], 0.035f, true);

	BBox(new Circle(19));

	aAtual = animacoes[0];
	type = TRAP;

	MoveTo(posx, posy);

}

Saw::~Saw() {
	for (int i = 0; i < 2; i++) {
		delete animacoes[i];
		delete tilesets[i];
	}
}

void Saw::Update() {
	aAtual->NextFrame();
	Translate(velX * gameTime, 0);

	if (tipo == MOVE) {
		if (X() >= xEnd) {
			velX = -velX;
			aAtual = animacoes[1];
		}
		
		if (X() <= xInit) {
			velX = -velX;
			aAtual = animacoes[0];
		}
	}
}

void Saw::Draw() {
	aAtual->Draw(x, y, Layer::LOWER);
}