#pragma once
#include <SFML/Graphics.hpp> // <-- Faltava isto!

class Personagem {
protected:
    sf::RectangleShape corpo;
    sf::Vector2f vel;
    int num_vidas; // <-- Faltava declarar isto!

public:
    Personagem();
    ~Personagem();
    void salvarDataBuffer();
    virtual void executar() = 0;
    virtual void salvar() = 0;
    virtual void mover() = 0;

    // <-- Faltava declarar estas duas funções!
    sf::Vector2f getPosicao();
    sf::RectangleShape getCorpo();
};

