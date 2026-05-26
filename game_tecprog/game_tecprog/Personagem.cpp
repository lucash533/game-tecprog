
#include "Personagem.h"


	//funçoes serão implementadas futuramente
	Personagem::Personagem() : num_vidas(3) {
	}
	
	Personagem::~Personagem() {	
	}

	void Personagem::salvarDataBuffer() {
	}
	sf::Vector2f Personagem::getPosicao() {
		return corpo.getPosition();
	}
	sf::RectangleShape Personagem::getCorpo() {
		return corpo;
	}
	


