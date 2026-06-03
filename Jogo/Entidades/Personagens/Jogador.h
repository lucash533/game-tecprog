#pragma once
#include "Personagem.h"
#include <SFML/Graphics.hpp>

namespace Jogo {
    class Inimigo; 
    class Jogador : public Personagem {
    public:
        int pontos;
        Inimigo* pIn; // ponteiro para inimigo (usado na colisão futuramente)

    public:
        Jogador();
        ~Jogador();
        void colidir(Inimigo* pIn); // reação ao colidir com inimigo
        void salvar();
        void mover(); // lê teclado e move o jogador
        void executar();
        void diminuirVelocidade(); //a forma que eu vi de diminuir a velocidade do jogador caso haja o efeito da lama
        void atordoamento(); //efeito de atordoamento quando o jogador é preso na armadilha
        
    };
}
