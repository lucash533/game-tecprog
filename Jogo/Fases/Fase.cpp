#include "Fase.h"
#include "../Entidades/Personagens/Alma.h"
#include "../Entidades/Entidade.h"
#include "../Entidades/Obstaculos/Plataforma.h"
#include "../Ente.h"
#include "../Gerenciadores/GerenciadorGrafico.h"
#include <cstdlib> //talvez errado .h //stdlib.h
#include <time.h>

namespace Principal {
    Fase::Fase()
    : maxAlmas(5), maxPlataformas(5) {
        //criarAlmasPenadas();
    }

    Fase::~Fase() {
        // ...
    }

    void Fase::limpaFase() {
        listaE.limpar();
    }

    // Cria inimigos fáceis
    void Fase::criarAlmasPenadas() {
        sementear();
        int qtd = rand() % (maxAlmas + 1 - 3) + 3;
        int i;

        for (i = 0; i < qtd; i++) {
            Alma* inimigo = new Alma;
            listaE.incluir(static_cast<Entidade*>(inimigo), true); // talvez dê erro
            // PRECISA DEFINIR POSIÇÃO ALEATÓRIA
        }
    }

    // Cria obstáculo 1 (plataformas)
    void Fase::criarPlataformas() {
        sementear();
        int qtd = rand() % (maxPlataformas + 1 - 3) + 3;
        float randX = rand() % (int)((Ente::getGG()->getLargura() - 200.0f) + 100.0f); //
        float randY = rand() % (int)((Ente::getGG()->getAltura() - 500.0f) + 400.0f); // INT PARA FLOAT PODE DAR PROBLEMA
        int i;

        for (i = 0; i < qtd; i++) {
            Plataforma* plat = new Plataforma(randX, randY, 100.0f);
            listaE.incluir(static_cast<Entidade*>(plat), true); // talvez dê erro
        }
    }

    // ???
    void Fase::criarCenario() {
        //...
    }

    void Fase::executar() {
        listaE.percorrer(*Ente::getGG()->getJanela());
    }

    void Fase::incluirJogadores(Jogador* pJog1, Jogador* pJog2) {
        listaE.incluir(pJog1, false);
        if (pJog2)
            listaE.incluir(pJog2, false);
    }

    // CÓDIGO INSPIRADO NA FUNÇÃO SEMENTAR FORNECIDA NAS PROVAS DE TECPROG
    void Fase::sementear() {
        time_t t;
        srand(time(&t)); // talvez dê problema com tempo negativo (se existir essa coisa legal!!!)
    }
}