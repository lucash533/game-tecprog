#pragma once
#include "Obstaculo.h"

class Lama : public Obstaculo
{
private:
	float largura;
public:
	Lama(float x, float y, float largura);
	~Lama();
	void executar();
	void salvar();
	void obstacularizar(Jogador* p);
};

