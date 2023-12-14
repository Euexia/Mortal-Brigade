#include "Components/BackgroundRenderer.h"

void BackgroundRenderer::LoadTexture(const std::string& _texturePath) {
    if (!texture.loadFromFile(_texturePath)) {
        // G�rer le cas o� le chargement de la texture �choue
    }
    background.setTexture(texture);
}

void BackgroundRenderer::Render(sf::RenderWindow* _window) {
    // Obtenir la taille de la fen�tre
    sf::Vector2u windowSize = _window->getSize();

    // Mettre � jour la taille du fond pour correspondre � la taille de la fen�tre
    sf::Vector2f newScale(static_cast<float>(windowSize.x) / background.getTexture()->getSize().x,
        static_cast<float>(windowSize.y) / background.getTexture()->getSize().y);
    background.setScale(newScale);

    // Dessiner le fond dans la fen�tre
    _window->draw(background);
}
