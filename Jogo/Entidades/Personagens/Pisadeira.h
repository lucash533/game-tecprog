#pragma once
#include "Inimigo.h"

namespace Principal {
	class Pisadeira :
		public Inimigo
	{
	private:
		float raio; // distância máxima para perseguir o jogador
		Personagem* alvo; // ponteiro para o jogador (alvo)
		float tamanho;
		int short forca;
	public:
		Pisadeira();
		Pisadeira(float x, float y);
		~Pisadeira();
		void executar();
		void mover();
		void perseguir(sf::Vector2f pos_alvo, sf::Vector2f pos_inimigo);
		void danificar(Jogador* p); // método para causar dano ao jogador
		void salvar();
	};
}

