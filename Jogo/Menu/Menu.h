#pragma once
#include "../Ente.h"


namespace Principal {

    class Jogo;

    class Menu : public Ente {
    protected:
        sf::Texture backgroundImage;
        sf::Sprite background;
        Jogo* pJogo;

        sf::Event evento;
        //bool teclaPressionada;

    public:
        Menu();
        ~Menu();

        void setJogo(Jogo* p);
        void setBackground(const char* caminho); // talvez não funcione

        void processarEvento(sf::Event& sinal);

        virtual void executar();
        virtual void desenhar(sf::RenderWindow& window);
    };
}