#include "Pisadeira.h"
//
//A DEFINIRR
//

namespace Principal {
	Pisadeira::Pisadeira() : raio(300.0f), alvo(nullptr), tamanho(40.0f), forca(20)
	{
		//id = Principal::ID_PISADEIRA;
		corpo.setSize(sf::Vector2f(tamanho, tamanho));
		corpo.setFillColor(sf::Color::Yellow);
		corpo.setPosition(sf::Vector2f(100, 100)); // posição inicial padrão
		vel = sf::Vector2f(3.0f, 0.0f); // velocidade horizontal base
	}
	Pisadeira::~Pisadeira(){}

	void Pisadeira::executar() { mover(); }

	void Pisadeira::mover()
	{
		
	}

	void Pisadeira::perseguir(sf::Vector2f pos_alvo, sf::Vector2f pos_inimigo)
	{
		// Implementação do método perseguir
	}

	void Pisadeira::danificar(Jogador* p)
	{
		// Implementação do método danificar
	}

	void Pisadeira::salvar()
	{
		// Implementação do método salvar
	}
}