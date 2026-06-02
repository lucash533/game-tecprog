#pragma once
#include "../Ente.h"
#include <SFML/Graphics.hpp>

namespace Jogo {
    
    class GerGrafico {
    private:
        sf::RenderWindow* janela;

    public:
        GerGrafico();
        ~GerGrafico();

        void desenharEnte(Ente* pE);
        void limpaJanela();
        void mostraJanela();

        void fechaJanela();
    };

}