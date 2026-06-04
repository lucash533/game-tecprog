#pragma once
#include "../Listas/ListaEntidade.h"

namespace Principal {
    class Fase {
    private:
        const int maxAlmas;
        const int maxPlataformas;

    protected:
        ListaEntidades listaE;
        //GerenciadorColisoes GC;

        void criarAlmasPenadas(); 
        void criarPlataformas();
        void criarCenario();

        virtual void criarInimigos() = 0;
        virtual void criarObstaculo() = 0;

        void sementear();

    public:
        Fase();
        virtual ~Fase();

        virtual void executar();

    };
}