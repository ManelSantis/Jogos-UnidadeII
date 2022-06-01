#include "Background.h"

Background::Background(uint tipo) {
	MoveTo(window->CenterX(), window->CenterY(), Layer::BACK);
	typeBg = tipo;

	backgrounds[0] = new Sprite("Resources/Backgrounds/BG-Forest.png");	
	backgrounds[1] = new Sprite("Resources/Backgrounds/BG-Cave0.png");
	backgrounds[2] = new Sprite("Resources/Backgrounds/BG-Cave1.png");
	backgrounds[3] = new Sprite("Resources/Backgrounds/BG-Cave2.png");
	backgrounds[4] = new Sprite("Resources/Backgrounds/BG-Cave3.png");

	if (tipo == BGFOREST) {
		background = backgrounds[0];
	}

	if (tipo == BGCAVE) {
		background = backgrounds[1];
	}

}

Background::~Background() {
	for (int i = 0; i < 5; i++) {
		delete backgrounds[i];
	}
}

void Background::Update() {
	if (typeBg == BGCAVE) {
		timeBtw += 0.025;
		if (timeBtw >= 17.55) {
			if (bgAtual < 4) {
				bgAtual++;
				background = backgrounds[bgAtual];
			} else {
				bgAtual = 1;
				background = backgrounds[bgAtual];
				timeBtw = 0;
			}
			timeBtw = 0;
		}
	}
}

void Background::Draw() {
	background->Draw(x, y, Layer::BACK);
}

// -------------------------------------------------------------------------------
