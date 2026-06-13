#pragma once
#include "../Ente.h"


namespace Principal {

    class Jogo;

    class Menu : public Ente {
    protected:
        sf::Texture backgroundImage;
        sf::Sprite background;
        Jogo* pJogo;

    public:
        Menu();
        ~Menu();

        void setJogo(Jogo* p);
        void setBackground(const char* caminho); // talvez não funcione

        virtual void executar();
        virtual void desenhar(sf::RenderWindow& window);
    };
}