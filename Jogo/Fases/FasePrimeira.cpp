#include "FasePrimeira.h"
#include "../Entidades/Personagens/Banshee.h"
//#include "../Entidades/" // OBSTACULO MEDIO
//#include <cstdlib>

namespace Principal {
    FasePrimeira::FasePrimeira() : maxBanshee(5) { //valor provisório para evitar erro
        // do saomething...
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
    void FasePrimeira::criarObstMedios() {
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
        criarBanshees();
    }

    void FasePrimeira::criarObstaculo() {
        criarPlataformas();
        //criar obstaculo medio
    }

    void FasePrimeira::inicializaFase() {
        criarObstaculo();
        criarInimigos();
    }

}