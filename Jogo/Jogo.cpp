#include "Jogo.h"

namespace Principal {

    Jogo::Jogo()
     : pGG(GerenciadorGrafico::getGerenciadorGrafico(alturaJanela, larguraJanela)), modo(0) {
        Ente::setGG(pGG);

        menuPrincipal.setBackground("assets/textures/irmasmariatruecut.png");

        // Provisoriamente, o jogo já começa direto na fase 1. Alterar após criar menu
        fase1.incluirJogadores(&jogador1);
        fase1.inicializaFase();

        // NOTA: executar() foi removido do construtor para evitar loop infinito
        // antes de Jogo ser retornado para o main
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

            while (pGG->getJanela()->pollEvent(evento)) {
                if (evento.type == sf::Event::Closed/* ||
                    evento.type == sf::Event::KeyPressed && 
                    evento.key.code == sf::Keyboard::Escape*/)
                    
                    pGG->getJanela()->close();
            }
            atualizarCamera();

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
    void Jogo::atualizarCamera() {
        if (!jogador1.getVivo()) return;

        sf::RenderWindow* janela = pGG->getJanela();
        sf::View camera = janela->getDefaultView();

        float camX = jogador1.getPosicao().x + 20.f;
        float metadeJanela = camera.getSize().x / 2.f;

        // limita para não sair da fase
        if (camX < metadeJanela)
            camX = metadeJanela;
        if (camX > larguraFase - metadeJanela) // usa largura da fase
            camX = larguraFase - metadeJanela;

        camera.setCenter(camX, camera.getSize().y / 2.f);
        janela->setView(camera);
    }
}