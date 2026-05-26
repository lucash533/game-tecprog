#include "Inimigo.h"
#include <cmath>

Inimigo::Inimigo() : alvo(nullptr), movi_aleatorio(0), nivel_maldade(1) {
	corpo.setSize(sf::Vector2f(40, 40));
	corpo.setFillColor(sf::Color::Red);
	corpo.setPosition(sf::Vector2f(400.f, 275.f));
	vel = sf::Vector2f(0.01f, 0.01f);

}

void Inimigo::salvar() { }
Inimigo::~Inimigo() {}
void Inimigo::executar() {
	mover();
}
void Inimigo::perseguir(sf::Vector2f pos_alvo, sf::Vector2f pos_inimigo) {
	if (pos_alvo.x - pos_inimigo.x > 0) {
		corpo.move(vel.x, 0);
	} else {
		corpo.move(-vel.x, 0);
	}
	if (pos_alvo.y - pos_inimigo.y > 0) {
		corpo.move(0, vel.y);
	} else {
		corpo.move(0, -vel.y);
	}
}
void Inimigo::desenhar(sf::RenderWindow& window) {
	window.draw(corpo);
}

void Inimigo::mover()
{
	
	if (alvo == nullptr) return;

	sf::Vector2f pos_alvo = alvo->getCorpo().getPosition();
	sf::Vector2f pos_inimigo = corpo.getPosition();
	if (fabs(pos_alvo.x - pos_inimigo.x) <= RAIO_DE_PERSEGUICAO && fabs(pos_alvo.y - pos_inimigo.y) <= RAIO_DE_PERSEGUICAO)
		perseguir(pos_alvo, pos_inimigo);
}




