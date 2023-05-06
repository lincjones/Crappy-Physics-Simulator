#include <raylib.h>
#include "Sprite.hpp"

class Object{
    public:
    int width;
    int height;
    int x_pos;
    int y_pos;
    int id;
    Color color;

    Object(int w, int h, int x, int y, Color col, int p_id) {
        width = w;
        height = h;
        x_pos = x;
        y_pos = y;
        id = p_id; 
        color = col;
    }

    void Update() {

    }

    void Draw() {
        DrawRectangle(x_pos, y_pos, width, height, color);
    }
};