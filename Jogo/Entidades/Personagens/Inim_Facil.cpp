#include "Inim_Facil.h"
#include <cmath>

Inim_Facil::Inim_Facil() : raio(300.0f), alvo(nullptr)
{
	nivel_maldade = 1;
	corpo.setSize(sf::Vector2f(40, 40));
	corpo.setFillColor(sf::Color::Red);
	corpo.setPosition(sf::Vector2f(100, 100)); // posição inicial padrão
	vel = sf::Vector2f(3.0f, 0.0f); // velocidade horizontal base
}
Inim_Facil::Inim_Facil(float x, float y) : raio(300.0f), alvo(nullptr)
{
    nivel_maldade = 1;
    corpo.setSize(sf::Vector2f(40, 40));
    corpo.setFillColor(sf::Color::Red);
    corpo.setPosition(sf::Vector2f(x, y));
    vel = sf::Vector2f(3.0f, 0.0f);
}

Inim_Facil::~Inim_Facil() {}

void Inim_Facil::executar() { mover(); }

void Inim_Facil::mover()
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
    aplicarGravidade();  // cai com gravidade igual ao jogador


}
// Move horizontalmente na direção do jogador
void Inim_Facil::perseguir(sf::Vector2f pos_alvo, sf::Vector2f pos_inimigo) //Referencia: https://www.youtube.com/watch?v=HXFTzs7jzJ8&list=PLR17O9xbTbIBBoL3lli44N8LdZVvg-_uZ&index=3
{ 
    if (pos_alvo.x - pos_inimigo.x > 0)
        corpo.move(vel.x, 0);  // jogador está à direita
    else
        corpo.move(-vel.x, 0); // jogador está à esquerda
}

void Inim_Facil::danificar(Jogador* p) {}
void Inim_Facil::salvar() {}


