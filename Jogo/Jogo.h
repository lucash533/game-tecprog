#pragma once
#include "Entidades/Personagens/Jogador.h"
#include "Fases/FasePrimeira.h"
#include "Ente.h"
#include "Gerenciadores/GerenciadorGrafico.h"
#include "Menu/Menu.h"


namespace Principal {
    class Jogo {
    private:
        // Dimensões da janela
        const float alturaJanela = 700.f;
        const float larguraJanela = 900.f;
        const float larguraFase = 3600.f;
        // Jogadores
        Jogador jogador1;
        Jogador jogador2;

        GerenciadorGrafico* pGG;

        // Identificador usado para definir qual parte do jogo executar
        // 0: menu principal
        // 1: fase 1
        int modo;

        // Fases
        FasePrimeira fase1;

        //menu
        Menu menuPrincipal;

        //void executarMenu();
        //void executarFase1();

    public:
        Jogo();
        ~Jogo();

        void executar();
		void atualizarCamera();
    };
}