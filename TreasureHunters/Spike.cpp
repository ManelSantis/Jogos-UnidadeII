#include "TreasureHunters.h"
#include "Spike.h"

Spike::Spike(float posx, float posy, uint tipo) {

	if (tipo == T) {
		spike = new Sprite("Resources/Traps/SpikesT.png");
		BBox(new Rect(-8, -4, 8, 4));
	}

	if (tipo == B) {
		spike = new Sprite("Resources/Traps/SpikesB.png");
		BBox(new Rect(-8, -4, 8, 4));
	}

	if (tipo == R) {
		spike = new Sprite("Resources/Traps/SpikesR.png");
		BBox(new Rect(-4, -8, 4, 8));
	}

	if (tipo == L) {
		spike = new Sprite("Resources/Traps/SpikesL.png");
		BBox(new Rect(-4, -8, 4, 8));
	}
	
	MoveTo(posx, posy);
	type = TRAP;
}

Spike::~Spike() {
	delete spike;
}

void Spike::Draw() {
	spike->Draw(x, y, Layer::MIDDLE);
}

void Spike::Update() {

}