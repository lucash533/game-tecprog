#include "MenuFases.h"
#include "../Jogo.h"

namespace Principal {

    MenuFases::MenuFases() {
        // inicializar imagens
        // ...
    }

    MenuFases::~MenuFases() {

    }

    void MenuFases::executar() {
        /*
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
            pJogo->alteraJogadores(false);
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
            pJogo->alteraJogadores(true);
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1)) {
            pJogo->alteraModo(0);
            pJogo->avançaFase();
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2)) {
            pJogo->alteraModo(1);
            pJogo->avançaFase();
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            pJogo->alteraModo(0);
        */
        
        //sf::Event evento;// = pJogo->getEvento();
        if (evento.type == sf::Event::KeyPressed) {
            if (evento.key.code == sf::Keyboard::M) {
                evento.type = sf::Event::Count;
                pJogo->alteraJogadores(false);
            }
            else if (evento.key.code == sf::Keyboard::L) {
                evento.type = sf::Event::Count;
                pJogo->alteraJogadores(true);
            }
            else if (evento.key.code == sf::Keyboard::Num1 || evento.key.code == sf::Keyboard::Numpad1) {
                evento.type = sf::Event::Count;
                pJogo->alteraModo(0);
                pJogo->avançaFase();
            }
            else if (evento.key.code == sf::Keyboard::Num2 || evento.key.code == sf::Keyboard::Numpad2) {
                3;//pJogo->alteraModo()
            }
            else if (evento.key.code == sf::Keyboard::Escape) {
                evento.type = sf::Event::Count;
                pJogo->alteraModo(0);
            }
        }
    }

    void MenuFases::desenhar(sf::RenderWindow& window) {
        // desenhar imagens

        window.draw(background);
    }

}