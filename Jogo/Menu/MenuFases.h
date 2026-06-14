#pragma once
#include "Menu.h"

namespace Principal {
    class MenuFases : public Menu {
    private:
        // imagem da fase 1
        // imagem da fase 2
    
    public:
        MenuFases();
        ~MenuFases();

        void executar();
        void desenhar(sf::RenderWindow& window);
    };
}