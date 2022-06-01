#ifndef _BACKGROUND_H_
#define _BACKGROUND_H_

#include "Types.h"
#include "Object.h"
#include "Sprite.h"
enum Backgrounds {BGFOREST, BGCAVE};

class Background : public Object
{
private:
	Sprite* backgrounds[5];
	Sprite* background;
	float timeBtw = 0;
	int bgAtual = 1;
	uint typeBg;

public:
	Background(uint tipo);//Construtor
	~Background();//Destrutor

	void Update();
	void Draw();
};

#endif