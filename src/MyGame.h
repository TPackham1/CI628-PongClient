#ifndef __MY_GAME_H__
#define __MY_GAME_H__

#include <iostream>
#include <vector>
#include <string>

#include "SDL.h"
#include "SDL_ttf.h"

static struct GameData {
    int player1Y = 0;
    int player1X = 0;
    int player2Y = 0;
    int player2X = 0;
    int ballX = 0;
    int ballY = 0;
    int powerUpX = 0;
    int powerUpY = 0;
    int ballRadius = 5;
} game_data;
static struct Scores {
    int player1Score = 0;
    int player2Score = 0;
} scores;
class MyGame {
            // {x,y,w,h}
    private:
        SDL_Rect player1 = { 0, 0, 20, 60 };
        SDL_Rect player2 = { 0, 0, 20, 60 };
        SDL_Rect scoreboard = {200, 10, 60,60};
        int player1Score = 0;
        int player2Score = 0;
        
        

    public:
        std::vector<std::string> messages;

        void on_receive(std::string message, std::vector<std::string>& args);
        void send(std::string message);
        void input(SDL_Event& event);
        void update();
        void drawCircle(SDL_Renderer* renderer);
        void render(SDL_Renderer* renderer);

};

#endif