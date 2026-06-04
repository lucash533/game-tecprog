#pragma once
#include "Fase.h"

namespace Principal {
    class FasePrimeira : public Fase {
    private:
        const int maxBanshee;
        //const int maxObstaculoMedio;

    protected:
        void criarBanshees();
        void criarObstMedios(); // Atualizar nome
        void criarInimigos();
        void criarObstaculo();

    public:
        FasePrimeira();
        ~FasePrimeira();

        
        void inicializaFase();
        //void limpaFase()

    };
}