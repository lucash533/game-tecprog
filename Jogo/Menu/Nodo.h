#pragma once
#include<SFML/Graphics.hpp>

namespace Principal {
    class Nodo {
    protected:
        //sf::RectangleShape

    public:
        Nodo();
        ~Nodo();

        virtual void executar() = 0;
    };
}