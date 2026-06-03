#pragma once
#include "Inimigo.h"

class Alma : public Inimigo
{
private:
    float raio;  // distância máxima para detectar e perseguir o jogador
	Jogador* alvo; // ponteiro para o jogador, usado para obter a posição do alvo

public:
	Alma(); // construtor padrão, vai precisar ser excluido com a criação de fases (APENAS PARA TESTES)
	Alma(float x, float y);// construtor para criar inimigo em posição específica
    ~Alma();

    void executar();
    void danificar(Jogador* p);
    void salvar();
    void mover();

    void perseguir(sf::Vector2f pos_alvo, sf::Vector2f pos_inimigo); // move em direção ao jogador
    void setAlvo(Jogador* jogador) { alvo = jogador; } // define quem perseguir
};


