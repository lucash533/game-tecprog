#pragma once

class Fase {
private:

protected:
    //ListaEntidades lista_ents;
    //GerenciadorColisoes GC;

    void criarGhouls(); 
    void criarPlataformas();
    void criarCenario();

    virtual void criarInimigos() = 0;
    virtual void criarObstaculo() = 0;

public:
    Fase();
    virtual ~Fase();

    virtual void executar();

};