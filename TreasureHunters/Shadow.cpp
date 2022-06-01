#include "Shadow.h"

Shadow::Shadow(Player* player, uint tipo) {
	Shadow::player = player;

	typeS = tipo;

	shadow[0] = new Sprite("Resources/Shadow0.png");
	shadow[1] = new Sprite("Resources/Shadow1.png");
	shadow[2] = new Sprite("Resources/Shadow2.png");
	shadow[3] = new Sprite("Resources/Shadow3.png");
	shadow[4] = new Sprite("Resources/Shadow4.png");

	fog[0] = new Sprite("Resources/Fog0.png");
	fog[1] = new Sprite("Resources/Fog1.png");
	fog[2] = new Sprite("Resources/Fog2.png");
	fog[3] = new Sprite("Resources/Fog3.png");
	fog[4] = new Sprite("Resources/Fog4.png");

	if (tipo == SHADOW) {
		sprite = shadow[0];
		MoveTo(Shadow::player->X(), Shadow::player->Y());
	}

	if (tipo == FOG) {
		sprite = fog[0];
		MoveTo(window->Width() / 2.0f, window->Height() / 2.0f);
	}

	
}

Shadow::~Shadow() {
	for (int i = 0; i < 5; i++) {
		delete shadow[i];
		delete fog[i];
	}
}

void Shadow::Update() {

	if (typeS == FOG) {
		timeBtw += 0.025f;
		if (timeBtw >= 20) {
			if (sAtual < 4) {
				sAtual++;
				sprite = fog[sAtual];
			}
			else {
				sAtual = 0;
				sprite = fog[sAtual];
				timeBtw = 0;
			}
			timeBtw = 0;
		}
	} else {
		timeBtw += 0.025f;
		if (timeBtw >= 20) {
			if (sAtual < 4) {
				sAtual++;
				sprite = shadow[sAtual];
			}
			else {
				sAtual = 0;
				sprite = shadow[sAtual];
				timeBtw = 0;
			}
			timeBtw = 0;
		}
		MoveTo(player->X(), player->Y());
	}


}

void Shadow::Draw() {
	sprite->Draw(x, y, Layer::UPPER);
}