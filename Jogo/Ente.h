#pragma once
#include "Gerenciadores/GerenciadorGrafico.h"
#include <SFML/Graphics.hpp>

namespace Principal {
    /*const int ID_JOGADOR = 1;
    const int ID_ALMA = 2;
    const int ID_BANSHEE = 3;
	const int ID_PISADEIRA = 4;
    const int ID_PLATAFORMA = 5;
    const int ID_LAMA = 6;
    const int ID_ARMADILHA = 7;*/



    class Figura;

    class Ente {
    protected:
        int id; // identificador único do ente
        static GerenciadorGrafico* pGG; 
        static sf::RenderWindow* pJanela;
        //static int contador_id; // contador para gerar IDs únicos
        //Figura* pFig;  

    public:
        Ente();
        virtual ~Ente();

        virtual void executar() = 0;
        virtual void desenhar(sf::RenderWindow& window) = 0; // desenha na tela

        static void setGG(GerenciadorGrafico* pG);
        static void setJanela(sf::RenderWindow* j);
        static GerenciadorGrafico* getGG();
       
    };
}


