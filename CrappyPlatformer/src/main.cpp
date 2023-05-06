#include <raylib.h>
#include "include/Game.hpp"

int main() {
    Game game;
    while(!WindowShouldClose()) {
        game.Run();
    }
}