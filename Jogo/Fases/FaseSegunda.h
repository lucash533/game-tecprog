#pragma once
#include "Fase.h"

class FaseSegunda : public Fase {
private:
    const int maxPisadeira;

protected:
    void criarPisadeiras();
    void criarObstMedios();
    //void criarProjeteis();

public:
    FaseSegunda();
    ~FaseSegunda();

};