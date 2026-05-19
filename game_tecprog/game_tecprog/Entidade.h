#pragma once
#include "Ente.h"

namespace Jogo
{
	class Entidade : public Ente
	{
	protected:
		int x;
		int y;
		// std::ostream buffer;
	public:
		Entidade();
		virtual ~Entidade();
		virtual void executar() = 0;
		virtual void salvar() = 0;
	protected:
		void salvarDataBuffer();


	};
}
