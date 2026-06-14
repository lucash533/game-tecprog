#include "Jogo.h"

namespace Principal {

    Jogo::Jogo()
        : pGG(GerenciadorGrafico::getGerenciadorGrafico(alturaJanela, larguraJanela)) {
        Ente::setGG(pGG);

        // Provisoriamente, o jogo já começa direto na fase 1
        fase1.incluirJogadores(&jogador1);
        fase1.inicializaFase();
       

        fase2.incluirJogadores(&jogador1); 
        fase2.inicializaFase();            
        
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
                if (evento.type == sf::Event::Closed ||
                    (evento.type == sf::Event::KeyPressed &&
                        evento.key.code == sf::Keyboard::Escape))
                    pGG->getJanela()->close();
            }
            atualizarCamera();

            pGG->limpaJanela();
            fase2.executar(pGG->getJanela());
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