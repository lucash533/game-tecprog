#include "Jogo.h"

// Whatsapp

namespace Principal {

    Jogo::Jogo()
     : pGG(GerenciadorGrafico::getGerenciadorGrafico(alturaJanela, larguraJanela)) {
        Ente::setGG(pGG);

        // Provisoriamente, o jogo já começa direto na fase 1. Alterar após criar menu
        fase1.incluirJogadores(&jogador1);

        executar();

    }

    Jogo::~Jogo() {
        if (pGG) {
            delete pGG;
            pGG = NULL;
        }
    }

    void Jogo::executar() {
        while (pGG->getJanela()->isOpen()) {
            sf::Event evento;
            
            // Função para conferir quando fechar a janela
            while (pGG->getJanela()->pollEvent(evento)) {
                if (evento.type == sf::Event::Closed ||
                    evento.type == sf::Event::KeyPressed && 
                    evento.key.code == sf::Keyboard::Escape)
                    
                    pGG->getJanela()->close();


            }

            // Executa a primeira fase. Novamente, provisório até ter um menu
            pGG->limpaJanela();
            fase1.executar(pGG->getJanela());
            pGG->mostraJanela();
        }
    }
}
