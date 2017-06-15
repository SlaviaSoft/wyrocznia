#pragma once
#include <string>
#include <iostream>

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

    int keybuffer;
    string linebuffer;
    string linebufferR;

private:
    string letter;
    string history[10];
    int a;
};
