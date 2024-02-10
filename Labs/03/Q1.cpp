#include<iostream>
using namespace std;

class BoardMarker{
  private:
    string brand;
    string shade;
    bool refillable;
    bool inkStatus;
  public:
    BoardMarker(string brand, string shade, bool refillable, bool inkStatus) : brand(brand), shade(shade), refillable(refillable), inkStatus(inkStatus){
      
    }
    string getBrand(){
      return brand;
    }
    string getShade(){
      return shade;
    }
    bool getRefillable(){
      return refillable;
    }
    bool getInkStatus(){
      return inkStatus;
    }

    void write(string ){
      if(inkStatus == true){
        cout << "Ink has run out" << endl;
      }
      else{
        cout << "Ink is not depleted" << endl;
      }
    }

    void refill(){
      if(refillable == true)
      {
        cout << "Refill the board marker" << endl;
      }
      else{
        cout << "The board marker is not refillable" << endl;
      }
    }

  
};

int main(){
  BoardMarker boardMarker("Dollar", "Black", true, true);
  boardMarker.write("Dollar");
  boardMarker.refill();
  
  return 0;
}
