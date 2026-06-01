
#include "Plataforma.h"
// A implementar

Plataforma::Plataforma(float x, float y, float largura, float altura) {
    corpo.setSize(sf::Vector2f(largura, altura));
    corpo.setPosition(x, y);
    corpo.setFillColor(sf::Color::Cyan);
}
Plataforma::~Plataforma() {}

void Plataforma::executar() {}
void Plataforma::obstacularizar(Jogador* p) {}
void Plataforma::salvar() {}

