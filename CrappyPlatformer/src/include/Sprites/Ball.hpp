#include <raylib.h>
#include "Sprite.hpp"
#include <iostream>

class Ball : public Sprite {
public:
    float radius;
    int x_vel;
    int y_vel;
    bool is_inn = false;
    using Sprite::Sprite;

    void inn(float _radius, int x_velo, int y_velo) {
        if(!is_inn){
            radius = _radius;
            x_vel = x_velo;
            y_vel = y_velo;
            is_inn = true;
        }
    }

    void Update() {
        x_pos += x_vel;
        y_pos += y_vel;

        // wall bounce logic
        if (x_pos + radius >= GetScreenWidth()) {
            x_vel = -x_vel;
        }
        if (x_pos - radius <= 0) {
            x_vel = -x_vel;
        }
        if (y_pos + radius >= GetScreenHeight()) {
            y_vel = -y_vel;
        }
        if (y_pos - radius <= 0) {
            y_vel = -y_vel;
        }
    }

    void Draw() {
        DrawCircle(x_pos, y_pos, radius, color);
    }
};