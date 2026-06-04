#include "Armadilha.h"

namespace Principal {
	Armadilha::Armadilha(float x, float y, float largura, float altura):danosidade(1) {
		corpo.setSize(sf::Vector2f(largura, altura));
		corpo.setPosition(x, y);
		corpo.setFillColor(sf::Color::Red);

		danoso = true; // Armadilha é danosa
	}
	Armadilha::~Armadilha() {}
	void Armadilha::executar() 
	{
		aplicarGravidade();
	}
	void Armadilha::obstacularizar(Jogador* p) {
		
		//alguma forma de diminuir a vida do jogador
		//será aqui que o jogador levara dano e colidirá
		setVivo(false);// A armadilha se torna inativa após ser acionada

	}
	void Armadilha::salvar() {
		// Implementação do método salvar
	}
}