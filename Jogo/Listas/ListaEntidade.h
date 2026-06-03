#pragma once
#include "Lista.h"
#include "../Entidades/Entidade.h"

namespace Principal {
    class ListaEntidades {
    private:
        Lista<Entidade> LEs;

    public:
        ListaEntidades();
        ~ListaEntidades();

        void incluir(Entidade* pE);
        void percorrer(sf::RenderWindow& window);
    };
}