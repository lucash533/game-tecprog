#pragma once
#include "Entidades/Personagens/Jogador.h"
#include "Entidades/Personagens/Ini_Facil.h"


class Jogo {
private:
    sf::RenderWindow janela;
    Jogador jogador;
    Inim_Facil inimigo;
    sf::RectangleShape chao;

    void processarEventos();
    void atualizar();
    void desenhar();
    void resolverColisao(Personagem& p);

public:
    Jogo();
    ~Jogo();
    void executar();
};




