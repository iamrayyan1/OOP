#include<iostream>
using namespace std;

int main() 
{
    int num;
    int flag = 0;

    cout << "Enter a number: ";
    cin >> num;

    if(num <= 1) {
        cout << "Not a Prime number";
    }
    else {
        for(int i = 2; i <= num/2; i++) {
            if(num % i == 0) {
                flag = 1;
                break;
            }
        }

        if(flag) {
            cout << "Not a Prime number";
        }
        else {
            cout << "Prime Number";
        }
    }

    return 0;
}
