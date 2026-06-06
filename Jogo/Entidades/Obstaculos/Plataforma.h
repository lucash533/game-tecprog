#pragma once
#include "Obstaculo.h"

namespace Principal {
    class Plataforma : public Obstaculo {
    public:
        // construtor para criar plataforma em posição específica, com largura e altura definidas (altura valor a definir)
        Plataforma(float x, float y, float largura, float altura = 20.f); 
        ~Plataforma();

        void executar(); 
        void obstacularizar(Jogador* p); 
		void obstacularizar(Entidade* p); // Sobrecarga para permitir que a plataforma funcione com qualquer entidade, não apenas o jogador
        void salvar();
    };
}

