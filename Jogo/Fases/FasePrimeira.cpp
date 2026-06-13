#include "FasePrimeira.h"
#include "../Entidades/Personagens/Banshee.h"
//#include "../Entidades/" // LAMA

namespace Principal {
    FasePrimeira::FasePrimeira() : maxBanshee(5), maxObstaculoLama(5) {
        GC.setSala(&minhaSala);
    }

    FasePrimeira::~FasePrimeira() {
        
    }

    // Cria inimigos médios
    // VIDE criarAlmas() DA CLASSE FASE PARA PEGAR INSPIRAÇÕES !!!
    void FasePrimeira::criarBanshees() {
        int qtd = rand() % (maxBanshee + 1 - 3) + 3;

        for (int i = 0; i < qtd; i++) {
            float randX = (int)(rand() % (int)(larguraFase - 200.f));
            float randY = alturaFase - 60.f;

            Banshee* inimigo = new Banshee( 50.f + randX, randY);
            inimigo->setAlvo(pJ1);
            listaE.incluir(static_cast<Entidade*>(inimigo), true);
            GC.incluirInimigo(inimigo);
        }
    }

    // VIDE criarPlataformas() DA CLASSE FASE PARA PEGAR INSPIRAÇÕES !!!
    // Cria lamas

    void FasePrimeira::criarLamas() {
        //sementear();
        int qtd = rand() % (maxObstaculoLama + 1 - 3) + 3;

        for (int i = 0; i < qtd; i++) {
            //sementear();
            float randX = (float)(rand() % (larguraFase - 150)) + 50.f;
            float randY = alturaFase - 60.f; // no chão, igual às plataformas

            Lama* lama = new Lama(randX, randY, 80.f);
            listaE.incluir(static_cast<Entidade*>(lama), true);
            GC.incluirObstcaulo(lama);
        }
    }

    void FasePrimeira::criarInimigos() {
        criarAlmasPenadas();
        criarBanshees();
    }

    void FasePrimeira::criarObstaculo() {
        criarPlataformas();
        criarLamas();
    }


    void FasePrimeira::incluirJogadores(Jogador* pJog1, Jogador* pJog2) {
        Fase::incluirJogadores(pJog1, pJog2);
        pJog1->setPosition(sf::Vector2f(50.f, alturaFase - 80.f));
        if (pJog2)
            pJog2->setPosition(sf::Vector2f(800.f, alturaFase - 80.f));
    }

    void FasePrimeira::inicializaFase() {
        criarObstaculo();
        criarInimigos();
    }

    void FasePrimeira::executar(sf::RenderWindow* janela) {
        minhaSala.desenhar(*janela);
        listaE.percorrer();
        // resolver colisões entre as entidades
        GC.executar();
        listaE.desenhaTodos(*janela); // Nota: foi necessário separar a colisão e a renderização em duas funções diferentes
        listaE.limparMortos();
    }

}