#pragma once
#include "../Listas/ListaEntidade.h"
#include "../Entidades/Personagens/Jogador.h"
//#include "../Entidades/Bloco/Sala.h"

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
        void criarCenario(); // escolher imagem

        virtual void criarInimigos() = 0;
        virtual void criarObstaculo() = 0;


        void sementear();

    public:
        Fase();
        virtual ~Fase();

        virtual void inicializaFase() = 0;
        void limpaFase();
        // salvaFase() carregaFase()

        void incluirJogadores(Jogador* pJog1, Jogador* pJog2 = NULL);

        virtual void executar();

    };
}