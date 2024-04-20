
#include <iostream>
using namespace std;

class Decrement{
private:
  int num;
public:
  Decrement(int n){
    num = n;
  }
  int getNum() { return num; }
  Decrement operator -- (){
    Decrement temp(num);
    num = num * 4;
    return temp;
  }
  Decrement operator -- (int){
    Decrement temp(num);
    num = num / 4;
    return temp;
  }
};

int main(){
  Decrement num1(12);
  cout << "Before decrement: " << num1.getNum() << endl;
  --num1;
  cout << "After decrement: " << num1.getNum() << endl;
  Decrement num2(12);
  cout << "Before decrement: " << num2.getNum() << endl;
  num2--;
  cout << "After decrement: " << num2.getNum() << endl;
  return 0;
  
}
