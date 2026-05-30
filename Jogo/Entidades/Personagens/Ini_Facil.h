#pragma once
#include "Inimigo.h"
#define RAIO_DE_PERSEGUICAO 300.0f

class Inim_Facil : public Inimigo
{
private:
    float raio;  // distância máxima para detectar e perseguir o jogador
	Jogador* alvo; // ponteiro para o jogador, usado para obter a posição do alvo

public:
    Inim_Facil();
    ~Inim_Facil();

    void executar();
    void danificar(Jogador* p);
    void salvar();
    void mover();

    void perseguir(sf::Vector2f pos_alvo, sf::Vector2f pos_inimigo); // move em direção ao jogador
    void setAlvo(Jogador* jogador) { alvo = jogador; } // define quem perseguir
};


