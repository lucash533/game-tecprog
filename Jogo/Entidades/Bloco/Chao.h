#pragma once
#include "../Obstaculos/Obstaculo.h"

namespace Jogo {
    class Chao : public Obstaculo {
    public:
        Chao(float x, float y, float largura);
        ~Chao();
        void executar();
        void salvar();
        void obstaculizar(Jogador* p);

    };
}
