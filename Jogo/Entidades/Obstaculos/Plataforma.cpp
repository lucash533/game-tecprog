
#include "Plataforma.h"

Plataforma::Plataforma(float x, float y, float largura, float altura) {
    // construtor para criar plataforma em posição específica, com largura e altura definidas (altura valor a definir)
    corpo.setSize(sf::Vector2f(largura, altura));
    corpo.setPosition(x, y);
    corpo.setFillColor(sf::Color::Cyan);
}
Plataforma::~Plataforma() {}

void Plataforma::executar() {}
//acredito que não tem nada a fazer aqui, tal função será mais complexa quando eu implementar os obstaculo medio e dificil
void Plataforma::obstacularizar(Jogador* p) {}
void Plataforma::salvar() {}

