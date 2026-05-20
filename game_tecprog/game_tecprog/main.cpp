#include <SFML/Graphics.hpp>
#include "Jogador.h"

int main()
{
    //criando a janela do jogo e o jogador para teste de movimento
    sf::RenderWindow window(sf::VideoMode({ 900, 700 }), "Jogo");
    Jogo::Entidades::Personagens::Jogador jogador;


    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        jogador.executar();

        window.clear();
        jogador.desenhar(window);
        window.display();
    }
}