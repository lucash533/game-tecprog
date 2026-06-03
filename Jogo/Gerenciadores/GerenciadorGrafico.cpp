#include "GerenciadorGrafico.h"
#include <iostream>
using namespace std; // TALVEZ DÊ CONFLITO COM O JOGO !!!

#define ALTURA 700u //float
#define LARGURA 900u //float

namespace Jogo {

    GerenciadorGrafico::GerenciadorGrafico()
     : altura(ALTURA), largura(LARGURA) {
        if(!janela) {
            janela = new sf::RenderWindow(sf::VideoMode(
                largura, altura), 
                "Super Irmãs Maria: Caçadoras de Fantasmas!");
        }
        else    
            cerr << "ERRO! \n Tentativa de inicializar janela já existente" << endl;
    }

    GerenciadorGrafico::~GerenciadorGrafico() {
        janela->close();
        janela = NULL;
    }

    GerenciadorGrafico* GerenciadorGrafico::getGerenciadorGrafico() {
        // Padrão de projeto singleton

        // Garante que haja apenas um gerenciador gráfico por vez

        if (pGerenciador == NULL) {
            pGerenciador = new GerenciadorGrafico();
            return pGerenciador;
        }
        return pGerenciador;
    }

    /*
    void GerenciadorGrafico::criaJanela(int largura, int altura) {
        if(!janela) {
            janela = new sf::RenderWindow(sf::VideoMode(
                (unsigned) largura, (unsigned) altura), 
                "Super Irmãs Maria: Caçadoras de Fantasmas!");
        }
        else    
            cerr << "ERRO! \n Tentativa de inicializar janela já existente" << endl;
    }
            */

    void GerenciadorGrafico::desenharEnte(Ente* pE) {
        pE->desenhar(*janela);
    }

    void GerenciadorGrafico::limpaJanela() {
        janela->clear();
    }

    void GerenciadorGrafico::mostraJanela() {
        janela->display();
    }

    sf::RenderWindow* GerenciadorGrafico::getJanela() const {
        return janela;
    }

    //const bool GerenciadorGrafico::janelaAberta()

    // FECHAR NA CLASSE JOGO
    /*
    void GerenciadorGrafico::fechaJanela() {
        sf::Event evento;
        while (janela->pollEvent(evento)) {
            if (evento.type == sf::Event::Closed ||
                evento.type == sf::Event::KeyPressed && 
                evento.key.code == sf::Keyboard::Escape)

                janela->close();
            }
        }
    }
    */

}