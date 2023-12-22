#pragma once
#include <iostream>
#include <functional>

#include "Engine.h"
#include "Modules/InputModule.h"
#include "Modules/AssetModule.h"

#include "Scene.h"
#include "Button.h" 
#include "BackgroundRenderer.h"
#include "RectangleShapeRenderer.h"
#include "SpriteRenderer.h"
#include "TextRenderer.h"
#include "Map1.h"
#include "Map2.h"
#include "Map3.h"
#include "Character.h"

class ChooseMap : public Scene {
public:
    ChooseMap() : Scene("ChooseMapScene") {
        // Cr�ation de l'arri�re-plan pour la s�lection de la carte
        GameObject* background = CreateBackgroundGameObject("MapSelectionBackground", "map_selection_background");

        AssetModule::Play("moon_selection");
        AssetModule::SetMusicVolume("moon_selection", 20.f);
        AssetModule::Loop("moon_selection", true);

        GameObject* select_text = CreateSelectTextGameObject("SelectionText", Maths::Vector2f(0.5f, 0.07f));

        std::function<void()> goToMap1_func = [this]() { GoToMap1(); };
        std::function<void()> goToMap2_func = [this]() { GoToMap2(); };
        std::function<void()> goToMap3_func = [this]() { GoToMap3(); };

        GameObject* map_button_1 = CreateMapButton("Map1Button", 250.f, 400.f, "moon_1" , goToMap1_func , 1);
        GameObject* map_button_2 = CreateMapButton("Map2Button", 850.f, 400.f, "moon_2" , goToMap2_func , 2);
        GameObject* map_button_3 = CreateMapButton("Map3Button", 1450.f, 400.f,"moon_3" , goToMap3_func , 3);

    }

    GameObject* CreateBackgroundGameObject(const std::string& _name, const std::string& _texture_path) {
        GameObject* game_object = CreateGameObject(_name);
        BackgroundRenderer* background_renderer = game_object->CreateComponent<BackgroundRenderer>();
        background_renderer->LoadTexture(_texture_path);
        return game_object;
    }

    GameObject* CreateSelectTextGameObject(const std::string& _name, const Maths::Vector2f& _position) {
        GameObject* game_object = CreateGameObject(_name);

        TextRenderer* text = game_object->CreateComponent<TextRenderer>();
        text->SetText("Select a moon to explore");
        text->SetColor(sf::Color::White);
        text->SetPosition(_position);
        text->SetSize(48);
        text->Center(true);

        return game_object;
    }

    GameObject* CreateMapButton(const std::string& _name, float _x, float _y, const std::string& _texture_path, std::function<void()> func , int _mapId) {
        GameObject* game_object = CreateGameObject(_name);
        game_object->SetPosition(Maths::Vector2f(_x, _y));

        SpriteRenderer* sprite = game_object->CreateComponent<SpriteRenderer>();
        sprite->LoadSprite(_texture_path);
        sprite->SetTextureSize(Maths::Vector2u(100, 100));
        sprite->SetAutoIncrement(true);
        sprite->SetScale(3.f);
        sprite->SetBegin(sf::Vector2i(0, 0));
        sprite->SetEnd(sf::Vector2i(49, 0));
        sprite->Center(true);

        bool createButton = true;
        for (const auto& valeur : *Character::GetMoonVisited()) {
            if (valeur == _mapId) {
                createButton = false;
            }
        }

        if (createButton == true) {
            // Cr�ation d'un bouton pour choisir une carte
            Button* button = game_object->CreateComponent<Button>();
            button->SetSize(Maths::Vector2f(300.f, 300.f));
            button->SetColor(sf::Color(0, 0, 0, 0));
            button->OnClick(func);
            button->SetBaseSize(3.f);
            button->SetHoverSize(3.5f);
            button->Animate(true);
        }
        return game_object;
    }
    void GoToMap1() {
        AssetModule::Stop("moon_selection");
        Character::AddVisistedMoon(1);
        Engine::GetInstance()->GetModuleManager()->GetModule<SceneModule>()->SetScene<Map1>();
    }
    void GoToMap2() {
        AssetModule::Stop("moon_selection");
        Character::AddVisistedMoon(2);
        Engine::GetInstance()->GetModuleManager()->GetModule<SceneModule>()->SetScene<Map2>();
    }
    void GoToMap3() {
        AssetModule::Stop("moon_selection");
        Character::AddVisistedMoon(3);
        Engine::GetInstance()->GetModuleManager()->GetModule<SceneModule>()->SetScene<Map3>();
    }

};