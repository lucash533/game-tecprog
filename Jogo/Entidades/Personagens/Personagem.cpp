#include "Personagem.h"

Personagem::Personagem() : num_vidas(3), velY(0.f), noChao(false) {
}

Personagem::~Personagem() {}

void Personagem::salvarDataBuffer() {}

void Personagem::aplicarGravidade() {
    if (!noChao) {
		velY += 0.5f; // acelera para baixo enquanto estiver fora do chão
    }
    corpo.move(0.f, velY); // aplica a velocidade vertical no corpo
    noChao = false; // reseta noChao
}


void Personagem::setPosition(sf::Vector2f pos) {
    corpo.setPosition(pos); // Reposiciona o corpo e sincroniza x,y 
    x = pos.x;
    y = pos.y;
}

sf::Vector2f Personagem::getPosicao() {
    return corpo.getPosition();
}





