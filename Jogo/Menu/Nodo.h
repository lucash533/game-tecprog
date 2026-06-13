#pragma once
#include "../Ente.h"

namespace Principal {
    class Nodo : public Ente {
    protected:
        sf::Vector2f coordenadas;
        sf::RectangleShape caixa;

    public:
        Nodo();
        virtual ~Nodo();

        void redimensionarCaixa(float eixoX, float eixoY);

        virtual void executar() = 0;
        virtual void desenhar(sf::RenderWindow& janela) = 0;

        sf::Vector2f getCoordenadas() const;
    };
}