#include "Modules/AssetModule.h"
#include "Components/BackgroundRenderer.h"

void BackgroundRenderer::LoadTexture(const std::string _texture) {
    texture = *AssetModule::GetAsset(_texture);
    background.setTexture(texture);
}

void BackgroundRenderer::Render(sf::RenderWindow* _window) {
    background.setPosition(0, 0);
    // Dessiner le fond dans la fen�tre
    _window->draw(background);
}