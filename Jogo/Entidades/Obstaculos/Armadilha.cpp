#include "Armadilha.h"

namespace Jogo {
	Armadilha::Armadilha(float x, float y, float largura, float altura):danosidade(1) {
		corpo.setSize(sf::Vector2f(largura, altura));
		corpo.setPosition(x, y);
		corpo.setFillColor(sf::Color::Red);

		danoso = true; // Armadilha é danosa
	}
	Armadilha::~Armadilha() {}
	void Armadilha::executar() 
	{

	}
	void Armadilha::obstacularizar(Jogador* p) {
		
		//alguma forma de diminuir a vida do jogador
		p->atordoamento();
	}
	void Armadilha::salvar() {
		// Implementação do método salvar
	}
}