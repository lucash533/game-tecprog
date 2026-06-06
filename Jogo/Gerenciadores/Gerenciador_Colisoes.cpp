#include "Gerenciador_Colisoes.h"
#include "../Ente.h"



namespace Principal {
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
            for (auto it = LOs.begin(); it != LOs.end(); ++it) {
                Obstaculo* obs = *it;
                if (!obs->getVivo()) continue;

                // --- JOGADOR x OBSTACULO ---
                // chama obstacularizar(Jogador*) - versao do jogador
                if (verificarColisao(pJog1, obs))
                    obs->obstacularizar(pJog1);

                // --- INIMIGOS x PLATAFORMA ---
                // tenta converter obs para Plataforma*
                // se nao for plataforma, dynamic_cast retorna nullptr e o if nao entra
                Plataforma* plat = dynamic_cast<Plataforma*>(obs);
                if (plat) {
                    for (auto* ini : LIs) {
                        if (ini->getVivo() && verificarColisao(ini, plat)) {
                            // chama obstacularizar(Entidade*) - versao do inimigo
                            plat->obstacularizar((Entidade*)ini);
                        }
                    }
                }
                // Lama e Armadilha: dynamic_cast retorna nullptr, nao entra no if
                // entao inimigos nao interagem com elas - so o jogador
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
 
        void Gerenciador_Colisoes::setJogador(Jogador* p) { pJog1 = p; }

        void Gerenciador_Colisoes::tratarColisoesJogsProjeteis() { /* a implementar */ }
 
        void Gerenciador_Colisoes::executar() {
            tratarColisoesJogsObstacs();
            tratarColisoesJogsInimgs();
            tratarColisoesJogsProjeteis();
        }
    }



