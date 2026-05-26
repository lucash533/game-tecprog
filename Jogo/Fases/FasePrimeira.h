#pragma once
#include "Fase.h"

class FasePrimeira : public Fase {
private:
    const int maxAlmaPenada;

protected:
    void criarBanshees();
    void criarObstMedios(); // Atualizar nome

public:
    FasePrimeira();
    ~FasePrimeira();



};