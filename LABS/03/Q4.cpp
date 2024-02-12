#include<iostream>
#include<string>
using namespace std;

class Smartphone
{
  private:
    string brand;
    string model;
    int displayResolution;
    int ram;
    int rom;
    int storage;

  public:


    void setBrand(string newBrand)
    {
      brand = newBrand;
    }
    void setModel(string newModel)
    {
      model = newModel;
    }
    void setDisplayResolution(int newDisplayResolution)
    {
      displayResolution = newDisplayResolution;
    }
    void setRam(int newRam)
    {
      ram = newRam;
    }
    void setRom(int newRom)
    {
      rom = newRom;
    }
    void setStorage(int newStorage)
    {
      storage = newStorage;
    }


    string getBrand(){
      cout<<"Enter the brand: "<<endl;
      getline(cin, brand);
      return brand;
    }
    string getModel(){
      cout<<"Enter the model: "<<endl;
      getline(cin, model);
      return model;
    }
    int getDisplayResolution(){
      cout<<"Enter the display resolution: "<<endl;
      cin>>displayResolution;
      return displayResolution;
    }
    int getRam(){
      cout<<"Enter the Ram: "<<endl;
      cin>>ram;
      return ram;
    }
    int getRom(){
      cout<<"Enter the Rom: "<<endl;
      cin>>rom;
      return rom;
    }
    int getStorage(){
      cout<<"Ente the storage capacity: "<<endl;
      cin>>storage;
      return storage;
    }


    void makePhoneCall()
    {
      cout << "Making phone call" << endl;
    }
    void sendMessage()
    {
      cout << "Sending message" << endl;  
    }
    void connectToWifi()
    {
      cout << "Connecting to Wifi" << endl;
    }
    void browseInternet()
    {
      cout << "Browsing the internet" << endl;
    }

};


//display details:
void displayDetails(Smartphone smartphone)
{
  cout<< "Brand: " << smartphone.getBrand() << endl;
  cout<< "Model: " << smartphone.getModel() << endl;
  cout<< "Display Resolution: " << smartphone.getDisplayResolution() << endl;
  cout<< "RAM: " << smartphone.getRam() << endl;
  cout<< "ROM: " << smartphone.getRom() << endl;
  cout<< "Storage: " << smartphone.getStorage() << endl;
}

//performing actions:
void actions(Smartphone smartphone)
{
  cout<<"What you want to do:"<<endl;
  cout<<"1. Make a phone call"<<endl<<"2. Send a message"<<endl<<"3. Connect to Wifi"<<endl<<"4. Browse the internet"<<endl;
  int choice;
  cin>>choice;
  switch(choice)
  {
    case 1:
      smartphone.makePhoneCall();
      break;
    case 2:
      smartphone.sendMessage();
      break;
    case 3:
      smartphone.connectToWifi();
      break;
    case 4:
      smartphone.browseInternet();
      break;
    default:
      cout<<"Invalid choice"<<endl;
  }
}

int main()
{
  Smartphone smartphone;
  
  smartphone.setBrand(smartphone.getBrand());
  smartphone.setModel(smartphone.getModel());
  smartphone.setDisplayResolution(smartphone.getDisplayResolution());
  smartphone.setRam(smartphone.getRam());
  smartphone.setRom(smartphone.getRom());
  smartphone.setStorage(smartphone.getStorage());
  
  displayDetails(smartphone);
  actions(smartphone);
  return 0;
}


