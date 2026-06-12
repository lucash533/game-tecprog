#include "FasePrimeira.h"
#include "../Entidades/Personagens/Banshee.h"
//#include "../Entidades/" // LAMA

namespace Principal {
    FasePrimeira::FasePrimeira() : maxBanshee(8), minhaSala(alturaFase, larguraFase), maxObstaculoLama(5) {
        GC.setSala(&minhaSala);
    }

    FasePrimeira::~FasePrimeira() {
        
    }

    // Cria inimigos médios
    // VIDE criarAlmas() DA CLASSE FASE PARA PEGAR INSPIRAÇÕES !!!
    void FasePrimeira::criarBanshees() {
        //sementear();
        int qtd = rand() % (maxBanshee + 1 - 3) + 3;
        int i;

        for (i = 0; i < qtd; i++) {
            Banshee* inimigo = new Banshee;
            listaE.incluir(static_cast<Entidade*>(inimigo), true); // talvez dê erro
            // PRECISA DEFINIR POSIÇÃO ALEATÓRIA
        }
    }

    // VIDE criarPlataformas() DA CLASSE FASE PARA PEGAR INSPIRAÇÕES !!!
    // Cria lamas

    void FasePrimeira::criarLamas() {
        //sementear();
        int qtd = rand() % 3 + 2;

        for (int i = 0; i < qtd; i++) {
            //sementear();
            float randX = (float)(rand() % (larguraFase - 150)) + 50.f;
            float randY = (float)(alturaFase - 40.f); // no chão, igual às plataformas

            Lama* lama = new Lama(randX, randY, 80.f);
            listaE.incluir(static_cast<Entidade*>(lama), true);
            GC.incluirObstcaulo(lama);
        }
    }

    void FasePrimeira::criarInimigos() {
        criarAlmasPenadas();
        //criarBanshees();
    }

    void FasePrimeira::criarObstaculo() {
        criarPlataformas();
        criarLamas();
    }

    void FasePrimeira::incluirJogadores(Jogador* pJog1, Jogador* pJog2) {
        Fase::incluirJogadores(pJog1, pJog2);
        pJog1->setPosition(sf::Vector2f(50.f, alturaFase - 80.f));
        if (pJog2)
            pJog2->setPosition(sf::Vector2f(100.f, alturaFase - 80.f));
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