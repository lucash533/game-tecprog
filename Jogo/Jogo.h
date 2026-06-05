// ---------------------------------//
// As implementações das funções dessa
// classe foram feitas unicamente
// para testar a estrutura do jogo,
// e não tem a intenção de estar no jogo completo.
//---------------------------------//

#pragma once
#include "Entidades/Personagens/Jogador.h"
#include "Fases/FasePrimeira.h"
#include "Ente.h"
#include "Gerenciadores/GerenciadorGrafico.h"

//#include "Entidades/Obstaculos/Plataforma.h"
//#include "Entidades/Personagens/Alma.h"

#include "Entidades/Bloco/Sala.h" // provisorio


namespace Principal {
    class Jogo {
    private:
        const float alturaJanela = 700.f;
        const float larguraJanela = 900.f;

        Jogador jogador1;
        Jogador jogador2;

        GerenciadorGrafico* pGG;

        FasePrimeira fase1;

        //Sala sala1;

        //menu

    public:
        Jogo();
        ~Jogo();

        void executar();
    };
}
//*/

/*
namespace Principal {
    class Jogo {
    private:
        sf::RenderWindow janela;
        Jogador jogador;
        Alma alma;
        sf::RectangleShape chao;
        Plataforma plataforma;

        void processarEventos();
        void atualizar();
        void desenhar();
        void resolverColisao(Personagem& p);

    public:
        Jogo();
        ~Jogo();
        void executar();
    };
}

//*/

