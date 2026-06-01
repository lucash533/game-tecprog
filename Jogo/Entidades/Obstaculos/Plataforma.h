#pragma once
#include "Obstaculo.h"

class Plataforma : public Obstaculo {
public:
    // construtor para criar plataforma em posição específica, com largura e altura definidas (altura valor a definir)
	Plataforma(float x, float y, float largura, float altura = 20.f); 
    ~Plataforma();

    void executar();
    void obstacularizar(Jogador* p);
    void salvar();
	void getPosicao();
};


