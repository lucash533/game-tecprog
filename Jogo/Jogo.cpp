#include "Jogo.h"

namespace Principal {

    Jogo::Jogo()
     : pGG(GerenciadorGrafico::getGerenciadorGrafico(alturaJanela, larguraJanela)), modo(0), 
     doisJogadores(false) {
        Ente::setGG(pGG);

        inicializaMenus();

        // Provisoriamente, o jogo já começa direto na fase 1. Alterar após criar menu
        //fase1.incluirJogadores(&jogador1);
        //fase1.inicializaFase();

        // NOTA: executar() foi removido do construtor para evitar loop infinito
        // antes de Jogo ser retornado para o main
    }

    Jogo::~Jogo() {
        if (pGG) {
            delete pGG;
            pGG = NULL;
        }
    }

    void Jogo::inicializaMenus() {
        menuPrincipal.setJogo(this);
        menuPrincipal.setBackground("assets/textures/irmasmariatruecut.png");

        menuFases.setJogo(this);
        menuFases.setBackground("assets/textures/salinhadasirmas.png");
    }

    void Jogo::alteraJogadores(bool jog2) {
        doisJogadores = jog2;
    }

    void Jogo::alteraModo(const int input) {
        modo = input;
    }

    void Jogo::avançaFase() {
        switch (modo)
        {
        case 0:
            if (doisJogadores)
                fase1.incluirJogadores(&jogador1, &jogador2);
            else
                fase1.incluirJogadores(&jogador1);
            fase1.inicializaFase();
            alteraModo(++modo);
            break;
        default:
            modo = 0;
            break;
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

                if (evento.type == sf::Event::KeyPressed) {
                    switch (modo)
                    {
                    case -1:
                        menuFases.processarEvento(evento);
                        break;

                    case 0:
                        menuPrincipal.processarEvento(evento);
                        break;
                    
                    default:
                        break;
                    }
                }
            }
            atualizarCamera();

            pGG->limpaJanela();
            switch (modo) {
            case -1:
                menuFases.executar();
                menuFases.desenhar(*pGG->getJanela());
                break;    

            case 0:
                menuPrincipal.executar();
                menuPrincipal.desenhar(*pGG->getJanela());
                break;
            case 1:
                // fase 1
                fase1.executar(pGG->getJanela()); // ATUALIZAR DEPOIS DE CORRIGIR FASE
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