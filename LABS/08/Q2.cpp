#include<iostream>
#include<string>
using namespace std;

class Character{

protected:
  int health;
  int damage;

public:
  Character(int health, int damage) : health(health), damage(damage) {}

  void display(){
    cout << "Health: " << health << endl;
    cout << "Damage: " << damage << endl;
  }

};

class Enemy : public Character{

public:
  Enemy(int health, int damage) : Character(health, damage) {}

  void display(){
    Character::display();
  }

};

class Player : public Character{

public:
  Player(int health, int damage) : Character(health, damage) {}

  void display(){
    Character::display();
  }

};

class Wizard : public Player{

private:
  int magicPower;
  string spells;

public:
  Wizard(int health, int damage, int magicPower, string spells) : Player(health, damage), magicPower(magicPower), spells(spells) {}

  void display(){
    Player::display();
    cout << "Magic Power: " << magicPower << endl;
    cout << "Spells: " << spells << endl;
  }

};

int main(){
  Wizard p1(10, 50, 100, "FIRE");
  p1.display();
}
