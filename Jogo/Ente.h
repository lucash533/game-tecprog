#pragma once
#include <SFML/Graphics.hpp>

class Gerenciador_Grafico; //Implementar Gerenciador_Grafico.h e .cpp depois
class Figura;

class Ente {
protected:
    int id; // identificador único do ente
    static Gerenciador_Grafico* pGG;
    static sf::RenderWindow* pJanela;
	static int contador_id; // contador para gerar IDs únicos
    //Figura* pFig;  

public:
    Ente();
    virtual ~Ente();

    virtual void executar() = 0;
    virtual void desenhar(sf::RenderWindow& window) = 0; // desenha na tela

    static void setGG(Gerenciador_Grafico* pG);
    static void setJanela(sf::RenderWindow* j);
};



