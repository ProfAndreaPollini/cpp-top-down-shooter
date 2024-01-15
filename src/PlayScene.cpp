//
// Created by profa on 15/01/2024.
//

#include "PlayScene.h"

#include <Components.h>

#include <format>
#include <iostream>

PlayScene::PlayScene()
  :  inputManager(sgk::CreatePtr<sgk::InputManager>()) {
  auto action_name = std::string("move_left");
  e = sgk::Game::get().getEntityManager()->createEntity();
  e->add<Position>();
  // inputManager->RegisterMapping(KEY_A, );
  inputManager->RegisterMapping(KEY_A, {action_name, sgk::ActionType::START});
  inputManager->RegisterMapping(KEY_D, {"MOVE_RIGHT", sgk::ActionType::ANY});
}

void PlayScene::setup() {
  sgk::Game::get().getWindow().SetTitle("prova");

  // inputManager->RegisterMapping(KEY_A, "move_left");
  inputManager->OnEvent("move_left", [](const sgk::Event& evt) {
    auto isPressed = std::get<sgk::ActionType>(evt) == sgk::ActionType::START;
    std::cout << std::format("move_left [pressed:{}]", isPressed) << std::endl;
  });
  inputManager->OnEvent("MOVE_RIGHT", [](const sgk::Event& evt) {
    auto isPressed = std::get<sgk::ActionType>(evt) == sgk::ActionType::START;
    std::cout << std::format("MOVE_RIGHT [pressed:{}]", isPressed) << std::endl;
  });
}

void PlayScene::handleInput() {
  inputManager->ProcessInput();
}

void PlayScene::draw() const {
  sgk::Renderer::ClearBackground({255, 0, 0, 255});
  if (e->has<Position>()) {
    if (const auto pos = e->get<Position>(); pos.has_value()) {
      const auto& p = e->get<Position>().value().get();
      // std::cout << std::format("pos: [{}, {}]", p.x, p.y) << std::endl;
      sgk::Renderer::DrawCircle(p.x, p.y, 50, {0, 255, 0, 255});
    }
  }
}
