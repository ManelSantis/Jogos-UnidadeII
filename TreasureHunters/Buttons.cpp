#include "TreasureHunters.h"
#include "Buttons.h"

Buttons::Buttons(float posx, float posy, uint tipo) {

	if (tipo == RESTART) {
		button = new Sprite("Resources/Buttons/RestartUp.png");
		sobre = new Sprite("Resources/Buttons/RestartDown.png");
		BBox(new Rect(-18, -21, 18, 21));
	}

	if (tipo == NEXT) {
		button = new Sprite("Resources/Buttons/NextUp.png");
		sobre = new Sprite("Resources/Buttons/NextDown.png");
		BBox(new Rect(-18, -21, 18, 21));
	}

	if (tipo == MENU) {
		button = new Sprite("Resources/Buttons/MenuUp.png");
		sobre = new Sprite("Resources/Buttons/MenuDown.png");
		BBox(new Rect(-18, -21, 18, 21));
	}

	if (tipo == PLAY) {
		button = new Sprite("Resources/Buttons/PlayUp.png");
		sobre = new Sprite("Resources/Buttons/PlayDown.png");
		BBox(new Rect(-77, -53, 77, 53));
	}

	if (tipo == PAUSE) {
		button = new Sprite("Resources/Buttons/PauseUp.png");
		sobre = new Sprite("Resources/Buttons/PauseDown.png");
		BBox(new Rect(-18, -21, 18, 21));
	}

	atual = button;

	MoveTo(posx, posy);

}

Buttons::~Buttons() {
	delete button;
	delete sobre;
}

void Buttons::Update() {

	if (mouseOver) {
		atual = sobre; 
	} else if (!mouseOver) {
		atual = button;
	}
}

void Buttons::Draw() {
	atual->Draw(x, y, Layer::FRONT);
}

bool Buttons::MouseOver(bool aux) {
	mouseOver = aux;
	return mouseOver;
}

bool Buttons::MouseOver() {
	return mouseOver;
}