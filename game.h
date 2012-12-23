#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "ObjectManager.h"
#include "imagemanager.h"
#include "field.h"

class game {
    public:
        static void start();
        static const sf::Input& GetInput();
        static const sf::Image& GetLoadedImage(std::string name);
        static bool isPlaying();
        static void nextTurn();

        static bool board[25];
        static const int windowWidth = 800;
        static const int windowHeight = 600;

    private:
        static void gameloop();
        static bool isExiting();
        static bool isEnding();
        static void setRed(int field1, int field2, int field3, int field4, int field5);

        enum gameState {uninitialized, playing, ending, exiting};

        static gameState _state;
        static sf::RenderWindow _gameWindow;
        static ObjectManager _gameObjects;
        static ImageManager _images;
        static sf::Font defaultFont;
        static sf::String subtext;
        static int turn;
};

#endif
