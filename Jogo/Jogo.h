<<<<<<< HEAD
#pragma once
#include "Entidades/Personagens/Jogador.h"


class Jogo {
private:
    //GerenciadorGrafico GG;
    Jogador pJog1; //Talvez seja um ponteiro, modelo UML está ambíguo

protected:


public:
    Jogo();
    ~Jogo();

    void executar();
};
=======
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



>>>>>>> origin/master
