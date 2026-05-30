#include "Jogador.h"
#include "Inimigo.h"
#include <SFML/Graphics.hpp>

Jogador::Jogador() : pontos(0) {
    corpo.setSize(sf::Vector2f(40, 40));
    corpo.setFillColor(sf::Color::Green);
    corpo.setPosition(sf::Vector2f(100.f, 275.f));

    //velocidade horizontal 5.0f
    vel = sf::Vector2f(5.0f, 0.0f);
}

Jogador::~Jogador() {}

void Jogador::executar() { mover(); }

void Jogador::mover() {
    // Movimentação horizontal
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) //Referencia: https://www.youtube.com/watch?v=WrJpux-vpcI&list=PLR17O9xbTbIBBoL3lli44N8LdZVvg-_uZ&index=2
        corpo.move(-vel.x, 0.0f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        corpo.move(vel.x, 0.0f);

    // Pulo (Teclando W e estando no chão)
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && noChao) {
        velY = -12.0f;  // Força que empurra o jogador para cima apenas quando estiver no chão
        noChao = false; // saiu do chão
    }

    // Aplica a gravidade sempre 
    aplicarGravidade();
}

void Jogador::salvar() {}
void Jogador::colidir(Inimigo* pIn) {}