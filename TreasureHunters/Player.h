#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Types.h"
#include "Object.h"
#include "Animation.h"
#include "Vector.h"

enum PlayerDirection{RIGHT, LEFT, UP, RIGHTUP, LEFTUP};

class Player : public Object {
private:
	TileSet* tileset[8];
	Animation* animacao[8];
	TileSet* tsAtual;
	Animation* aAtual;

	float timeMidAir = 0;

	int direction = 0;

	Vector speed;
	Vector height;
	Vector direcao;

	Rect* antiga = nullptr;

	float antigoT, antigoB, antigoL, antigoR;

	bool run = false;
	bool onAir = false;
	bool onCollision = false;
	bool jumping = false;
	
	float velx = 150;
	float vely = 100;
	float velX = 0;
	float velY = 0;

	float gravidade = 200;

public:

	int score = 0;
	bool alive = true;
	bool nextLevel = false;

	Player(float posx, float posy); //Construtor
	~Player(); //Destrutor

	void CalcularValores();

	void OnCollision(Object* obj);
	void NotCollision();
	void Update();
	void Draw();
};


#endif