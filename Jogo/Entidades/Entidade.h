#pragma once
#include "../Ente.h"
#include <SFML/Graphics.hpp>
#include <sstream>

namespace Jogo {
    // Entidade adiciona forma visual e posição ao Ente
    class Entidade : public Ente {
    protected:
        float x, y;  // posição
        sf::RectangleShape corpo;  // forma retangular que representa o objeto na tela
        //std::ostream buffer; Implementar depos, não sei o que fazer com isso

    public:
        Entidade();
        virtual ~Entidade();

        virtual void executar() = 0;
        virtual void desenhar(sf::RenderWindow& window); // desenha o corpo na janela
        virtual void salvar() = 0;

        void salvarDataBuffer();
        sf::RectangleShape& getCorpo(); // retorna referência ao corpo 
        sf::Vector2f getPosicao() const;  // retorna posição atual do corpo
    };
}