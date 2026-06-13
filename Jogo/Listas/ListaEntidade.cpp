#include "ListaEntidade.h"

namespace Principal {
    ListaEntidades::ListaEntidades() {}
    ListaEntidades::~ListaEntidades() {}

    void ListaEntidades::incluir(Entidade* pE, bool d)
    {
        LEs.incluir(pE, d);
    }

    // Percorre e executa elementos
    void ListaEntidades::percorrer()
    {
        Lista<Entidade>::Elemento* pElem = LEs.getPrimeiro();
        while (pElem != nullptr)
        {
            Entidade* pE = pElem->getInfo();
            if (pE)
            {
                pE->executar();
            }
            pElem = pElem->getProx();
        }
    }

    // Percorre e desenha elementos
    void ListaEntidades::desenhaTodos(sf::RenderWindow& janela) {
        Lista<Entidade>::Elemento* pElem = LEs.getPrimeiro();
        while (pElem != nullptr)
        {
            Entidade* pE = pElem->getInfo();
            if (pE)
            {
                pE->desenhar(janela); //
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
            if (pElem->dinamico && pElem->getInfo() && !pElem->getInfo()->getVivo()) {
                LEs.remover(pE); // Remove a entidade morta da lista
            }
            pElem = pProx;
        }
    }
}
