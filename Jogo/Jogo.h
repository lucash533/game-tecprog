// ---------------------------------//
// As implementações das funções dessa
// classe foram feitas unicamente
// para testar a estrutura do jogo,
// e não tem a intenção de estar no jogo completo.
//---------------------------------//

#pragma once
#include "Entidades/Personagens/Jogador.h"
#include "Entidades/Personagens/Alma.h"
#include "Entidades/Obstaculos/Plataforma.h"

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



