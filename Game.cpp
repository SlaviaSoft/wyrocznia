#include "Game.h"
#include "Console.h"

extern Game*game;

extern Console*console;

Game::Game(){
  window.create(sf::VideoMode(WIDTH,HEIGHT), "Wyrocznia");
  scene = 0;



  if(scene==0)
  {
  //set bg
  setBgImage("test.png");
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
      std::cout<<"Can't load arial font"<<std::endl;
  }
  obelix = new sf::Font();
  if (!obelix->loadFromFile("obelix.ttf"))
  {
      std::cout<<"Can't load obelix font"<<std::endl;
  }
  inputText = new sf::Text;
  inputText->setString("|");
  inputText->setPosition(sf::Vector2f(WIDTH*0.08,HEIGHT*0.87));
  inputText->setFont(arial);
  inputText->setCharacterSize(30);
  inputText->setStyle(sf::Text::Regular);

  //create logo letters
  short int logoFontSize=40;
  logo.push_back(sf::Text("w",*obelix,logoFontSize));
  logo.push_back(sf::Text("y",*obelix,logoFontSize));
  logo.push_back(sf::Text("r",*obelix,logoFontSize));
  logo.push_back(sf::Text("o",*obelix,logoFontSize));
  logo.push_back(sf::Text("c",*obelix,logoFontSize));
  logo.push_back(sf::Text("z",*obelix,logoFontSize));
  logo.push_back(sf::Text("n",*obelix,logoFontSize));
  logo.push_back(sf::Text("i",*obelix,logoFontSize));
  logo.push_back(sf::Text("a",*obelix,logoFontSize));
  for(int i=0;i<9;i++)
  {
    logo[i].setPosition(400+50*i,-40);
    logo[i].setColor(sf::Color(255,255,255,0));
    logo[i].setOrigin(logo[i].getGlobalBounds().width/2,logo[i].getGlobalBounds().height/2);
  }

  mainText = new sf::Text;
  mainText->setPosition(sf::Vector2f(WIDTH*0.07,HEIGHT*0.11));
  mainText->setFont(arial);
  mainText->setCharacterSize(30);
  mainText->setStyle(sf::Text::Regular);

  //set fadeRect
  fadeRect = new sf::RectangleShape(sf::Vector2f(WIDTH,HEIGHT));
  fadeRect->setFillColor(sf::Color(0,0,0,255));

  //restart clocks
  blinkingCursorClock.restart();
  LogoClock.restart();
  fadeClock.restart();

  //set other variables values
  fps=0;
  ifDisplayLogo = true;
  ifFadeIn = true;
  displayTextLine=0;
    }


}


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
        case sf::Keyboard::Escape:
          window.close();
    }

}

//..............................................................................

void Game::render(){
  window.draw(bgImg);
  window.draw(*consoleShape);
  window.draw(*consoleInputShape);
  window.draw(*inputText);
  window.draw(*mainText);

  for(int i=0;i<logo.size();i++)
    window.draw(logo[i]);


  if(ifDisplayLogo==true)
    displayLogo();

  if(ifFadeIn==true)
    fadeIn();

  if(scene==1)
  {
    displayText("Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.",170, WIDTH*0.4);
  }

  consoleInput();

  window.draw(*fadeRect);
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

void Game::displayLogo()
{
  for(int i=0;i<9;i++)
  {
    int logoTime = LogoClock.getElapsedTime().asMilliseconds();
    if(logoTime>1000 && logo[i].getPosition().y < 300 && logoTime<5000)
    {
      logo[i].move(0, logoTime/((i+1)*300));
    }
    if((logoTime*logoTime)/60000 < 255)
      logo[i].setColor(sf::Color(255,255,255,(logoTime*logoTime)/60000));

    if(logoTime>5000)
    {
      logo[i].rotate(logoTime/5000);
      logo[i].setCharacterSize(40*5000*5000/(logoTime*logoTime));
      if(i==0)
          logo[i].move(-1.3,-0.5);
      if(i==1)
          logo[i].move(-0.3,-0.9);
      if(i==2)
          logo[i].move(-0.8,0.3);
      if(i==3)
          logo[i].move(0.9,0.6);
      if(i==4)
          logo[i].move(0.9,-0.9);
      if(i==5)
          logo[i].move(0.7,1);
      if(i==6)
          logo[i].move(-0.7,-1.2);
      if(i==7)
          logo[i].move(1.3,-0.5);
      if(i==8)
          logo[i].move(0.3,-0.7);

    }
    if(logoTime>8000){
        scene=1;
        displayTextClock.restart();
        ifDisplayLogo = false;
    }



  }
}

//..............................................................................

void Game::fadeIn()
{
  int alpha = fadeClock.getElapsedTime().asMilliseconds()/5;
  fadeRect->setFillColor(sf::Color(0,0,0,255 - alpha));
  if(alpha>250)
    ifFadeIn=false;
}

//..............................................................................

void Game::displayText(std::string text, int speed, int end)
{
  for(int i=0;i<text.length();i++){
    if(displayTextClock.getElapsedTime().asMilliseconds()<speed*i){
      if(displayTextLine==0)
      {
        std::cout<<i<<std::endl;
        //std::string main0 = mainText->getString().toAnsiString();
        //if(mainText->getLocalBounds().width < end+1000)
        //{
          mainText->setString(text.substr(0,i)+'_');
        //}
        /*else if((text[i]==' ')==0)
        {
          mainText->setString(text.substr(0,i)+'_');
        }else{
          mainText->setString(text.substr(0,i));
          displayTextLine++;
        }*/
      }
      break;
    }
  }

}
