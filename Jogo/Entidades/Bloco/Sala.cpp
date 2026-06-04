#include "Sala.h"
#include <algorithm>
using namespace std;

namespace Principal {
    Sala::Sala(int alturaFornecida, int larguraFornecida)
     : altura(alturaFornecida), largura(larguraFornecida) {
        area.setPosition(sf::Vector2f(0.f, 0.f));
        area.setSize(sf::Vector2f(largura, altura));
        area.setFillColor(sf::Color(100, 100, 100));
    }

    Sala::~Sala() {

    }

    void Sala::limitar(Entidade* ent) { // Empurra entidade para dentro da sala
        sf::FloatRect areaEnt = ent->getCorpo().getGlobalBounds();
        sf::FloatRect areaSala = area.getGlobalBounds();

        // Confere a margem de não-colisão e anula negativos
        float erroEsquerda = max(0.f, areaSala.left - areaEnt.left);
        float erroCima = max(0.f, areaSala.top - areaEnt.top);
        float erroDireita = max(0.f,(areaEnt.left + areaEnt.width) - (areaSala.left + areaSala.width));
        float erroBaixo = max(0.f,(areaEnt.top + areaEnt.height) - (areaSala.top + areaSala.height));

        bool erro = (erroBaixo || erroCima || erroDireita || erroEsquerda);

        if (erro) {
            ent->setPosition(sf::Vector2f(areaEnt.left + (erroEsquerda - erroDireita),
                                          areaEnt.top + (erroCima - erroBaixo)));
            //ent->setPosition(sf::Vector2f(areaEnt.left, areaEnt.top - erroBaixo)); //

            if (erroBaixo)
                ent->pousar();
                
        }
    }

    void Sala::desenhar(sf::RenderWindow& window) {
        window.draw(area);
    }
}