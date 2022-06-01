#ifndef _DOOR_H_
#define _DOOR_H_

#include "Types.h"
#include "Object.h"
#include "Sprite.h"

enum Doors { PORTAL, CAVE };

class Door : public Object {

private:
	Sprite* door = nullptr;
	Sprite* doors[3];
	float timeOpen = 0;
	bool open = false;

public:
	Door(float posx, float posy, uint tipo); //Construtor
	~Door(); //Destrutor
	
	bool Open();
	void Open(bool aux);
	void Draw();
	void Update();
};

#endif

