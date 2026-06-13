#pragma once
#include "Fase.h"

namespace Principal {
    class FaseSegunda : public Fase {
    private:
        const int maxArmadilhas;
        const int maxPisadeira;

    protected:
        void criarPisadeiras();
        void criarObstDificeis();
        void criarProjeteis();

    public:
        FaseSegunda();
        ~FaseSegunda();

    };
}