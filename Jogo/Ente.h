#pragma once
namespace Jogo
{
	class Gerenciador_Grafico; // Remover depois de configurar o gerenciador gráfico
	class Ente {
	protected:
		int id;
		static Gerenciador_Grafico* pGG;

	public:
		Ente();
		virtual ~Ente();
		virtual void executar() = 0;
		void desenhar();
		static void setGG(Gerenciador_Grafico* pG);
	};
}
