
#include <format>
#include "SimpleGameKit/SimpleGameKit.h"

#include "PlayScene.h"


int main() {
  sgk::Game::get().addScene<PlayScene>("play");
  sgk::Game::get().setCurrentScene("play");
  sgk::Game::get().run();
  return 0;
}
