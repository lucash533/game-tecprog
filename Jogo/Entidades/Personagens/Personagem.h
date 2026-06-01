#pragma once
#include "../Entidade.h"


class Personagem : public Entidade {
protected:

    sf::Vector2f vel; // velocidade horizontal (x) e vertical (y) base
    int num_vidas;  // quantidade de vidas
    float velY;  // velocidade vertical atual (afetada pela gravidade)
    bool noChao; // controla se pode pular e se aplica gravidade

public:
    Personagem();
    virtual ~Personagem();

    void salvarDataBuffer();
    virtual void executar() = 0;
    virtual void salvar() = 0;
    virtual void mover() = 0;
	void pousar(); // chamada quando o personagem colidir com o chão, para resetar o pulo
    void aplicarGravidade(); // aumenta velY e move o corpo para baixo
    void setPosition(sf::Vector2f pos); // reposiciona o corpo
};


