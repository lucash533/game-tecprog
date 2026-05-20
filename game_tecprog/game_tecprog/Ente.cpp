#include "Ente.h"
namespace Jogo
{
	//inicialização do ponteiro para o gerenciador gráfico
	Gerenciador_Grafico* Ente::pGG = nullptr;

	//funções serão implementadas futuramente
	Ente::Ente()
	{
		id = 0;
	}
	Ente::~Ente()
	{
	}
	void Ente::desenhar()
	{
	}
	void Ente::setGG(Gerenciador_Grafico* pG)
	{
		pGG = pG;
	}
}