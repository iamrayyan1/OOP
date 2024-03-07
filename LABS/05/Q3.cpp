#include<iostream>
#include<string>
using namespace std;

class ValidateString
{
private:
  string str;

public:
  ValidateString(string str) : str(str) {}

  // If you do not make your function constant, it means that the function is allowed to modify the member variables of the class
  bool valid() const
  {
    for(int i = 0; i < str.length(); i++)
    {
      if(!isalpha(str[i]))
      {
        cout << "Invalid string" << endl;
        return false;
      }
    }
    cout << "Valid string" << endl;
    return true;
  }

};

int main()
{
  string str1 = "my name is rayyan";
  string str2 = "rayyyy";
  string str3 = "taass32";

  ValidateString string1(str1);
  string1.valid();
  ValidateString string2(str2);
  string2.valid();
  ValidateString string3(str3);
  string3.valid();

  return 0;
}
