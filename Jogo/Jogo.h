#pragma once
#include "Entidades/Personagens/Jogador.h"


class Jogo {
private:
    //GerenciadorGrafico GG;
    Jogador pJog1; //Talvez seja um ponteiro, modelo UML está ambíguo

protected:


public:
    Jogo();
    ~Jogo();

    void executar();
};