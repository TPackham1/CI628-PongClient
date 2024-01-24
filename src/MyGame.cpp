#include "MyGame.h"

//width 800 hieght 600
void MyGame::on_receive(std::string cmd, std::vector<std::string>& args) {
            game_data.ballRadius = 5;
            game_data.player1X = 200;
            game_data.player2X = 575;
    if (cmd == "GAME_DATA") {
        // we should have exactly 4 arguments
        if (args.size() == 4) {
            game_data.player1Y = stoi(args.at(0));
            game_data.player2Y = stoi(args.at(1));
            game_data.ballX = stoi(args.at(2));
            game_data.ballY = stoi(args.at(3));
           
           
        }
        if (cmd == "SCORES")
            if (args.size() == 2)
            {
                scores.player1Score = stoi(args.at(0));
                scores.player2Score = stoi(args.at(1));
        }
    } else {
        std::cout << "Received: " << cmd << std::endl;
    }
}

void MyGame::send(std::string message) {
    messages.push_back(message);
}
//player inputs
void MyGame::input(SDL_Event& event) {
    switch (event.key.keysym.sym) {
        case SDLK_w:
            send(event.type == SDL_KEYDOWN ? "W_DOWN" : "W_UP");
            break;
        case SDLK_s:
            send(event.type == SDL_KEYDOWN ? "S_DOWN" : "S_UP");
            break;
        case SDLK_i:
            send(event.type == SDL_KEYDOWN ? "I_DOWN": "I_UP");
            break;
        case SDLK_k:
            send(event.type == SDL_KEYDOWN ? "K_DOWN" : "K_UP");
            break;
    }
}


void MyGame::update() 
{
    //player 1

    player1.y = game_data.player1Y;
    player1.x = game_data.player1X;
    player1Score = scores.player1Score;
   //
    //player 2

    player2.y = game_data.player2Y;
    player2.x = game_data.player2X;
    player2Score = scores.player2Score;
    //
}


// Simple work around for SDL not having native support for drawing circles
// Solution found @ https://iq.opengenus.org/getting-started-2d-graphics-in-cpp-sdl2/
void MyGame::drawCircle(SDL_Renderer* renderer)
{
    for (int x = game_data.ballX - game_data.ballRadius; x <= game_data.ballX + game_data.ballRadius; x++) {
        for (int y = game_data.ballY - game_data.ballRadius; y <= game_data.ballY + game_data.ballRadius; y++) {
            if ((std::pow(game_data.ballY - y, 2) + std::pow(game_data.ballX - x, 2)) <=
                std::pow(game_data.ballRadius, 2)) {
                SDL_RenderDrawPoint(renderer, x, y);
            }
        }
    }

    SDL_RenderPresent(renderer);
};




void MyGame::render(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawRect(renderer, &player1);
    SDL_RenderDrawRect(renderer, &player2);
    drawCircle(renderer);
   
   /* TTF_Init();
   TTF_Font font = TTF_OpenFont("arial.ttf", 24);
    SDL_Color White = { 255, 255, 255 };
    SDL_Surface* scoreboard = TTF_RenderText_Solid(font,player1Score + "            " + player2Score,White);*/
}