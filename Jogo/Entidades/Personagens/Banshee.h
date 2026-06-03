#pragma once
#include "Inimigo.h"
//
// A DEFINIRRR
//
class Banshee :
    public Inimigo
{
private:
    float raio; // distância máxima para perseguir o jogador
    Personagem* alvo; // ponteiro para o jogador (alvo)
    float tamanho;
public:
	Banshee();
	Banshee(float x, float y);
	~Banshee();
	void executar();
	void mover();
	void perseguir(sf::Vector2f pos_alvo, sf::Vector2f pos_inimigo);
	void danificar(Jogador* p); // método para causar dano ao jogador
	void salvar();
};

