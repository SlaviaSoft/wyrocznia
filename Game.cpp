#include "Game.h"
#include "Console.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

extern Game*game;

extern Console*console;

Game::Game(){
  window.create(sf::VideoMode(WIDTH,HEIGHT), "Wyrocznia");

  //set bg
  setBgImage("test.jpg");
  bgImg.setTexture(bgImgTexture);
  bgImg.setTextureRect(sf::IntRect(0,0,WIDTH,HEIGHT));

  //set console rectangle
  consoleShape = new sf::RectangleShape((sf::Vector2f(WIDTH*0.86,HEIGHT*0.86)));
  consoleShape->setFillColor(sf::Color(30, 30, 30));
  //set console position to center
  consoleShape->setPosition(sf::Vector2f(WIDTH*0.07,HEIGHT*0.07));

  //set console input rectangle
  consoleInputShape = new sf::RectangleShape((sf::Vector2f(WIDTH*0.86,HEIGHT*0.06)));
  consoleInputShape->setFillColor(sf::Color(50, 50, 50));
  consoleInputShape->setPosition(sf::Vector2f(WIDTH*0.07,HEIGHT*0.87));

  //set console input text and font

  if (!arial.loadFromFile("arial.ttf"))
  {
      std::cout<<"Can't load font"<<std::endl;
  }
  inputText = new sf::Text;
  inputText->setString("|");
  inputText->setPosition(sf::Vector2f(WIDTH*0.08,HEIGHT*0.87));
  inputText->setFont(arial);
  inputText->setCharacterSize(30);
  inputText->setStyle(sf::Text::Regular);

  //restart clocks
  blinkingCursorClock.restart();

  //set other variables values
  fps=0;
};


//..............................................................................

void Game::writeText(int key){
    if((key>=32 && key<=127) || key == 8 || key == 13)
    {
        console->keybuffer = key;
        console->linecreator();
    }

};

//..............................................................................

void Game::keyPressed(sf::Keyboard::Key key)
{
    switch(key)
    {
        case sf::Keyboard::Up:
        console->up();
        break;
        case sf::Keyboard::Down:
        console->down();
        break;
        case sf::Keyboard::Left:
        console->left();
        break;
        case sf::Keyboard::Right:
        console->right();
        case sf::Keyboard::Delete:
        console->del();
        break;
    }

}

//..............................................................................

void Game::render(){
  window.draw(bgImg);
  window.draw(*consoleShape);
  window.draw(*consoleInputShape);
  window.draw(*inputText);

  consoleInput();

}

//..............................................................................

void Game::calculateFPS()
{
  // FPStime = FPSclock.getElapsedTime();
  // cout << FPStime.asSeconds() << endl;
  // FPSclock.restart().asSeconds();
  // fps = 1.0f/FPStime.asSeconds();
  //std::cout<<fps<<std::endl;
}

//..............................................................................

void Game::consoleInput(){

  if(blinkingCursorClock.getElapsedTime().asSeconds()>0.5)
  {
    inputText->setString(console->linebuffer+"|"+console->linebufferR);
    if(blinkingCursorClock.getElapsedTime().asSeconds()>1)
      blinkingCursorClock.restart();
  }else
  {
    inputText->setString(console->linebuffer+" "+console->linebufferR);
  }
}

//..............................................................................

void Game::setBgImage(std::string imgName)
{
  if (!bgImgTexture.loadFromFile(imgName))
  {
    std::cout<<"Can't load bg img"<<std::endl;
  }
}

//..............................................................................
