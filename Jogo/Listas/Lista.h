#pragma once

namespace Jogo {

    template <class TL>
    class Lista {
    private:
    // Classe aninhada Elemento de objetos da lista
        class Elemento { // 
        private:
            Elemento* pProx; 
            TL* pInfo; 
            bool dinamico;

        public:
            Elemento(bool d);
            ~Elemento();

            void incluir(TL* p); //const 
            void setProx (Elemento* pE); //const 
            Elemento* getProx() const;
        };
    
    // Demais atributos privados
    private:
        Elemento<TL>* pPrimeiro;
        Elemento<TL>* pUltimo;

    public:
        Lista();
        virtual ~Lista();  

        void incluir(TL* p, bool d);
        void limpar();
        //void executar();
    };

    // ============================================= //
    // =============== IMPLEMENTAÇÃO =============== //
    // ============================================= //

    // Implementação das funções do Elemento
    template<class TL>
    Lista<TL>::Elemento::Elemento(bool d)
     : pProx(NULL), pInfo(NULL), dinamico(d) {
        // do something...
    }

    template<class TL>
    Lista<TL>::Elemento::~Elemento() {
        if (pInfo) {
            if (d) // ATENTAR-SE A D !!! (pode ser que cause problemas mais tarde)
                delete pInfo;
        }
        //if (pInfo)
        //    delete pInfo;
        pProx = NULL;
        pInfo = NULL;
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
     : pPrimeiro(NULL), pUltimo(NULL) {
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

        while (pAux != NULL) {
            Elemento* pPrev = pAux;
            pAux = pAux->getProx();
            delete pPrev; // elemento dinamico será desalocado na propria destrutoria de Elemento
        }

        pPrimeiro = NULL;
        pUltimo = NULL;
    }
}