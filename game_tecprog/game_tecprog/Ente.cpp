#include "Ente.h"
namespace Jogo
{

	Gerenciador_Grafico* Ente::pGG = nullptr;

	Ente::Ente()
	{
		id = 0;
	}
	Ente::~Ente()
	{
	}
	void Ente::desenhar()
	{
		//será implementado futuramente
	}
	void Ente::setGG(Gerenciador_Grafico* pG)
	{
		pGG = pG;
	}
}