#pragma once
#include <vector>
#include <list>
#include <set>
#include "../Entidades/Entidade.h"
#include "../Entidades/Personagens/Jogador.h"
#include "../Entidades/Personagens/Inimigo.h"
#include "../Entidades/Obstaculos/Obstaculo.h"
#include "../Entidades/Bloco/Sala.h" 

namespace Principal {
    class Gerenciador_Colisoes {
    private:
        std::vector<Inimigo*>   LIs;
        std::list<Obstaculo*>   LOs;
        //std::set<Projetil*>     LPs;
        Sala* minhaSala; 
        Jogador* pJog1; 
        Jogador* pJog2; 

        const bool verificarColisao(Entidade* pe1, Entidade* pe2) const;
        void tratarColisoesJogsObstacs();
        void tratarColisoesJogsInimgs();
        void tratarColisoesJogsProjeteis();
        void tratarColisoesEntsSala();

    public:
        void setJogador1(Jogador* p);
        void setJogador2(Jogador* p);
        Gerenciador_Colisoes();
        ~Gerenciador_Colisoes();

        void setSala(Sala* pS);

        void incluirInimigo(Inimigo* pi);
        void incluirObstcaulo(Obstaculo* po);
        //void incluirProjetil(Projetil* pj);
        void executar();
    };
}

