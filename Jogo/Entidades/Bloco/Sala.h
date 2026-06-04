#pragma once
#include "../Entidade.h"

namespace Principal {
    class Sala {
    private:
        const int altura;
        const int largura;

    public:
        Sala(int alturaFornecida, int larguraFornecida);
        ~Sala();

        void limitar(Entidade* ent); // pensar em talvez dar um limite externo para a sala
    };
   
}