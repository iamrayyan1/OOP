  #include<iostream>
#include<string>
using namespace std;

class Office
{
private:
  string Location = " ";;
  int SeatingCapacity = 0;;
  string *Furniture;

public:
  Office(string location, int seatingCapacity, int size) : Location(location), SeatinCapacity(seatingCapacity), Furniture(new string[size]) {}

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
  ~Office() { delete[] Furniture; }
};


int main()
{
  Office *office1 = new Office("Karachi", 300, 3);
  Office *office2 = new Office("Lahore", 200, 5);
  Office *office3 = new Office("Islamabad", 900, 4);

  delete office1;
  delete office2;
  delete office3;
  return 0;
}
