#include <raylib.h>
#include <list>
#include "settings.h"
#include "Sprites/Player.hpp"
#include "Sprites/Ball.hpp"
#include "Sprites/Object.hpp"

Player player = Player(30, 30, 200, 200, Color {255, 255, 0, 255}, 00); 
std::list<Object> list_objects = {
};
std::list<Ball> list_balls = {
};

class Game {
    public:
    Game() {
        SetTargetFPS(60);
        InitWindow(window_width, window_height, "Crappy Platformer Game in C++");
    }
    
    void BallLogic() {
        std::list<Ball>::reverse_iterator it;
        // init ball
        for (it = list_balls.rbegin(); it != list_balls.rend(); it++) {
            // rand velocities and directions
            
            int xv = rand() % 10 +1;
            int yv = rand() % 10 +1;
            int xvn = rand() % 2 +0;
            int yvn = rand() % 2 +0;
            
            if (xvn && yvn) {
                it -> inn(10, -xv, -yv);
            }
            if (xvn && !yvn) {
                it -> inn(10, -xv, yv);
            }
            if (!xvn && yvn) {
                it -> inn(10, xv, -yv);
            }
            if (!xvn && !yvn) {
                it -> inn(10, xv, yv);
            }
        }
        // draw balls
        for (it = list_balls.rbegin(); it != list_balls.rend(); it++) {
            std::cout << "(*)\n";
            it->Update();
            it->Draw();
            std::cout << it->id << "::" << it->x_pos <<","<< it->y_pos << "\n";
        }
        // rand id
        if (player.add_ball) {
            int _id = rand() % 99999 + 1;
            list_balls.push_front(Ball(0, 0, player.x_pos, player.y_pos, WHITE, _id));
            std::cout << "ADDED A BALL";
        }
    }

    void ObjectLogic() {
        std::list<Object>::reverse_iterator it;
        for (it = list_objects.rbegin(); it != list_objects.rend(); it ++) {
            it->Draw();
            it->Update();
        }
        if (player.add_object) {
            // add obj
            int width = 40;
            int height = 40;
            list_objects.push_front(Object (width, height, GetMousePosition().x, GetMousePosition().y,
            Color {255, 0, 0, 255}, 000));
        }
    }
    
    void CheckCollisions() {
        std::list<Object>::reverse_iterator o_it;
        for (o_it = list_objects.rbegin(); o_it != list_objects.rend(); o_it ++) {
            Rectangle o_rect = Rectangle({
            (float)o_it->x_pos, (float)o_it->y_pos, (float)o_it->width, (float)o_it->height});
            
            std::list<Ball>::reverse_iterator b_it;
            
            for (b_it = list_balls.rbegin(); b_it != list_balls.rend(); b_it++) {
                if(CheckCollisionCircleRec(
                    Vector2 ({(float)b_it->x_pos, (float)b_it->y_pos}),
                    b_it->radius, o_rect)) {
                        b_it->x_vel *= -1;
                        b_it->y_vel *= -1;
                    }
            }
        }
    }

    void Run() {
        Update();
        Draw();
    }

    void Update() {
        player.Update();
        DrawFPS(10, 10);
        CheckCollisions();
        BallLogic();
        ObjectLogic();

        if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) {
            list_balls = {};
            list_objects = {};
        }
    }

    void Draw() {
        BeginDrawing();
        ClearBackground(Color {0, 0, 0, 255});

        player.Draw();

        EndDrawing();
    }
};