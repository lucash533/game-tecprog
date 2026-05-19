#include "Personagem.h"
namespace Jogo
{
	namespace Personagens
	{
		Personagem::Personagem() : num_vidas(3)
		{
		}
		Personagem::~Personagem()
		{
		}
		void Personagem::salvarDataBuffer()
		{
			salvar();
			salvarDataBuffer();
		}
	}
}
