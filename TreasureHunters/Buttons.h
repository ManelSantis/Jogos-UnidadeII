#ifndef _BUTTONS_H_
#define _BUTTONS_H_

#include "Types.h"
#include "Object.h"
#include "Sprite.h"

enum TypeButtons { PLAY, PAUSE, RESTART, MENU, NEXT};

class Buttons : public Object {

private:
	Sprite* button = nullptr;
	Sprite* sobre = nullptr;
	Sprite* atual = nullptr;
	bool mouseOver = false;
	bool startSound = true;
	
public:

	Buttons(float posx, float posy, uint tipo); //Construtor
	~Buttons(); //Destrutor

	bool MouseOver(bool aux);
	bool MouseOver();
	void Draw();
	void Update();

};

#endif
