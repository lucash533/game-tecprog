#pragma once
#include "../Ente.h"
#include <SFML/Graphics.hpp>

namespace Jogo {
    
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

        sf::RenderWindow* getJanela() const;
        //const bool janelaAberta() const;
    };

}