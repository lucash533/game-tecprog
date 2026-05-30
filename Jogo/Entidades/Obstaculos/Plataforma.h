#pragma once
#include "Obstaculo.h"

class Plataforma : public Obstaculo {
public:
    Plataforma();
    ~Plataforma();

    void executar();
    void obstaculizar(Personagem& p);
    void salvar();
};

