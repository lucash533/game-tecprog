#include "GerenciadorColisao.h"
#include "../Ente.h"
#include <cmath>
 
namespace Principal {
    GerenciadorColisao::GerenciadorColisao() : pJog1(nullptr), pJog2(nullptr) {}
    GerenciadorColisao::~GerenciadorColisao() {}

    void GerenciadorColisao::setSala(Sala* pS) {minhaSala = pS;}

    void GerenciadorColisao::incluirInimigo(Inimigo* pi) { LIs.push_back(pi); }
    void GerenciadorColisao::incluirObstcaulo(Obstaculo* po) { LOs.push_back(po); }
    //void GerenciadorColisao::incluirProjetil(Projetil* pj) { LPs.insert(pj); }

    const bool GerenciadorColisao::verificarColisao(Entidade* pe1, Entidade* pe2) const {
        // ====================================================== //
        // Código tirado de video do monitor Giovane Limas Salvi //
        // ==================================================== //

        
        sf::Vector2f pos1 = pe1->getPosicao();
        sf::Vector2f pos2 = pe2->getPosicao();
        sf::Vector2f tam1 = pe1->getTam();
        sf::Vector2f tam2 = pe2->getTam();

        float distX = fabs((pos1.x + tam1.x / 2.f) - (pos2.x + tam2.x / 2.f));
        float distY = fabs((pos1.y + tam1.y / 2.f) - (pos2.y + tam2.y / 2.f));

        float somaX = tam1.x / 2.f + tam2.x / 2.f;
        float somaY = tam1.y / 2.f + tam2.y / 2.f;

        return (distX < somaX && distY < somaY);
    }

    void GerenciadorColisao::tratarColisoesJogsObstacs() {
        for (std::list<Obstaculo*>::iterator it = LOs.begin(); it != LOs.end(); ++it) {
            Obstaculo* obs = *it;
            if (obs->getVivo() && verificarColisao(pJog1, obs))
                obs->obstacularizar(pJog1); // obstáculo decide o que fazer com o jogador
        }
    }

    void GerenciadorColisao::tratarColisoesJogsInimgs()
    {
        for (std::vector<Inimigo*>::iterator it = LIs.begin(); it != LIs.end(); ++it)
        {
            Inimigo* ini = *it;
            if (ini->getVivo() && verificarColisao(pJog1, ini))
            {
                sf::FloatRect rJog = pJog1->getCorpo().getGlobalBounds();
                sf::FloatRect rIni = ini->getCorpo().getGlobalBounds();

                float peJog = rJog.top + rJog.height; // posição do "pé" do jogador (parte inferior)
                float topoIni = rIni.top; // posição do topo do inimigo (parte superior)

                if (peJog <= topoIni + 5.f)
                {
                    // jogador pisou em cima
                    ini->setVivo(false);
                    pJog1->adicionarPontos(100);
                    pJog1->pousar();
                }
                else
                    ini->danificar(pJog1);  // colisão de lado
            }
        }
    }

    void GerenciadorColisao::setJogador1(Jogador* p) { pJog1 = p; }
    void GerenciadorColisao::setJogador2(Jogador* p) { pJog2 = p; }
    void GerenciadorColisao::tratarColisoesJogsProjeteis() { /* a implementar */ }

    void GerenciadorColisao::tratarColisoesEntsSala() {
        if (pJog1)
            minhaSala->limitar(pJog1);
        //if (pjog2)
    }

    void GerenciadorColisao::executar() {
        //tratarColisoesJogsObstacs();
        //tratarColisoesJogsInimgs();
        //tratarColisoesJogsProjeteis();
        tratarColisoesEntsSala();
    }
}


