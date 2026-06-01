// ---------------------------------//
// As implementações das funções dessa
// classe foram feitas unicamente
// para testar a estrutura do jogo,
// e não tem a intenção de estar no jogo completo.
//---------------------------------//

#pragma once
#include "Entidades/Personagens/Jogador.h"
#include "Entidades/Personagens/Inim_Facil.h"
#include "Entidades/Obstaculos/Plataforma.h"

class Jogo {
private:
    sf::RenderWindow janela;
    Jogador jogador;
    Inim_Facil inimigo;
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




