#include "Jogador.h"

//namespace Jogo::Entidades::Personagens{
Jogador::Jogador() : pontos(0) {
      
        corpo.setSize(sf::Vector2f(50, 50));
        corpo.setFillColor(sf::Color::Green);
        corpo.setPosition(sf::Vector2f(375.f, 275.f));
    }

    Jogador::~Jogador() {}

    void Jogador::executar() { mover(); }

    void Jogador::mover() {
        float vel = 0.1f;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            corpo.move(-vel, 0.f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            corpo.move(vel, 0.f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            corpo.move(0.f, -vel);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            corpo.move(0.f, vel);
    }

    void Jogador::salvar() {}
    void Jogador::colidir() {}

    void Jogador::desenhar(sf::RenderWindow& window) {
        window.draw(corpo);
    }