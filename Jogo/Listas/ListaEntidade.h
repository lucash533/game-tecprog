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

        void incluir(Entidade* pE, bool d); // Inclui elemento na lista
        void percorrer(); // Percorre e executa elementos
        void desenhaTodos(sf::RenderWindow& janela); // Percorre e desenha elementos
        void limpar(); // Esvazia lista
		void limparMortos(); // nova função para limpar entidades mortas
    };
}