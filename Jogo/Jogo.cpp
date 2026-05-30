#include "Jogo.h"

static const float LARGURA = 900.f;
static const float ALTURA = 700.f;

Jogo::Jogo()
    : janela(sf::VideoMode((unsigned)LARGURA, (unsigned)ALTURA), "Jogo")
{
    janela.setFramerateLimit(60);
    inimigo.setAlvo(&jogador);

    chao.setSize(sf::Vector2f(LARGURA, 32.f));
    chao.setPosition(0.f, ALTURA - 32.f);
    chao.setFillColor(sf::Color::Blue);
}

Jogo::~Jogo() {}

void Jogo::resolverColisao(Personagem& p) {
    sf::FloatRect r = p.getCorpo().getGlobalBounds();
    sf::FloatRect o = chao.getGlobalBounds();
    if (r.intersects(o)) {
        float penetracao = (r.top + r.height) - o.top;
        if (penetracao > 0.f && penetracao < r.height) {
            p.setPosition(sf::Vector2f(r.left, r.top - penetracao));
            p.velY = 0.f; 
            p.noChao = true;
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
    inimigo.executar();
    inimigo.danificar(&jogador);
    resolverColisao(jogador);
    resolverColisao(inimigo);
}

void Jogo::desenhar() {
    janela.clear(sf::Color(30, 30, 30));
    janela.draw(chao);
    jogador.desenhar(janela);
    inimigo.desenhar(janela);
    janela.display();
}


