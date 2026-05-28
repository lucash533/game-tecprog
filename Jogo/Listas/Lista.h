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

        void incluir(TL* p);
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
        if (d) // ATENTAR-SE A D !!!
            delete pInfo;
        pProx = NULL;
        pInfo = NULL;
    }

    template<class TL>
    typename Lista<TL>::Elemento* Lista<TL>::Elemento::getProx() const {

    }
    
}