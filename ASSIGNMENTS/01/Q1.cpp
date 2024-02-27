#include<iostream>
#include<string>
using namespace std;
  
class Pet
{
public:
  string healthStatus, specialSkills;;
  int hungerLevel, happinessLevel;
  
  Pet(string healthStatus, string specialSkills, int hungerLevel, int happinessLevel) : healthStatus(healthStatus), specialSkills(specialSkills), hungerLevel(hungerLevel), happinessLevel(happinessLevel) {};
  
void displayPetDetails()
{
    cout << "Pet Deatils: " << endl;
    cout << "Health Status: " << healthStatus << endl;
    cout << "Special Skills: " << specialSkills << endl;
    cout << "Hunger Level: " << hungerLevel << endl;
    cout << "Happiness Level: " << happinessLevel << endl;
  }
  
  void updateHunger(int hunger)
  {
    hungerLevel = hunger;
    if (hungerLevel <= 5)
    {
      happinessLevel--;
    }
    else
    {
      happinessLevel++;
    } 
    }
    void updateHappiness(int happiness) 
    {
      happinessLevel = happiness; 
    }
    void updateHealth(string health) 
    {
      healthStatus = health; 
    }
  
  
  };
  
  
  
class Adopter
{
public:
    string adopterName, adopterMobileNum;
    string adoptedPetRecords[10];
  
    Adopter(string adopterName, string adopterMobileNum)
    {
      this->adopterName = adopterName;
      this->adopterMobileNum = adopterMobileNum;
    }
  
    void adoptPet(Pet pet)
    {
      for (int i = 0; i < 10; i++)
      {
        if (adoptedPetRecords[i] == "")
        {
          adoptedPetRecords[i] = pet.healthStatus + "," + pet.specialSkills + "," + to_string(pet.hungerLevel) + "," + to_string(pet.happinessLevel);
          break;
        }
        
      }
    }
  
    void returnPet(Pet pet)
    {
      for (int i = 0; i < 10; i++)
      {
        if (adoptedPetRecords[i] == pet.healthStatus + "," + pet.specialSkills + "," + to_string(pet.hungerLevel) + "," + to_string(pet.happinessLevel))
        {
          adoptedPetRecords[i] = "";
          break;
        }
        
      }
    }
  
    void displayAdoptedPets()
    {
      cout << "Adopted Pets: " << endl;
      for (int i = 0; i < 10; i++)
      {
        if (adoptedPetRecords[i] != "")
        {
          cout << "Pet " << i + 1 << ":\n" << adoptedPetRecords[i] << endl;
        }
      }
    }
  
  };
  
void menu()
{
    cout << "---------------------------" << endl;
    cout << "Virtual Pet Adoption System" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Show all Pets" << endl;
    cout << "2. Adopt a Pet" << endl;
    cout << "3. Return a Pet" << endl;
    cout << "4. Display Adopted Pets" << endl;
    cout << "5. Add Pets" << endl;
    cout << "6. Interact wiht a Pet" << endl;
    cout << "7. Exit" << endl;
}
  
void showAllPets(Pet pets[], int numPets)
{
    cout << "All Pets: " << endl;
    for (int i = 0; i < numPets; i++)
    {
      cout << "Pet " << i + 1 << ":\n" << pets[i].healthStatus << endl << pets[i].specialSkills << endl << pets[i].hungerLevel << endl << pets[i].happinessLevel << endl;
    }
}
  
void adoptAPet(Pet pets[], int numPets, Adopter &adopter)
{
    int index;
    cout << "Enter the index of the pet you want to adopt: ";
    cin >> index;
    if (index >= 1 && index <= numPets)
    {
      adopter.adoptPet(pets[index - 1]);
      cout << "Pet " << index << " has been adopted by " << adopter.adopterName << endl;
    }
    else
    {
      cout << "Invalid index." << endl;
    }
}
  
void returnAPet(Pet pets[], int numPets, Adopter &adopter)
{
    int index;
    cout << "Enter the index of the pet you want to return: ";
    cin >> index;
    if (index >= 1 && index <= numPets)
    {
      adopter.returnPet(pets[index - 1]);
      cout << "Pet " << index << " has been returned by " << adopter.adopterName << endl;
    }
    else
    {
      cout << "Invalid index." << endl;
    }
}
  
void displayAdoptedPets(Adopter adopter)
{
    adopter.displayAdoptedPets();
}
  
void addPets(Pet pets[], int numPets)
{
    string healthStatus, specialSkills;
    int hungerLevel, happinessLevel;
    cin.ignore();
    cout << "Enter the health status of the pet: ";
    getline(cin, healthStatus);
    cout << "Enter the happiness level of the pet: ";
    cin >> happinessLevel;
    cout << "Enter the hunger level of the pet: ";
    cin >> hungerLevel;
    cout << "Enter the special skills of the pet: ";
    getline(cin, specialSkills);
    pets[numPets] = Pet(healthStatus, specialSkills, hungerLevel, happinessLevel);
    numPets++;
    cout << "Pet has been added." << endl;
}
  
  
void interactWithAPet();
  
  
int main()
{
    cout << "RAYYAN MERCHANT-23K-0073" << endl;
    Pet pets[10];
    int numPets = 0;
    Adopter adopter("Rayyan", "0101010101");
    Adopter adopter2("Ukkashah", "0202020202");
    Adopter adopter3("Sabeeh", "0303030303");
    int choice;
    do
    {
      menu();
      cout << "Enter your choice: ";
      cin >> choice;
      switch(choice)
      {
        case 1:
          showAllPets(pets, numPets);     
          break;
        case 2:
          adoptAPet(pets, numPets, adopter);
          break;
        case 3:
          returnAPet(pets, numPets, adopter);
          break;
        case 4:
          displayAdoptedPets(adopter);
          break;
        case 5:
          addPets(pets, numPets);
          break;
        case 6:
          interactWithAPet();
          break;
        case 7:
          cout << "Exiting..." << endl;
          break;
        default:
          cout << "Invalid choice." << endl;
      }
  
    }while(choice != 7);
  
    return 0;
}
  
  
