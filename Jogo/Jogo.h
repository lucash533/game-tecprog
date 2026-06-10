#pragma once
#include "Entidades/Personagens/Jogador.h"
#include "Fases/FasePrimeira.h"
#include "Ente.h"
#include "Gerenciadores/GerenciadorGrafico.h"


namespace Principal {
    class Jogo {
    private:
        // Dimensões da janela
        const float alturaJanela = 700.f;
        const float larguraJanela = 900.f;

        // Jogadores
        Jogador jogador1;
        Jogador jogador2;

        GerenciadorGrafico* pGG;

        // Fases
        FasePrimeira fase1;

        //menu

    public:
        Jogo();
        ~Jogo();

        void executar();
    };
}