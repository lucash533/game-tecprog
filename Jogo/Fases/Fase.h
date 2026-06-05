#pragma once
#include "../Listas/ListaEntidade.h"
#include "../Entidades/Personagens/Jogador.h"
#include "../Gerenciadores/Gerenciador_Colisoes.h"
//#include "../Entidades/Personagens/Jogador.h"
#include "../Entidades/Bloco/Sala.h"

namespace Principal {
    class Fase {
    private:
        const int maxAlmas;
        const int maxPlataformas;

    protected:
        ListaEntidades listaE;
        Gerenciador_Colisoes GC;

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

        virtual void incluirJogadores(Jogador* pJog1, Jogador* pJog2 = NULL);

        virtual void executar(sf::RenderWindow* janela) = 0;
    };
}