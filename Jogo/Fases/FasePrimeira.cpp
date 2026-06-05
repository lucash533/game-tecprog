#include "FasePrimeira.h"
#include "../Entidades/Personagens/Banshee.h"
//#include "../Entidades/" // OBSTACULO MEDIO
//#include <cstdlib>

namespace Principal {
    FasePrimeira::FasePrimeira() : maxBanshee(5), minhaSala(alturaFase, larguraFase) {
        GC.setSala(&minhaSala);
    }

    FasePrimeira::~FasePrimeira() {
        
    }

    // Cria inimigos médios
    void FasePrimeira::criarBanshees() {
        sementear();
        int qtd = rand() % (maxBanshee + 1 - 3) + 3;
        int i;

        for (i = 0; i < qtd; i++) {
            Banshee* inimigo = new Banshee;
            listaE.incluir(static_cast<Entidade*>(inimigo), true); // talvez dê erro
            // PRECISA DEFINIR POSIÇÃO ALEATÓRIA
        }
    }

    // Cria obstáculos médios (ainda sem identidade)
    void FasePrimeira::criarLamas() {
        sementear();
        //int qtd = rand() % (maxPlataformas + 1 - 3) + 3;
        //float randX = rand() % (int)((Ente::getGG()->getLargura() - 200.0f) + 100.0f); //
        //float randY = rand() % (int)((Ente::getGG()->getAltura() - 400.0f) + 300.0f); // INT PARA FLOAT PODE DAR PROBLEMA
        int i;

        //for (i = 0; i < qtd; i++) {
        //    Plataforma* plat = new Plataforma(randX, randY, 100.0f);
        //    listaE.incluir(static_cast<Entidade*>(plat)); // talvez dê erro
        //}
    }

    void FasePrimeira::criarInimigos() {
        criarAlmasPenadas();
        //criarBanshees();
    }

    void FasePrimeira::criarObstaculo() {
        criarPlataformas();
        //criar obstaculo medio
    }

    void FasePrimeira::incluirJogadores(Jogador* pJog1, Jogador* pJog2) {
        listaE.incluir(pJog1, false);
        GC.setJogador1(pJog1);
        pJog1->setPosition(sf::Vector2f(larguraFase + 100.f, alturaFase + 100.f));

        if (pJog2) {
            listaE.incluir(pJog2, false);
            GC.setJogador2(pJog2);        
            // definir posição    
        }
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
        listaE.desenhaTodos(*janela);
    }

}