#include "Menu.h"
#include"../Jogo.h"

namespace Principal {

    Menu::Menu() {
        //...
        //backgroundImage.loadFromFile("assets/textures/irmasmariatruecut.png");
                                    // Jogo/Menu/Menu.cpp
    }

    Menu::~Menu() {
        //...
    }

    void Menu::setJogo(Jogo* p) {
        if (p) 
            pJogo = p;
    }

    void Menu::setBackground(const char* caminho) {
        backgroundImage.loadFromFile(caminho);
        background.setPosition(sf::Vector2f(0.f,0.f));
        background.setTexture(backgroundImage);
    }

    void Menu::desenhar(sf::RenderWindow& window) {
        window.draw(background);
    } // talvez precise de virtual

    void Menu::executar() {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1))
            3;// alterar estado
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2))
            3;// alterar estado
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            pGG->getJanela()->close();
    
    }
}