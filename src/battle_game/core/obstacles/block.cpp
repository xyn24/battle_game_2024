#include "battle_game/core/obstacles/block.h"

namespace battle_game::obstacle {

Block::Block(GameCore *game_core,
             uint32_t id,
             glm::vec2 position,
             float rotation,
             glm::vec2 scale)
    : Obstacle(game_core, id, position, rotation) {
}

bool Block::IsBlocked(glm::vec2 p) const {
  p = WorldToLocal(p);
  return p.x <= scale_.x && p.x >= -scale_.x && p.y <= scale_.y &&
         p.y >= -scale_.y;
}

glm::vec2 Block::GetParallelDirection(glm::vec2 p_1, glm::vec2 p_2) const {
  if (!IsBlocked(p_1)) {
    return {0.0f, 0.0f};
  }
  p_1 = WorldToLocal(p_1);
  p_2 = WorldToLocal(p_2);
  if (p_2.x > scale_.x || p_2.x < -scale_.x) {
    return {0.0f, 1.0f};
  }
  if (p_2.y > scale_.y || p_2.y < -scale_.y) {
    return {1.0f, 0.0f};
  }
}


void Block::Render() {
  battle_game::SetColor(glm::vec4{0.0f, 0.0f, 0.0f, 1.0f});
  battle_game::SetTexture(0);
  battle_game::SetTransformation(position_, rotation_, scale_);
  battle_game::DrawModel(0);
}
}  // namespace battle_game::obstacle
