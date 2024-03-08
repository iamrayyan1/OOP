
#include<iostream>
#include<string>
using namespace std;

class Graphics
{
private:
  string graphics;

public:
  Graphics(string graphics) : graphics(graphics) {}
  string setGraphics(string Graphics) { graphics = Graphics; }
  string getGraphics() { return graphics; }
};

class Input
{
private:
  string input;

public:
  Input(string input) : input(input) {}
  string setInput(string Input) { input = Input; }
  string getInput() { return input; }
};

class Engine
{
private:
  string engine;

public:
  Engine(string engine) : engine(engine) {}
  string setEngine(string Engine) { engine = Engine; }
  string getEngine() { return engine; }
};


class GameEngine
{
private:
  Graphics *graphics;
  Input *input;
  Engine *engine;

public:
  GameEngine(Graphics *graphics, Input *input, Engine *engine) : graphics(graphics), input(input), engine(engine) {}
  void setGraphics(Graphics *graphics) { this->graphics = graphics; }
  Graphics *getGraphics() { return graphics; }
  void setInput(Input *input) { this->input = input; }
  Input *getInput() { return input; }
  void setEngine(Engine *engine) { this->engine = engine; }
  Engine *getEngine() { return engine; }
};

int main()
{
  
}
