#include <string>
#include <SFML/Graphics.hpp>
#include "../Ente.h"
using namespace std;

namespace Principal {
    class Texto : public Ente {
    private:
        sf::Vector2f coordenadas;
        //sf::RectangleShape caixa;

        sf::Font lirregulier; //.load("caminho/para/a/fonte")
        sf::Text textoVisivel; //.setFont(lirregulier)
        string textData;
    
    public:
        Texto();
        ~Texto();

        void alterarTexto();
        //void redimensionarCaixa(float eixoX, float eixoY);

        virtual void executar();
        virtual void desenhar(sf::RenderWindow& window);

        sf::Vector2f getCoordenadas() const;
    };
}