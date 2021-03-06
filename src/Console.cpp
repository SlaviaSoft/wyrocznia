#include "Console.h"

Console::Console()
:
    linebuffer("")
{
    keybuffer = 0;
    a = -1; 
};

void Console::linecreator()
{

    if (keybuffer>=32 && keybuffer<=126)
    {
        letter = char(keybuffer);
        linebuffer = linebuffer + letter;
        keybuffer = 0;
    }

    if (keybuffer == 8 && linebuffer.size() > 0)
    {
        linebuffer.resize(linebuffer.size()-1);
        keybuffer = 0;
    }

    if (keybuffer == 13)
    {
        for(int i=9; i>0; i--)
        {
            history[i] = history[i-1];
        }
        history[0] = linebuffer + linebufferR;
        linebuffer = "";
        linebufferR = "";
        keybuffer = 0;
        a = -1;
    }

};

void Console::up()
{
    if(a<9)
    {
        a++;
        linebuffer = history[a];
    }
};

void Console::down()
{
    if(a>0)
    {
        a--;
        linebuffer = history[a];
    }
};

void Console::left()
{
    if(linebuffer.size()>0)
    {
        linebufferR = linebuffer[linebuffer.size()-1] + linebufferR;
        linebuffer.resize(linebuffer.size()-1);
    }

};

void Console::right()
{
    if(linebufferR.size()>0)
    {
        linebuffer = linebuffer + linebufferR[0];
        for(int i=0; i<linebufferR.size(); i++)
        {
            linebufferR[i] = linebufferR[i+1];
        }
        linebufferR.resize(linebufferR.size()-1);
    }
};

void Console::del()
{
    if (linebufferR.size() > 0)
    {
        for(int i=0; i<linebufferR.size(); i++)
        {
            linebufferR[i] = linebufferR[i+1];
        }
        linebufferR.resize(linebufferR.size()-1);
    }
};
