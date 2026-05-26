#pragma once
#include "Personagem.h"
#include "Jogador.h"
#include <SFML/Graphics.hpp>
#define RAIO_DE_PERSEGUICAO 300.0f

class Inimigo : public Personagem
{
private:
	Jogador* alvo;
	short movi_aleatorio;

protected:
	int nivel_maldade;

public:
	Inimigo();
	~Inimigo();
	void salvarDataBuffer();
	virtual void executar();
	void perseguir(sf::Vector2f pos_alvo, sf::Vector2f pos_inimigo);
	void moverAleatorio();
	void mover();
	void desenhar(sf::RenderWindow& window);
	virtual void salvar();
	void setAlvo(Jogador* jogador) { alvo = jogador; }
};

