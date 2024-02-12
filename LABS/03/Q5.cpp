#include<iostream>
#include<string>
using namespace std;

class StationaryShop
{
  private:
    string items[100];
    float prices[100];
  public:
    StationaryShop() : items(), prices() {}

    void addItem(string item, float price)
    {
      for(int i = 0; i < 100; i++)
      {
        if(items[i] == "")
        {
          items[i] = item;
          prices[i] = price;
          cout<< "Item added successfully" << endl;
          break;
        }
      }
    }

    void displayItems()
    {
      cout<< "Items: " << endl;
      for(int i = 0; i < 100; i++)
      {
        if(items[i] != "")
        {
          cout << items[i] << " - " << prices[i] << endl;
        }
      }
    }

    void modifyPrice(string item, float newPrice)
    {
      for(int i = 0; i < 100; i++)
      {
        if(items[i] == item)
        {
          prices[i] = newPrice;
          cout<< "Price modified successfully" << endl;
          break;
        }
        else
        {
          cout << "Item not found" << endl;
        }
      }
    }

    void generateReceipt(string items[], int prices[], int numItems)
    {
      float total = 0;
      cout<< "Receipt: " << endl;
      for(int i = 0; i < numItems; i++)
      {
        for(int j = 0; j < 100; j++)
        {
          if(items[i] == items[j])
          {
            total += prices[j] * quantities[i];
            cout << items[i] << " - " << quantities[i] << " - " << prices[j] << endl;
            break;
          }
        }
      }
      cout << "Total: " << total << endl;
      cout << "Thank you for shopping with us!" << endl;
    }

};



int main()
{
  StationaryShop shop;
  int choice;

  do
  {
    cout << "1. Add item" << endl << "2. Display items" << endl << "3. Modify" << endl << "4. Generate receipt" << endl << "5. Exit" << endl;
    cin >> choice;

    switch(choice)
    {
      case 1:
        string item;
        float price;
        cout << "Enter the item: ";
        getline(cin, item);
        cout << "Enter the price: ";
        cin >> price;
        shop.addItem(item, price);
        break;
      case 2:
        shop.displayItems();
        break;
      case 3:
        string item;
        float newPrice;
        cout << "Enter the item: ";
        getline(cin, item);
        cout << "Enter the new price: ";
        cin >> newPrice;
        shop.modifyPrice(item, newPrice);
        break;
      case 4:
        string items[100];
        int quantities[100];
        int numItems;
        cout << "Enter the number of items: ";
        cin >> numItems;



      case 5:
        cout << "Exiting" << endl;
        break;
      default:
        cout << "Invalid choice" << endl;
    }  
  } while(choice > 5 || choice < 1);
  return 0;
}
