#include "Alma.h"
#include <cmath>

namespace Principal {
    Alma::Alma() : raio(500.0f), alvo(nullptr)
    {
        nivel_maldade = 1;
        corpo.setSize(sf::Vector2f(40, 40));
        corpo.setFillColor(sf::Color::Red);
        corpo.setPosition(sf::Vector2f(100, 100)); // posição inicial padrão
        vel = sf::Vector2f(3.0f, 3.0f); // velocidade horizontal base
    }
    Alma::Alma(float x, float y) : raio(300.0f), alvo(nullptr)
    {
        nivel_maldade = 1;
        corpo.setSize(sf::Vector2f(40, 40));
        corpo.setFillColor(sf::Color::Red);
        corpo.setPosition(sf::Vector2f(x, y));
        vel = sf::Vector2f(3.0f, 0.0f);
    }

    Alma::~Alma() {}


    void Alma::executar() { mover(); aplicarGravidade(); }

    void Alma::mover()
    {
        if (alvo != nullptr)
        {
            sf::Vector2f pos_alvo = alvo->getCorpo().getPosition();
            sf::Vector2f pos_inimigo = corpo.getPosition();
            // só persegue se o jogador estiver dentro do raio de detecção
            if (fabs(pos_alvo.x - pos_inimigo.x) <= raio && fabs(pos_alvo.y - pos_inimigo.y) <= raio) //Referencia: https://www.youtube.com/watch?v=HXFTzs7jzJ8&list=PLR17O9xbTbIBBoL3lli44N8LdZVvg-_uZ&index=3
            {
                perseguir(pos_alvo, pos_inimigo);
            }
        }


    }
    // Move horizontalmente na direção do jogador
    void Alma::perseguir(sf::Vector2f pos_alvo, sf::Vector2f pos_inimigo) //Referencia: https://www.youtube.com/watch?v=HXFTzs7jzJ8&list=PLR17O9xbTbIBBoL3lli44N8LdZVvg-_uZ&index=3
    { 
        if (pos_alvo.x - pos_inimigo.x > 0)
            corpo.move(vel.x, 0);  // jogador está à direita
        else if (pos_alvo.x - pos_inimigo.x < 0)
            corpo.move(-vel.x, 0); // jogador está à esquerda
        if (pos_alvo.y - pos_inimigo.y > 0)
            corpo.move(0, vel.x);  // jogador está abaixo
        else if (pos_alvo.y - pos_inimigo.y < 0)
            corpo.move(0, -vel.x); // jogador está acima
    }
    void Alma::moverAletoriamente()
    {
        //a implementar
    }

    void Alma::danificar(Jogador* p) {}
    void Alma::salvar() {}
}

