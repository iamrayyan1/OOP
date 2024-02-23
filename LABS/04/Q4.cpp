#include<iostream>
#include<string>
using namespace std;

class Office
{
private:
  string Location = " ";;
  int SeatingCapacity = 0;;
  string Furniture[3] = {"", "", ""};

public:
  Office(string location, int seatingCapacity, string furniture[3]) : Location(location), SeatingCapacity(seatingCapacity), Furniture(furniture) {}

  void display()
  {
    cout<<"Location: "<<Location<<endl;
    cout<<"Seating Capacity: "<<SeatingCapacity<<endl;
    cout << "Furniture: ";
    for (int i = 0; i < 3; ++i) 
    {
      cout << Furniture[i] << " ";
    }
    cout << endl;
    
  }

};

int main()
{
  Office office1("Karachi", 300, {"Chair", "Table", "Sofa"});
  Office office2("Lahore", 200, {"Kursi", "Desk", "Sleeping Bags"});
  Office office3("Islamabad", 900, {"aaa", "zzz", "xcc"});
  Office office4;
  return 0;
}
