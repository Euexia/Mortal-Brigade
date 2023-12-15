#pragma once
#include <iostream>
#include <functional>
#include "Engine.h"
#include "Modules/InputModule.h"
#include "Scene.h"
#include "Button.h" 
#include "BackgroundRenderer.h"
#include "RectangleShapeRenderer.h"

class MenuScene final : public Scene {
public:
    MenuScene() : Scene("MenuScene") {
        // Cr�ation de l'arri�re-plan du menu (supposons que vous avez une classe Background)
        GameObject* background = CreateBackgroundGameObject("Background", "../Assets/Images/menu_background.png");

        // Cr�ation des boutons du menu
        std::function<void()> play_func = [this]() { Play(); };
        std::function<void()> empty_func = [this]() { EmptyFunc(); };

        GameObject* playButton = CreateButtonGameObject("PlayButton", 792.f, 300.f, "Play", play_func);
        //GameObject* optionsButton = CreateButtonGameObject("OptionsButton", 930.f, 300.f, "Options", play_func);
        //GameObject* creditsButton = CreateButtonGameObject("CreditsButton", 792.f, 403.f, "Credits", play_func);
        //GameObject* leaveButton = CreateButtonGameObject("LeaveButton", 930.f, 403.f, "Leave", play_func);
    }

    void Play() {
        std::cout << "test" << std::endl;
        Engine::GetInstance()->GetModuleManager()->GetModule<SceneModule>()->SetScene<DefaultScene>();
    }

    void EmptyFunc() {

    }

    GameObject* CreateBackgroundGameObject(const std::string& _name, const std::string& _texturePath) {
        GameObject* game_object = CreateGameObject(_name);
        // Code pour charger et d�finir la texture pour l'arri�re-plan

        // Supposons que vous ayez une classe BackgroundRenderer pour rendre l'arri�re-plan
        BackgroundRenderer* background_renderer = game_object->CreateComponent<BackgroundRenderer>();
        background_renderer->LoadTexture(_texturePath); // Charger la texture de l'arri�re-plan  

        return game_object;
    }

    GameObject* CreateButtonGameObject(const std::string& _name, float _x, float _y, const std::string& _text, std::function<void()> func) {
        GameObject* game_object = CreateGameObject(_name);
        game_object->SetPosition(Maths::Vector2f(_x, _y));

        // Cr�ation d'un bouton avec du texte
        Button* button = game_object->CreateComponent<Button>();
        button->SetText(_text);
        button->SetSize(Maths::Vector2f(100.f, 100.f));
        button->SetColor(sf::Color(0, 0, 0, 0));
        button->OnClick(func);

        return game_object;
    }

};