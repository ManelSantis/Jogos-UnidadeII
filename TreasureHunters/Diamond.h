#ifndef _DIAMOND_H_
#define _DIAMOND_H_

#include "Types.h"
#include "Object.h"
#include "Animation.h"

enum DiamondType {BLUE, GREEN, RED, YELLOW};

class Diamond : public Object {
private:
	TileSet* tileset[2];
	Animation* animacao[2];
	TileSet* tAtual;
	Animation* aAtual;
	bool pegou = false;
	
public:

	Diamond(uint tipo, float posx, float posy); //Construtor
	~Diamond(); //Destrutor

	int Catch();
	void Update();
	void Draw();
};



#endif
