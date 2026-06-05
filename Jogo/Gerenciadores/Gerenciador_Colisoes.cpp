#include "Gerenciador_Colisoes.h"
#include "../Ente.h"
 
namespace Principal {
    namespace Gerenciador {
        Gerenciador_Colisoes::Gerenciador_Colisoes() : pJog1(nullptr) {}
        Gerenciador_Colisoes::~Gerenciador_Colisoes() {}
 
        void Gerenciador_Colisoes::incluirInimigo(Inimigo* pi) { LIs.push_back(pi); }
        void Gerenciador_Colisoes::incluirObstcaulo(Obstaculo* po) { LOs.push_back(po); }
        //void Gerenciador_Colisoes::incluirProjetil(Projetil* pj) { LPs.insert(pj); }
 
        const bool Gerenciador_Colisoes::verificarColisao(Entidade* pe1, Entidade* pe2) const {
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
 
        void Gerenciador_Colisoes::tratarColisoesJogsObstacs() {
            for (std::list<Obstaculo*>::iterator it = LOs.begin(); it != LOs.end(); ++it) {
                Obstaculo* obs = *it;
                if (obs->getVivo() && verificarColisao(pJog1, obs))
                    obs->obstacularizar(pJog1); // obstáculo decide o que fazer com o jogador
            }
        }
 
        void Gerenciador_Colisoes::tratarColisoesJogsInimgs()
        {
            for (std::vector<Inimigo*>::iterator it = LIs.begin(); it != LIs.end(); ++it)
            {
                Inimigo* ini = *it;
                if (ini->getVivo() && verificarColisao(pJog1, ini))
                {
                    sf::FloatRect rJog = pJog1->getCorpo().getGlobalBounds();
                    sf::FloatRect rIni = ini->getCorpo().getGlobalBounds();

                    // jogador veio de cima se o pé dele está perto do topo do inimigo
                    float peJog = rJog.top + rJog.height;
                    float topoIni = rIni.top;

                    if (peJog <= topoIni + 15.f)  // margem de 15px
                    {
                        ini->danificar(pJog1);  // inimigo morre
                        pJog1->adicionarPontos(100);
                        pJog1->pousar();  // jogador quica em cima
                    }
                    else
                        ini->danificar(pJog1);  // jogador leva dano
                }
            }
        }
 
        void Gerenciador_Colisoes::setJogador(Jogador* p) { pJog1 = p; }
        void Gerenciador_Colisoes::tratarColisoesJogsProjeteis() { /* a implementar */ }
 
        void Gerenciador_Colisoes::executar() {
            tratarColisoesJogsObstacs();
            tratarColisoesJogsInimgs();
            tratarColisoesJogsProjeteis();
        }
    }
}


