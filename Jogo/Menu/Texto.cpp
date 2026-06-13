#include "Texto.h"

namespace Principal {
    Texto::Texto() : textData("Lorem ipsum") {
        lirregulier.loadFromFile("../../assets/fonts/LIRREGULIER.ttf");
        textoVisivel.setFont(lirregulier);
        textoVisivel.setString(textData.c_str());
    }

    Texto::~Texto() {

    }

    void Texto::alterarTexto() {

    }

    void Texto::executar() {

    }

    void Texto::desenhar(sf::RenderWindow& janela) {

    }
}