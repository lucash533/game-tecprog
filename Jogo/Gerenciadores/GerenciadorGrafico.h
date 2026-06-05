#pragma once
#include "../Ente.h"
#include <SFML/Graphics.hpp>

namespace Principal {
    
    class GerenciadorGrafico {
    private:
        sf::RenderWindow* janela;

        static GerenciadorGrafico* pGerenciador;
        GerenciadorGrafico(unsigned altura, unsigned largura);

        const unsigned int alturaJanela; //float
        const unsigned int larguraJanela; //float

    public:
        ~GerenciadorGrafico();

        static GerenciadorGrafico* getGerenciadorGrafico(unsigned altura, unsigned largura);
        static GerenciadorGrafico* getGerenciadorGrafico();

        void desenharEnte(Ente* pE);
        void limpaJanela();
        void mostraJanela();

        const unsigned int getAltura() const;
        const unsigned int getLargura() const;

        sf::RenderWindow* getJanela() const;
    };

}