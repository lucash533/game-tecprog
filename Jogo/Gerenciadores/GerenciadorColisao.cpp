#include "GerenciadorColisao.h"
#include "../Ente.h"
#include <cmath>
 
namespace Principal {
    GerenciadorColisao::GerenciadorColisao() : pJog1(nullptr), pJog2(nullptr), minhaSala(nullptr) {}
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
        for (auto it = LOs.begin(); it != LOs.end(); ++it) {
            Obstaculo* obs = *it;
            if (obs->getVivo()) {

                // --- JOGADOR x OBSTACULO ---
                // chama obstacularizar(Jogador*) - versao do jogador
                if (pJog1 && pJog1->getVivo() && verificarColisao(pJog1, obs))
                    obs->obstacularizar(pJog1);
                if (pJog2 && pJog2->getVivo() && verificarColisao(pJog2, obs))
                    obs->obstacularizar(pJog2);


                // Lama e Armadilha: dynamic_cast retorna nullptr, nao entra no if
                // entao inimigos nao interagem com elas - so o jogador
            }
        }

    }
    void GerenciadorColisao::tratarColisoesEntidadesObstacs() {
        for (auto it = LOs.begin(); it != LOs.end(); ++it) {
            Plataforma* plat = dynamic_cast<Plataforma*>(*it);
            if (plat && plat->getVivo()) {

                // inimigos x plataforma
                for (auto* ini : LIs) {
                    if (ini->getVivo() && verificarColisao(ini, plat))
                        plat->obstacularizar((Entidade*)ini);
                }

                // outros obstáculos x plataforma
                for (auto it2 = LOs.begin(); it2 != LOs.end(); ++it2) {
                    Obstaculo* obs2 = *it2;
                    if (obs2 != plat && obs2->getVivo() && !dynamic_cast<Plataforma*>(obs2)) {  // não verifica plataforma x plataforma ou obstáculos mortos

                        if (verificarColisao(plat, obs2))
                            plat->obstacularizar((Entidade*)obs2);
                    }
                }
            }
        }
    }


    void GerenciadorColisao::tratarColisoesJogsInimgs()
    {
        for (auto it = LIs.begin(); it != LIs.end(); ++it)
        {
            Inimigo* ini = *it;
            if (ini->getVivo()) { // pula inimigos mortos 

                if (pJog1 && pJog1->getVivo() && ini->getVivo() && verificarColisao(pJog1, ini))
                {
                    sf::FloatRect rJog = pJog1->getCorpo().getGlobalBounds();
                    sf::FloatRect rIni = ini->getCorpo().getGlobalBounds();

                    float peJog = rJog.top + rJog.height; // posição do "pé" do jogador (parte inferior)
                    float topoIni = rIni.top; // posição do topo do inimigo (parte superior)

                    if (peJog >= topoIni && peJog <= topoIni + 10.f)
                    {
                        // jogador pisou em cima
                        ini->setVivo(false);
                        pJog1->adicionarPontos(100);
                        pJog1->pousar();
                    }
                    else

                        ini->danificar(pJog1);
                }
            }
        }
    }

    void GerenciadorColisao::setJogador1(Jogador* p) { pJog1 = p; }
    void GerenciadorColisao::setJogador2(Jogador* p) { pJog2 = p; }
    void GerenciadorColisao::tratarColisoesJogsProjeteis() { /* a implementar */ }

    void GerenciadorColisao::tratarColisoesEntsSala() {
        if (minhaSala) {
            if (pJog1 && pJog1->getVivo()) minhaSala->limitar(pJog1);
            if (pJog2 && pJog2->getVivo()) minhaSala->limitar(pJog2);

            for (auto* ini : LIs)
                if (ini->getVivo()) minhaSala->limitar(ini);

            for (auto it = LOs.begin(); it != LOs.end(); ++it)
                if ((*it)->getVivo()) minhaSala->limitar(*it);
        }
    }
    void GerenciadorColisao::limparMortos() {
        std::vector<Inimigo*>::iterator it = LIs.begin();
        while (it != LIs.end()) {
            if (!(*it)->getVivo())
                it = LIs.erase(it); // remove do vetor sem deletar (já foi deletado pela lista)
            else
                ++it;
        }
    }


    void GerenciadorColisao::executar() {
        limparMortos();
        tratarColisoesJogsObstacs();
        tratarColisoesJogsInimgs();
        tratarColisoesEntidadesObstacs();
        //tratarColisoesJogsProjeteis();
        tratarColisoesEntsSala();

    }
}


