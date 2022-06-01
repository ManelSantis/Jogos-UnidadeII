#ifndef _BLOCK_H_
#define _BLOCK_H_

#include "Types.h"
#include "Object.h"
#include "Sprite.h"

enum Blocks {SOLOG, CONTINUOG, SOLOS, CONTINUOS,
	CAVESOLO, CAVECONTINUO, CSSOLO, CSCONTINUO};

class Block : public Object {

private:
	Sprite* block = nullptr;
public:
	Block(uint tipo, uint ordem, float posx, float posy); //Construtor
	Block(uint tipo, uint ordem, float posx, float posy, bool terBbox, uint tamanho);
	~Block(); //Destrutor

	void Draw();
	void Update();
};

#endif
