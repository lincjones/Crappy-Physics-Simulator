#include <raylib.h>
#include "Sprite.hpp"
#include <iostream>

class Player : public Sprite{
  public:
    bool add_ball = false;
    bool add_object = false;
    using Sprite::Sprite;

    void Update() {
        add_ball = false;
        add_object = false;
        CheckMovement();

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            add_object = true;
        }
        if (IsKeyPressed(KEY_ENTER)) {
            add_ball = true;
        }
        if (IsKeyDown(KEY_SPACE)) {
            add_ball = true;
        }
    }

    void Draw() {
        DrawRectangle(x_pos, y_pos, width, height, color);
    }

  private:
    int velocity = 10;

    void CheckMovement() {
        if(IsKeyUp(KEY_W)) {
            y_pos += velocity;
        }
        if(IsKeyUp(KEY_S)) {
            y_pos -= velocity;
        }
        if(IsKeyUp(KEY_A)) {
            x_pos += velocity;
        }
        if(IsKeyUp(KEY_D)) {
            x_pos -= velocity;
        }
    }
};