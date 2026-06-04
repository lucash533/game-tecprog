
#pragma once

namespace Principal {

    template <class TL>
    class Lista {
    public:
        // Classe aninhada Elemento de objetos da lista
        class Elemento { // 
        public: // private
            Elemento* pProx;
            TL* pInfo;
            bool dinamico;

        public:
            Elemento(bool d);
            ~Elemento();

            void incluir(TL* p); //const 
            void setProx(Elemento* pE); //const 
            Elemento* getProx() const;

            TL* getInfo() const { return pInfo; }
        };

        // Demais atributos privados
    private:
        Elemento* pPrimeiro;
        Elemento* pUltimo;

    public:
        Lista();
        virtual ~Lista();
        Elemento* getPrimeiro() const { return pPrimeiro; }
        Elemento* getUltimo() const { return pUltimo; }
        void incluir(TL* p, bool d);
        void limpar();
        void remover(TL* elemento);
        //void executar();
    };

    // ============================================= //
    // =============== IMPLEMENTAÇÃO =============== //
    // ============================================= //

    // Implementação das funções do Elemento
    template<class TL>
    Lista<TL>::Elemento::Elemento(bool d)
        : pProx(nullptr), pInfo(nullptr), dinamico(d) {
        // do something...
    }

    template<class TL>
    Lista<TL>::Elemento::~Elemento() {
        if (pInfo) {
            if (dinamico) // ATENTAR-SE A D !!! (pode ser que cause problemas mais tarde)
                delete pInfo;
        }
        //if (pInfo)
        //    delete pInfo;
        pProx = nullptr;
        pInfo = nullptr;
    }

    // Retorna prox
    template<class TL>
    typename Lista<TL>::Elemento* Lista<TL>::Elemento::getProx() const {
        return pProx;
    }

    // Define prox
    template<class TL>
    void Lista<TL>::Elemento::setProx(Elemento* pE) {
        pProx = pE;
    }

    // Define o elemento apontado por pInfo
    template<class TL>
    void Lista<TL>::Elemento::incluir(TL* p) {
        pInfo = p;
    }


    // Implementação das funções da Lista
    template<class TL>
    Lista<TL>::Lista()
        : pPrimeiro(nullptr), pUltimo(nullptr) {
        limpar();
    }

    template<class TL>
    Lista<TL>::~Lista() {
        limpar();
    }

    // Inclui info na lista
    template<class TL>
    void Lista<TL>::incluir(TL* p, bool d) {
        Elemento* pE = new Elemento(d);
        if (!pE)
            return; // !!!
        pE->incluir(p);

        // Confere se há algum elemento na lista
        if (!(pPrimeiro && pUltimo)) {
            pPrimeiro = pE;
            pUltimo = pE;
            //return;
        }
        else {
            //Elemento* pAux = pPrimeiro;

            // Navega até o final
            //while (pAux != pUltimo) {
            //    pAux = pAux->getProx;
            //}
            //pAux->setProx(pE);
            pUltimo->setProx(pE); // Não foi sugerido, pode acarretar problemas
            pUltimo = pE;
        }
    }

    // Esvazia lista e desaloca elementos
    template<class TL>
    void Lista<TL>::limpar() {
        Elemento* pAux = pPrimeiro;

        while (pAux != nullptr) {
            Elemento* pPrev = pAux;
            pAux = pAux->getProx();
            delete pPrev; // elemento dinamico será desalocado na propria destrutoria de Elemento
        }

        pPrimeiro = nullptr;
        pUltimo = nullptr;
    }

    template<class TL>
    void Lista<TL>::remover(TL* elemento) {
        Elemento* pAtual = pPrimeiro;
        Elemento* pAnterior = NULL;

        while (pAtual->getInfo() != elemento &&
               pAtual != NULL) {
            pAnterior = pAtual;
            pAtual = pAtual->getProx();
           }
        if (pAtual->getInfo() == elemento) {
            pAnterior->setProx(pAtual->getProx());
            if (pAtual->dinamico)
                delete pAtual->getInfo();
            delete pAtual;
        }
    }
}