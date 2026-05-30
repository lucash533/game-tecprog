#include "Ente.h"

// Inicializa os ponteiros estáticos como nulos
	Gerenciador_Grafico* Ente::pGG = nullptr;
	sf::RenderWindow* Ente::pJanela = nullptr;
	int Ente::contador_id = 0;

	Ente::Ente() : id(contador_id++) /*pFig(nullptr)*/ {}
	Ente::~Ente() {}

	// Guarda o ponteiro do gerenciador gráfico 
	void Ente::setGG(Gerenciador_Grafico* pG) {
		pGG = pG;
	}

	// Guarda o ponteiro da janela 
	void Ente::setJanela(sf::RenderWindow* j) {
		pJanela = j;
	}
