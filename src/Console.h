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

    int keybuffer;
    string linebuffer;

private:
    string letter;
    string history[10];
    int a;
};
