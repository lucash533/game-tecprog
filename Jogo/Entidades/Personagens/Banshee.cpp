#include "Banshee.h"
//
//A DEFINIRR
//
Banshee::Banshee() : raio(300.0f), alvo(nullptr), tamanho(40.0f)
{
	corpo.setSize(sf::Vector2f(tamanho, tamanho));
	corpo.setFillColor(sf::Color::Green);
	corpo.setPosition(sf::Vector2f(100, 100)); // posição inicial padrão
	vel = sf::Vector2f(3.0f, 0.0f); // velocidade horizontal base
}
Banshee::~Banshee() {}

void Banshee::executar()
{
}

void Banshee::mover()
{
}

void Banshee::perseguir(sf::Vector2f pos_alvo, sf::Vector2f pos_inimigo)
{
}

void Banshee::danificar(Jogador* p)
{
}

void Banshee::salvar()
{
}
