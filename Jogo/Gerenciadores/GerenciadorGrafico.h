#pragma once
#include "../Ente.h"
#include <SFML/Graphics.hpp>

namespace Jogo {
    
    class GerenciadorGrafico {
    private:
        sf::RenderWindow* janela;

        static GerenciadorGrafico* pGerenciador;
        GerenciadorGrafico();

        const unsigned int altura; //float
        const unsigned int largura; //float

    public:
        ~GerenciadorGrafico();

        static GerenciadorGrafico* getGerenciadorGrafico();

        void desenharEnte(Ente* pE);
        void limpaJanela();
        void mostraJanela();

        sf::RenderWindow* getJanela() const;
        //const bool janelaAberta() const;
    };

}