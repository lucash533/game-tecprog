#include <SFML/Graphics.hpp>
#include "Jogador.h"
#include "Inimigo.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(900, 700), "Jogo - Testando Jogador e Inimigo");

    Jogador jogador;
    Inimigo inimigo;

    inimigo.setAlvo(&jogador);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed ||
                (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
                window.close();
            }
        }
        jogador.executar();
        inimigo.executar();

        window.clear();

        jogador.desenhar(window);
        inimigo.desenhar(window);

        window.display();
    }

    return 0;
}