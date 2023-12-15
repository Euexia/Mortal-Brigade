#include "Components/BackgroundRenderer.h"

void BackgroundRenderer::LoadTexture(const std::string& _texturePath) {
    if (!texture.loadFromFile(_texturePath)) {
        // G�rer le cas o� le chargement de la texture �choue
    }
    background.setTexture(texture);
}

void BackgroundRenderer::Render(sf::RenderWindow* _window) {
    background.setPosition(0, 0);
    // Dessiner le fond dans la fen�tre
    _window->draw(background);
}