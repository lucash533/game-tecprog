#include <SFML/Graphics.hpp>
#include "Entidades/Personagens/Jogador.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(900, 700), "Jogo");
    Jogador jogador;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        jogador.executar();

        window.clear();
        jogador.desenhar(window);
        window.display();
    }
}