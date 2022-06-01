#ifndef _SPIKE_H_
#define _SPIKE_H_

#include "Types.h"
#include "Object.h"
#include "Sprite.h"

enum Spikes {T, B, L, R};

class Spike : public Object {

private:
	Sprite* spike = nullptr;
public:
	Spike(float posx, float posy, uint tipo); //Construtor
	~Spike(); //Destrutor

	void Draw();
	void Update();
};

#endif

