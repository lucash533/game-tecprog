#pragma once
#include "../Entidade.h"
#include "../../Ente.h"
#include "../../Gerenciadores/GerenciadorGrafico.h"

namespace Principal {
    class Sala : public Ente {
    private:
        const int altura;
        const int largura;

        sf::RectangleShape area;

    public:
        Sala(int alturaFornecida, int larguraFornecida);
        ~Sala();

        void limitar(Entidade* ent);

        void executar() {};
        void desenhar(sf::RenderWindow& window);
    };
   
}