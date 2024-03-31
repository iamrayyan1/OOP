#include<iostream>
#include<string>
using namespace std;

class Player{
private:
    int playerID;
    string playerName;
protected:
    int health;
public:
    Player(int playerID, string playerName) : playerID(playerID), playerName(playerName), health(100) {}

    int getHealth(){
        return health;
    }

    void setHealth(int n){
        health -= n;
    }

    void displayPlayerInfo(){
        cout << "Player ID: " << playerID << endl;
        cout << "Name: " << playerName << endl;
        cout << "Health: " << health << endl;
    }

};

class Weapon{
private:
    string weaponsList[5] = {"Sword", "Axe", "Shield", "Hammer", "Knife"};
public:
    Weapon(){}

    void displayWeapons(){
        cout << "Weapons List: " << endl;
        for(int i = 0; i < 5; i++){
            cout << i+1 << ": " << weaponsList[i] << endl;
        }
    }
    int use(){
        int choice;
        //cout << "Which weapon would you like to use?(1-5): ";
        cin >> choice;
        if(choice < 1 || choice > 5)
            cout << "Invalid choice. Please try again." << endl;
        else
            cout << "You have chosen " << weaponsList[choice-1] << endl;
        return choice;
    }
};

class Character : public Player{
private:
    int level;
    string experience;
    int points;
    Weapon weapon;
public:
    Character(int playerID, string playerName) : Player(playerID, playerName), level(0), experience("Beginner"), points(0) {}

    void levelUp(){
        if(points >= 10){
            level++;
            points -= 10;
            if(experience == "Beginner")
            {
                experience = "Intermediate";
                cout << "Congratulations! You have leveled up to Intermediate" << endl;
            }
            else if(experience == "Intermediate")
            {
                experience = "Advanced";
                cout << "Congratulations! You have leveled up to Advanced" << endl;
            }
            else if(experience == "Advanced")
            {
                experience = "Expert";
                cout << "Congratulations! You have leveled up Expert" << endl;
            }
        }
    }

    void attack(Player& enemy){
        enemy.setHealth(5);
        points += 10;
        levelUp();
        cout << "You have attacked the enemy!!" << endl;
        displayPlayerInfo();
        enemy.displayPlayerInfo();
    }

    void playGame(Player& enemy){
        cout << "Which weapon would you like to use?" << endl;
        weapon.displayWeapons();
        int choice = weapon.use();
        if(choice != -1){
            int target;
            cout << "Who is attacked( enemy(1) or player(2) ): " << endl;
            cin >> target;
            if(target == 1)
                attack(enemy);
            else if(target == 2)
                attack(*this); 
            else
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    void finalResult(Player& enemy){
        displayPlayerInfo();
        enemy.displayPlayerInfo();
    }
};

class Enemy : public Player{
private:
    int damage;
public:
    Enemy(int playerID, string playerName, int damage) : Player(playerID, playerName), damage(damage) {}

    void attack(Player& player){
        player.setHealth(damage);
        cout << "You have been attacked by the enemy!!" << endl;
        displayPlayerInfo();
        player.displayPlayerInfo();
    }
};

int main(){
    cout<<"Name: Rayyan Merchant\n23K-0073"<<endl;

    Character player(1, "Rayyan");
    Enemy enemy(2, "Lucifer", 10);

    do{
        player.playGame(enemy);
        if(enemy.getHealth() <= 0){
            cout << "You WON" << endl;
            player.finalResult(enemy);
            break;
        }
        if(player.getHealth() <= 0)
        {
            cout << "You LOST!!" << endl;
            player.finalResult(enemy);
            break;
        }
    }while(player.getHealth() > 0 && enemy.getHealth() > 0);

    return 0;
}
