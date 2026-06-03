#include "Entidade.h"

namespace Principal {
    Entidade::Entidade() : x(0.f), y(0.f) {
        corpo.setPosition(x, y); // posiciona o corpo na origem ao criar
    }

    Entidade::~Entidade() {}

    // Desenha o corpo retangular na janela
    void Entidade::desenhar(sf::RenderWindow& window) {
        window.draw(corpo);
    }

    void Entidade::salvarDataBuffer() {}

    sf::RectangleShape& Entidade::getCorpo() { // Retorna o corpo para quem precisar acessar
        return corpo;
    }

    sf::Vector2f Entidade::getPosicao() const {
        return corpo.getPosition(); // Retorna a posição atual do corpo na tela
    }
}