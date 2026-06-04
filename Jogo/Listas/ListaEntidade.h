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

        void incluir(Entidade* pE, bool d);
        void percorrer(sf::RenderWindow& window);
        void limpar();
		void limparMortos(); // nova função para limpar entidades mortas
    };
}