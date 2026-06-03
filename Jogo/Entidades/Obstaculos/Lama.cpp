#include "Lama.h"

Lama::Lama(float x, float y, float largura) {
	corpo.setSize(sf::Vector2f(largura, 20.f));
	corpo.setPosition(x, y);
	corpo.setFillColor(sf::Color::Magenta);
}
Lama::~Lama() {}
//diminuir a velocidade do jogador 
void Lama::executar()
{
}
//deve ser implementado no gerenciador de colisões uma forma de detectar a colisão do jogador com a lama para que ocorra o efeito
void Lama::obstacularizar(Jogador* p)
{
	p->diminuirVelocidade();
}
