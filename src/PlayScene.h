//
// Created by profa on 15/01/2024.
//

#pragma once
#include <Components.h>
#include <SimpleGameKit/SimpleGameKit.h>

namespace sgk {
class InputManager;
}

class PlayScene final : public sgk::Scene{
  sgk::Ptr<sgk::InputManager> inputManager;

  sgk::Ref<sgk::Entity> e;

public:
  PlayScene();
  ~PlayScene() override = default;

  void setup() override;

  void handleInput() override;

  void update(const double dt) override {
    if (e->has<Position>()) {
      auto& pos = e->get<Position>().value().get();
      pos.x += 100.0f * dt;
      pos.y += 100.0f * dt;
    }
  }

  void draw() const override;

  void drawGui() const {
  }
};

