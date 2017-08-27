#pragma once
#include <string>
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace std;

class Console
{
public:

    Console();
    void linecreator();
    void up();
    void down();
    void left();
    void right();
    void del();

    sf::RectangleShape* consoleInputShape;

    int keybuffer;
    string linebuffer;
    string linebufferR;
    string command;
    bool isActive;

private:
    string letter;
    string history[10];
    int a;
};
