#include "Jogo.h"

// Whatsapp

namespace Principal {

    Jogo::Jogo()
     : pGG(GerenciadorGrafico::getGerenciadorGrafico(alturaJanela, larguraJanela)), modo(0) {
        Ente::setGG(pGG);

        menuPrincipal.setBackground("assets/textures/irmasmariatruecut.png");

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
                if (evento.type == sf::Event::Closed/* ||
                    evento.type == sf::Event::KeyPressed && 
                    evento.key.code == sf::Keyboard::Escape*/)
                    
                    pGG->getJanela()->close();
            }

            // Executa a primeira fase. Novamente, provisório até ter um menu
            pGG->limpaJanela();
            switch (modo) {
            case 0:
                menuPrincipal.executar();
                menuPrincipal.desenhar(*pGG->getJanela());
                break;
            case 1:
                // fase 1
                fase1.executar(pGG->getJanela());
                break;
            default:
                // menu
                break;
            }

            //fase1.executar(pGG->getJanela());
            pGG->mostraJanela();
        }
    }
}
