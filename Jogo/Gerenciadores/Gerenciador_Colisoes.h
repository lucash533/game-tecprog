#pragma once
#include <vector>
#include <list>
#include <set>
#include "../Entidades/Entidade.h"
#include "../Entidades/Personagens/Jogador.h"
#include "../Entidades/Personagens/Inimigo.h"
#include "../Entidades/Obstaculos/Obstaculo.h"

namespace Principal {
    namespace Gerenciador {

        class Gerenciador_Colisoes {
        private:
            std::vector<Inimigo*>   LIs;
            std::list<Obstaculo*>   LOs;
            //std::set<Projetil*>     LPs;
            Jogador* pJog1;

            const bool verificarColisao(Entidade* pe1, Entidade* pe2) const;
            void tratarColisoesJogsObstacs();
            void tratarColisoesJogsInimgs();
            void tratarColisoesJogsProjeteis();

        public:
            void setJogador(Jogador* p);
            Gerenciador_Colisoes();
            ~Gerenciador_Colisoes();

            void incluirInimigo(Inimigo* pi);
            void incluirObstcaulo(Obstaculo* po);
            //void incluirProjetil(Projetil* pj);
            void executar();
        };

    }
}

