#include "Jogador.h"
#include <SFML/Graphics.hpp>

//namespace Jogo::Entidades::Personagens{
Jogador::Jogador() : pontos(0) {
      
        corpo.setSize(sf::Vector2f(40, 40));
        corpo.setFillColor(sf::Color::Green);
        corpo.setPosition(sf::Vector2f(100.f, 275.f));
        vel = sf::Vector2f(0.1f, 0.1f);
		
    }

    Jogador::~Jogador() {}

    void Jogador::executar() { mover(); }

    void Jogador::mover() {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            corpo.move(-vel.x, 0.0f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            corpo.move(vel.x, 0.0f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            corpo.move(0.0f, -vel.y);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            corpo.move(0.0f, vel.y);
    }

    void Jogador::salvar() {}
    void Jogador::colidir() {}

    void Jogador::desenhar(sf::RenderWindow& window) {
        window.draw(corpo);
    }