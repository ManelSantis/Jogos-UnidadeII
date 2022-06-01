#include "Player.h"
#include "Diamond.h"
#include "TreasureHunters.h"
#include "Door.h"

Player::Player(float posx, float posy) {

	tileset[0] = new TileSet("Resources/Player/IdleRight.png", 32, 32, 11, 11);
	animacao[0] = new Animation(tileset[0], 0.1f, true);

	tileset[1] = new TileSet("Resources/Player/IdleLeft.png", 32, 32, 11, 11);
	animacao[1] = new Animation(tileset[1], 0.1f, true);

	tileset[2] = new TileSet("Resources/Player/RunRight.png", 32, 32, 11, 11);
	animacao[2] = new Animation(tileset[2], 0.1f, true);

	tileset[3] = new TileSet("Resources/Player/RunLeft.png", 32, 32, 11, 11);
	animacao[3] = new Animation(tileset[3], 0.1f, true);

	tileset[4] = new TileSet("Resources/Player/JumpRight.png", 32, 32, 1, 1);
	animacao[4] = new Animation(tileset[4], 0.1f, true);

	tileset[5] = new TileSet("Resources/Player/JumpLeft.png", 32, 32, 1, 1);
	animacao[5] = new Animation(tileset[5], 0.1f, true);

	tileset[6] = new TileSet("Resources/Player/DoubleJumpRight.png", 32, 32, 7, 7);
	animacao[6] = new Animation(tileset[6], 0.1f, true);

	tileset[7] = new TileSet("Resources/Player/DoubleJumpLeft.png", 32, 32, 7, 7);
	animacao[7] = new Animation(tileset[7], 0.1f, true);

	speed.RotateTo(270.0f);
	speed.ScaleTo(0.0f);

	tsAtual = tileset[0];
	aAtual = animacao[0];
	BBox (new Rect(-10, -12, 10, 15));

	type = PLAYER;
	velY = vely;
	MoveTo(posx, posy);

	antiga = (Rect*)BBox();
	antigoT = antiga->Top();
	antigoB = antiga->Bottom();
	antigoL = antiga->Left();
	antigoR = antiga->Right();
}

Player::~Player() {

	//delete tsAtual;
	//delete aAtual;

	for (int i = 0; i < 8; i++) {
		delete animacao[i];
		delete tileset[i];
	}

	
}

void Player::CalcularValores() {
	
	//velx = (150 * gameTime) / 60;
	//vely = (100 * gameTime) / 60;
	//gravidade = (500 * gameTime) / 60;

	velx = (150.0f * gameTime ) / 0.017f;
	vely = (100.0f * gameTime ) / 0.017f;
	gravidade = (200.0f * gameTime ) / 0.017f;

}

void Player::Update() {

	//CalcularValores();

	Vector gravi{ 270.0f, 100.0f * gameTime };
	speed.Add(gravi);

	antiga = (Rect*)BBox();

	antigoT = antiga->Top();
	antigoB = antiga->Bottom();
	antigoL = antiga->Left();
	antigoR = antiga->Right();

	if (window->KeyDown('D') && !onAir) {
		tsAtual = tileset[2];
		aAtual = animacao[2];
		velX = velx;
		direction = RIGHT;
		run = true;
	}

	if (window->KeyPress('D') && onAir) {
		aAtual = animacao[4];
	}

	if (window->KeyDown('D') && onAir) {
		velX = velx - 30;
	}

	if (window->KeyDown('A') && !onAir) {
		tsAtual = tileset[3];
		aAtual = animacao[3];
		velX = -velx;
		direction = LEFT;
		run = true;
	}

	if (window->KeyPress('A') && onAir) {
		aAtual = animacao[5];
	}

	if (window->KeyDown('A') && onAir) {
		velX = -velx + 30;
	}

	if (window->KeyPress('W')) {
		if (!onAir) {
			TreasureHunters::audio->Play(JUMP);
			if (direction == RIGHT) {
				aAtual = animacao[4];
			}

			if (direction == LEFT) {
				aAtual = animacao[5];
			}
			
			velY = -vely;

			direction = UP;
			run = false;
			onAir = true;
			jumping = true;

		} else if (jumping) {

			TreasureHunters::audio->Play(DOUBLEJUMP);
			if (aAtual == animacao[4]) {
				aAtual = animacao[6];
			}

			if (aAtual == animacao[5]) {
				aAtual = animacao[7];
			}

			velY = -vely;
			timeMidAir = 0.0f;
			jumping = false;
		}
	}
	
	if (window->KeyUp('D') && window->KeyUp('A') && window->KeyUp('W') && direction != UP) {

		if (direction == RIGHT) {
	 		tsAtual = tileset[0];
			aAtual = animacao[0];
		}

		if (direction == LEFT) {
			tsAtual = tileset[1];
			aAtual = animacao[1];
		}

		//velY = vely;
		velX = 0;
		run = false;
		onAir = true;
	}

	//if (jumping) {

	timeMidAir += 0.0085f;

	speed.RotateTo(0.0f);
	speed.ScaleTo(velX * gameTime);

	speed.Add(gravi);


	velY = velY + timeMidAir * gravidade * gameTime;

	height.RotateTo(90.0f);
	height.ScaleTo(velY * gameTime);
	height.Add(gravi);

	Translate(speed.XComponent(), height.YComponent());

	if (!onAir) {
		timeMidAir = 0.0f;
	}
	
		/*distance--;
		if (distance == 0) {
			distance = sizeJump * 4;
			jumping = false;
			fallingFromJump = true;
			falling = true;
		}
	} else {
		velY = 150;
		Translate(velX * gameTime, velY * gameTime);
	} */

	//onCollision = false;

	if (x >= 630) {
		MoveTo(629, y);
	}

	if (x <= 12) {
		MoveTo(13, y);
	}

	 if (y >= 450) {
		 TreasureHunters::audio->Stop(DIAMOND);
		 TreasureHunters::audio->Stop(JUMP);
		 TreasureHunters::audio->Stop(DOUBLEJUMP);
		 TreasureHunters::audio->Play(PLAYERHIT);
		 Sleep(700);
		 alive = false;
	}

	if (y <= 16) {
		velY = vely;
		MoveTo(x, 17);
	}

	aAtual->NextFrame();
}

void Player::OnCollision(Object* obj){

	if (obj->Type() == BLOCK) {
		Rect* aux = (Rect*) obj->BBox();
		Rect* atual = (Rect*) BBox();

		bool colidirTop = antigoB < aux->Top() && atual->Bottom() >= aux->Top();
		bool colidirBot = antigoT >= aux->Bottom() && atual->Top() < aux->Bottom();
		bool colidirLeft = antigoR < aux->Left() && atual->Right() >= aux->Left();
		bool colidirRight = antigoL >= aux->Right() && atual->Left() < aux->Right();

		if (colidirBot) {
			velY = vely;
			MoveTo(x, aux->Bottom() + 16);
		}

		if (colidirTop) {
			//velY = 0;
			if (velX > 0) {
				direction = RIGHT;
			}
			else if (velX < 0) {
				direction = LEFT;
			} else {
				if (aAtual == animacao[6] || aAtual == animacao[4]) {
					direction = RIGHT;
				}
				else if (aAtual == animacao[7] || aAtual == animacao[5]) {
					direction = LEFT;
				}
			}

			velX = 0;
			onAir = false;
			jumping = false;
			timeMidAir = 0;
			MoveTo(x, aux->Top() - 16);
		}

		if (colidirLeft) {
			if (aAtual == animacao[6] || aAtual == animacao[4]) {
				aAtual = animacao[4];
			}
			else if (aAtual == animacao[7] || aAtual == animacao[5]) {
				aAtual = animacao[5];
			}
			MoveTo(aux->Left() - 13, y);
			velX = 0;
		}

		if (colidirRight) {
			if (aAtual == animacao[6] || aAtual == animacao[4]) {
				aAtual = animacao[4];
			}
			else if (aAtual == animacao[7] || aAtual == animacao[5]) {
				aAtual = animacao[5];
			}
			MoveTo(aux->Right() + 13, y);
			velX = 0;
		}

		
	}

	if (obj->Type() == DIAMOND) {
		Diamond* aux = (Diamond*)obj;
		score += aux->Catch();
	}

	if (obj->Type() == TRAP) {
		TreasureHunters::audio->Stop(DIAMOND);
		TreasureHunters::audio->Stop(JUMP);
		TreasureHunters::audio->Stop(DOUBLEJUMP);
		TreasureHunters::audio->Play(PLAYERHIT);
		Sleep(700);
		alive = false;
	}

	if (obj->Type() == LVLUP) {
		Door* aux = (Door*)obj;
		if (!aux->Open()) {
			aux->Open(true);
			TreasureHunters::audio->Play(OPENDOOR);
		}
		

		if (window->KeyPress('F')) {
			nextLevel = true;
		}
	}

	if (obj->Type() == CAVE) {

		if (window->KeyPress('F')) {
			nextLevel = true;
		}
	}
}

void Player::NotCollision() {
	//onCollision = false;
}

void Player::Draw() {
	aAtual->Draw(x, y, Layer::UPPER);
}