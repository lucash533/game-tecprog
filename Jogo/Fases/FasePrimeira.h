#pragma once
#include "Fase.h"
#include "../Entidades/Bloco/Sala.h"

namespace Principal {
    class FasePrimeira : public Fase {
    private:
        const int maxBanshee;
        //const int maxObstaculoMedio;
        const int alturaFase = 700;
        const int larguraFase = 900;

        Sala minhaSala;

    protected:
        void criarBanshees();
        void criarLamas();
        void criarInimigos();
        void criarObstaculo();

    public:
        FasePrimeira();
        ~FasePrimeira();

        void incluirJogadores(Jogador* pJog1, Jogador* pJog2 = NULL);
        void inicializaFase();
        //void limpaFase()

        void executar(sf::RenderWindow* janela); // talvez precise atualizar a virtual pura

    };
}