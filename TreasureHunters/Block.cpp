#include "TreasureHunters.h"
#include "Block.h"
#include <string>

Block::Block(uint tipo, uint ordem, float posx, float posy) {

	string aux = std::to_string(ordem);
	aux = aux + ".png";

	//Floresta
	if (tipo == SOLOG) {
		block = new Sprite("Resources/GreenGrass/Type1-" + aux);
	}

	if (tipo == CONTINUOG) {
		block = new Sprite("Resources/GreenGrass/Type2-" + aux);
	}

	if (tipo == SOLOS) {
		block = new Sprite("Resources/GreenGrass/Type3-" + aux);
	}

	if (tipo == CONTINUOS) {
		block = new Sprite("Resources/GreenGrass/Type4-" + aux);
	}

	//Caverna
	if (tipo == CAVESOLO) {
		block = new Sprite("Resources/Cave/Type1-" + aux);
	}

	if (tipo == CAVECONTINUO) {
		block = new Sprite("Resources/Cave/Type2-" + aux);
	}

	if (tipo == CSSOLO) {
		block = new Sprite("Resources/Cave/Type3-" + aux);
	}

	if (tipo == CSCONTINUO) {
		block = new Sprite("Resources/Cave/Type4-" + aux);
	}
	
	BBox(new Rect(-24, -24, 24, 24));

	MoveTo(posx, posy);
	type = BLOCK;
}

Block::Block(uint tipo, uint ordem, float posx, float posy, bool terBbox, uint tamanho) {

	tamanho = tamanho * 1.9;

	string aux = std::to_string(ordem);
	aux = aux + ".png";

	//Floresta
	if (tipo == SOLOG) {
		block = new Sprite("Resources/GreenGrass/Type1-" + aux);
	}

	if (tipo == CONTINUOG) {
		block = new Sprite("Resources/GreenGrass/Type2-" + aux);
	}

	if (tipo == SOLOS) {
		block = new Sprite("Resources/GreenGrass/Type3-" + aux);
	}

	if (tipo == CONTINUOS) {
		block = new Sprite("Resources/GreenGrass/Type4-" + aux);
	}

	//Caverna
	if (tipo == CAVESOLO) {
		block = new Sprite("Resources/Cave/Type1-" + aux);
	}

	if (tipo == CAVECONTINUO) {
		block = new Sprite("Resources/Cave/Type2-" + aux);
	}

	if (tipo == CSSOLO) {
		block = new Sprite("Resources/Cave/Type3-" + aux);
	}

	if (tipo == CSCONTINUO) {
		block = new Sprite("Resources/Cave/Type4-" + aux);
	}

	if(terBbox){
		BBox(new Rect(-24, -24, 24 * tamanho, 24));
	}
	
	MoveTo(posx, posy);
	type = BLOCK;
}

Block::~Block() {
	delete block;
}

void Block::Draw() {
	block->Draw(x, y, Layer::MIDDLE);
}

void Block::Update() {

}