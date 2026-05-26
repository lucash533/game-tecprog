#pragma once
#include "Personagem.h"
//using namespace Personagens;
#include <SFML/Graphics.hpp>

//namespace Jogo::Entidades::Personagens{
	class Jogador : public Personagem {
	public:	
		int pontos;

	public:
		Jogador();
		~Jogador();
		void colidir();
		void salvar();
		void mover();
		void executar();
		void desenhar(sf::RenderWindow& window);
		
	};

