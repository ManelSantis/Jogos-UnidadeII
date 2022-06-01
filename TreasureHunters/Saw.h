#ifndef _SAW_H_
#define _SAW_H_

#include "Types.h"
#include "Object.h"
#include "Animation.h"
#include "TileSet.h"

enum Saws { MOVE, IDDLE };

class Saw : public Object {

private:
	Animation* animacoes[2];
	TileSet* tilesets[2];
	uint tipo;
	Animation* aAtual = nullptr;
	float velX = 0;
	float xInit = 0, xEnd = 0;

public:
	Saw(float posx, float posy, int blocos); //Construtor Iddle
	~Saw(); //Destrutor

	void Draw();
	void Update();
};

#endif
