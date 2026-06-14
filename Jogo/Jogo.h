#pragma once
#include "Entidades/Personagens/Jogador.h"
#include "Fases/FasePrimeira.h"
#include "Ente.h"
#include "Gerenciadores/GerenciadorGrafico.h"
#include "Menu/Menu.h"
#include "Menu/MenuFases.h"


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
        bool doisJogadores; // !!!

        GerenciadorGrafico* pGG;

        // Identificador usado para definir qual parte do jogo executar
        // 0: menu principal
        // 1: fase 1
        int modo;

        // Fases
        FasePrimeira fase1;

        //menu
        Menu menuPrincipal;
        MenuFases menuFases;       

        void inicializaMenus();
        

    public:
        Jogo();
        ~Jogo();

        void alteraJogadores(bool jog2);
        void alteraModo(const int input);
        void avançaFase();

        void executar();
		void atualizarCamera();
    };
}