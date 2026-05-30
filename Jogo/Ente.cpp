#include "Ente.h"

// Inicializa os ponteiros estáticos como nulos
	Gerenciador_Grafico* Ente::pGG = nullptr;
	sf::RenderWindow* Ente::pJanela = nullptr;

	Ente::Ente() : id(0) /*pFig(nullptr)*/ {}
	Ente::~Ente() {}

	// Guarda o ponteiro do gerenciador gráfico 
	void Ente::setGG(Gerenciador_Grafico* pG) {
		pGG = pG;
	}

	// Guarda o ponteiro da janela 
	void Ente::setJanela(sf::RenderWindow* j) {
		pJanela = j;
	}
