#pragma once
#include "Lista.h"
#include "../Entidades/Entidade.h"



class ListaEntidades
{
private:
    Jogo::Lista<Entidade> LEs;

public:
    ListaEntidades();
    ~ListaEntidades();

    void incluir(Entidade* pE);
    void percorrer(sf::RenderWindow& window);
};
