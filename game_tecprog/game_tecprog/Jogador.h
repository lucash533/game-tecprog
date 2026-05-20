#pragma once
#include "Personagem.h"
#include <SFML/Graphics.hpp>
namespace Jogo
{
	namespace Personagens
	{
	class Jogador : public Personagem
	{
	protected:
		
		int pontos;
		sf::Vector2i vel;
		sf::RectangleShape corpo;
	public:
		Jogador();
		~Jogador();
		void colidir();
		void salvar();
		void mover();
		void executar();
		void desenhar(sf::RenderWindow& window);
	};
}
}