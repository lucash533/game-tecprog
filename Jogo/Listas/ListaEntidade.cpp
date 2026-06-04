#include "ListaEntidade.h"

namespace Principal {
    ListaEntidades::ListaEntidades() {}
    ListaEntidades::~ListaEntidades() {}

    void ListaEntidades::incluir(Entidade* pE, bool d)
    {
        LEs.incluir(pE, d);
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
                pE->desenhar(window); // mudar
            }
            pElem = pElem->getProx();
        }
    }

    void ListaEntidades::limpar() {
        LEs.limpar();
    }

	void ListaEntidades::limparMortos() {
		Lista<Entidade>::Elemento* pElem = LEs.getPrimeiro();
		Lista<Entidade>::Elemento* pProx = nullptr; // Para manter o controle do elemento anterior
		while (pElem != nullptr) {
			pProx = pElem->getProx(); // Armazena o próximo elemento antes de possivelmente remover o atual
			Entidade* pE = pElem->getInfo();
			if (pE && !pE->getVivo()) {
				LEs.remover(pE); // Remove a entidade morta da lista
			}
			pElem = pProx;
		}
	}
}
