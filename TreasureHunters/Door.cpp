#include "TreasureHunters.h"
#include "Door.h"

Door::Door(float posx, float posy, uint tipo) {
	doors[0] = new Sprite("Resources/Doors/DoorClosed.png");
	doors[1] = new Sprite("Resources/Doors/DoorOpen.png");
	doors[2] = new Sprite("Resources/Doors/CaveDoor.png");

	if (tipo == PORTAL) {
		door = doors[0];
		BBox(new Rect(-22, -32, 22, 32));
		type = LVLUP;
	}

	if (tipo == CAVE) {
		door = doors[2];
		BBox(new Rect(-24, -32, 24, 32));
		type = NEXTCAVE;
	}

	MoveTo(posx, posy);
}

Door::~Door() {
	TreasureHunters::audio->Stop(CLOSEDOOR);
	TreasureHunters::audio->Stop(OPENDOOR);
	for (int i = 0; i < 3; i++) {
		delete doors[i];
	}
}

void Door::Update() {

	if (type == LVLUP) {
		if (open) {
			door = doors[1];
			timeOpen += 0.025f;
		} else if (!open) {
			door = doors[0];
		}
	}
	
	if (timeOpen >= 25.0f && open) {
		TreasureHunters::audio->Play(CLOSEDOOR);
		timeOpen = 0.0f;
		open = false;
	}
}

bool Door::Open() {
	return open;
}

void Door::Open(bool aux) {
	open = aux;
}

void Door::Draw() {
	door->Draw(x, y, Layer::MIDDLE);
}