#ifndef _SHADOW_H_
#define _SHADOW_H_

#include "Types.h"
#include "Object.h"
#include "Sprite.h"
#include "Player.h"

enum ShadowType {SHADOW, FOG};

class Shadow : public Object {
private:
	Sprite* shadow[5];
	Sprite* fog[5];
	Sprite* sprite = nullptr;
	Player* player;

	float timeBtw = 0;
	int sAtual = 0;
	uint typeS;

public:
	Shadow(Player* player, uint tipo);//Construdor
	~Shadow();//Destrutor

	void Update();
	void Draw();
};

#endif