#include "Fase.h"
#include "../Entidades/Personagens/Alma.h"
#include "../Entidades/Entidade.h"
#include "../Entidades/Obstaculos/Plataforma.h"
#include "../Ente.h"
#include "../Gerenciadores/GerenciadorGrafico.h"
#include <cstdlib>
#include <ctime>
#include <cmath>
namespace Principal {
    Fase::Fase()
    : maxAlmas(5), maxPlataformas(5),
        pJog1(nullptr), pJog2(nullptr) {
        sementear();

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
        //sementear();
        int qtd = rand() % (maxAlmas + 1 - 3) + 3;


        for (int i = 0; i < qtd; i++) {
            //();
			float randX = (float)(rand() % 700) + 50.f; // posição aleatória dentro de uma área
            float randY = (float)(alturaFase - 60.f);  // posição aleatória dentro de uma área 

			Alma* inimigo = new Alma(randX, randY); // posição aleatória dentro de uma área 
            inimigo->setAlvo(pJog1); // Define jogador como alvo
			listaE.incluir(static_cast<Entidade*>(inimigo), true); // talvez dê erro // não lembro por que pudesse dar erro, mas chuto que seja por causa do static_cast
            GC.incluirInimigo(inimigo); // registra no GC para colisão
        }
    }


    // Cria obstáculo 1 (plataformas)
    void Fase::criarPlataformas() {
        //sementear();
        int qtd = rand() % (maxPlataformas + 1 - 3) + 3;
        int i;
		float espaco = (larguraFase - 100) / qtd; // para distribuir as plataformas ao longo da fase, com uma margem de 50 em cada lado

        for (i = 0; i < qtd; i++) {
            //sementear();

            // Coordenadas aleatórias não testadas. formato: (... - (d)) + distancia minima, onde d = distancia maxima + distancia minima
			float randX = (int)(50.f + (i * espaco) + (rand() % 100)); // posição aleatória dentro de uma área, com espaçamento para distribuir as plataformas ao longo da fase
            float randY = rand() % (int)(rand() % 300) + (alturaFase - 400.f); // INT PARA FLOAT PODE DAR PROBLEMA

            float largura = (float)(rand() % 100) + 150.f;
            float altura = 40.f;

            Plataforma* plat = new Plataforma(randX, randY, largura, altura);
            listaE.incluir(static_cast<Entidade*>(plat), true); // talvez dê erro // não lembro por que pudesse dar erro, mas chuto que seja por causa do static_cast
            GC.incluirObstcaulo(plat); // registra no GC para colisão        
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
        this->pJog1 = pJog1;
        this->pJog2 = pJog2;
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