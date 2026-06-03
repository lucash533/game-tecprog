#include "Jogo.h"

// ---------------------------------//
// As implementações das funções dessa
// classe foram feitas unicamente
// para testar a estrutura do jogo,
// e não tem a intenção de estar no jogo completo
// Serao excluidas ao decorrer do desenvolvimento ;)
//---------------------------------//

static const float LARGURA = 900.f;
static const float ALTURA = 700.f;

Jogo::Jogo()
    : janela(sf::VideoMode((unsigned)LARGURA, (unsigned)ALTURA), "Jogo"),
    plataforma(300.f, ALTURA - 32.f - 20.f, 150.f)  // em cima do chão
{
    janela.setFramerateLimit(60);
    alma.setAlvo(&jogador);

    chao.setSize(sf::Vector2f(LARGURA, 32.f));
    chao.setPosition(0.f, ALTURA - 32.f);
    chao.setFillColor(sf::Color::Blue);
}

Jogo::~Jogo() {}

void Jogo::resolverColisao(Personagem& p) {
    // colisão com chão
    sf::FloatRect r = p.getCorpo().getGlobalBounds();
    sf::FloatRect o = chao.getGlobalBounds();
    if (r.intersects(o)) {
        float pen = (r.top + r.height) - o.top;
        if (pen > 0.f && pen < r.height) {
            p.setPosition(sf::Vector2f(r.left, r.top - pen));
            p.pousar();
        }
    }
    
}

void Jogo::executar() {
    while (janela.isOpen()) {
        processarEventos();
        atualizar();
        desenhar();
    }
}

void Jogo::processarEventos() {
    sf::Event event;
    while (janela.pollEvent(event)) {
        if (event.type == sf::Event::Closed ||
            (event.type == sf::Event::KeyPressed &&
                event.key.code == sf::Keyboard::Escape))
            janela.close();
    }
}

void Jogo::atualizar() {
    jogador.executar();
    alma.executar();
    alma.danificar(&jogador);
    resolverColisao(jogador);
    resolverColisao(alma);
}

void Jogo::desenhar() {
    janela.clear(sf::Color(30, 30, 30));
    janela.draw(chao);
    plataforma.desenhar(janela);
    jogador.desenhar(janela);
    alma.desenhar(janela);
    janela.display();
}



