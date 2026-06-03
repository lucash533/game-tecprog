#include "ListaEntidade.h"

namespace Principal {
    ListaEntidades::ListaEntidades() {}
    ListaEntidades::~ListaEntidades() {}

    void ListaEntidades::incluir(Entidade* pE)
    {
        LEs.incluir(pE, false);
    }

    void ListaEntidades::percorrer(sf::RenderWindow& window)
    {
        Lista<Entidade>::Elemento* pElem = LEs.getPrimeiro();
        while (pElem != nullptr)
        {
            Entidade* pE = pElem->getInfo();
            if (pE)
            {
                pE->executar();
                pE->desenhar(window);
            }
            pElem = pElem->getProx();
        }
    }
}
