#include "Fase.h"
#include "../Entidades/Personagens/Alma.h"
#include "../Entidades/Entidade.h"
#include "../Entidades/Obstaculos/Plataforma.h"
#include "../Ente.h"
#include "../Gerenciadores/GerenciadorGrafico.h"

#include <cstdlib> // usado para a função rand. talvez gere problemas e precise ser trocado por <stdlib.h>
#include <time.h> // usado para a função rand com o tempo

namespace Principal {
    Fase::Fase()
    : maxAlmas(5), maxPlataformas(5) {

    }

    Fase::~Fase() {
        // ...
    }
    // Esvazia a lista e desaloca entidades
    void Fase::limpaFase() {
        listaE.limpar();
    }

    // Cria inimigos fáceis
    void Fase::criarAlmasPenadas() {
        sementear();
        int qtd = rand() % (maxAlmas + 1 - 3) + 3; // Valor da direita é o mínimo
        int i;

        for (i = 0; i < qtd; i++) {
            Alma* inimigo = new Alma;
            listaE.incluir(static_cast<Entidade*>(inimigo), true); // talvez dê erro // não lembro por que pudesse dar erro, mas chuto que seja por causa do static_cast
            // PRECISA DEFINIR POSIÇÃO ALEATÓRIA
        }
    }

    // Cria obstáculo 1 (plataformas)
    void Fase::criarPlataformas() {
        sementear();
        int qtd = rand() % (maxPlataformas + 1 - 3) + 3;
        int i;

        for (i = 0; i < qtd; i++) {
            sementear();

            // Coordenadas aleatórias não testadas. formato: (... - (d)) + distancia minima, onde d = distancia maxima + distancia minima
            float randX = rand() % (int)((Ente::getGG()->getLargura() - 200.0f) + 100.0f); //
            float randY = rand() % (int)((Ente::getGG()->getAltura() - 500.0f) + 400.0f); // INT PARA FLOAT PODE DAR PROBLEMA

            Plataforma* plat = new Plataforma(randX, randY, 100.0f);
            listaE.incluir(static_cast<Entidade*>(plat), true); // talvez dê erro // não lembro por que pudesse dar erro, mas chuto que seja por causa do static_cast
        }
    }

    // ainda não sei o que fazer com essa função. não vou retirar pois está no diagrama,
    // porém o que eu imagino que seja a utilidade dela (criar o background), vai ser feito
    // em cada fase individual por meio da classe Sala
    void Fase::criarCenario() {
        // Do something...
    }

    // Inclui jogadores na lista. Não deve ser chamada mais do que uma vez !!!
    void Fase::incluirJogadores(Jogador* pJog1, Jogador* pJog2) {
        listaE.incluir(pJog1, false);
        GC.setJogador1(pJog1);
        if (pJog2) {
            listaE.incluir(pJog2, false);
            GC.setJogador2(pJog2);            
        }
    }

    // CÓDIGO INSPIRADO NA FUNÇÃO SEMENTAR FORNECIDA NAS PROVAS DE TECPROG
    // Nota: não foi testado se está funcionando. Na dúvida, pesquise no google ou pegue o código 100% dos exemplos do professor (com cŕeditos é claro ;D)
    void Fase::sementear() {
        time_t t;
        srand(time(&t)); // talvez dê problema com tempo negativo (se existir essa coisa legal!!!)
    }
}