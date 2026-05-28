#pragma once

namespace Jogo {

    template <class TL>
    class Lista {
    private:
    // Classe aninhada Elemento de objetos da lista
        template <class TE> // trocar por TL
        class Elemento<TE> {
        private:
            Elemento<TE>* pProx;
            TE* pInfo;

        public:
            Elemento();
            ~Elemento();

            void incluir(TE* p); //const
            void setProx (Elemento<TE>* pE); //const
            Elemento<TE>* const getProx();
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
    };
}