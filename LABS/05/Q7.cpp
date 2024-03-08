
#include<iostream>
#include<string>
using namespace std;

class MenuItem 
{
public:
  string name;
  float price;
  MenuItem(string n = "", float p = 0.0) : name(n), price(p) {}
};

class Menu 
{
private:
  static const int MAX_ITEMS = 10; 
  MenuItem menuList[MAX_ITEMS];
  int itemCount;

public:
  Menu() : itemCount(0) {}

  void addItem(MenuItem& item) 
  {
    if (itemCount < MAX_ITEMS) 
    {
      menuList[itemCount++] = item;
    } 
    else 
    {
      cout << "Menu is full. Cannot add more items." << endl;
    }
  }

  void removeItem(int index) 
  {
    if (index >= 0 && index < itemCount) 
    {
      for (int i = index; i < itemCount - 1; ++i) 
      {
        menuList[i] = menuList[i + 1];
      }
      --itemCount;
      } 
    else 
    {
      cout << "Invalid index. No item removed." << endl;
    }
  }

  MenuItem getItem(string name) 
  {
    for (int i = 0; i < itemCount; ++i) 
    {
      if (name == menuList[i].name) 
      {
        return menuList[i];
      }
    }
      return MenuItem(); // Return an empty MenuItem if not found
  }

  void display() 
  {
    for (int i = 0; i < itemCount; ++i) 
    {
      cout << "Name: " << menuList[i].name << "\nPrice: " << menuList[i].price << "\n\n";
    }
  }
};

class Payment 
{
public:
  float amount;

  Payment(float a = 0.f) : amount(a) {}
};

class Order 
{
private:
  static const int MAX_ITEMS = 10;
  MenuItem items[MAX_ITEMS];
  int itemCount;
  Payment payment;

public:
  Order() : itemCount(0), payment(0.f) {}

  void addItem(MenuItem item) 
  {
    if (itemCount < MAX_ITEMS) 
    {
      items[itemCount++] = item;
      payment.amount += item.price;
    } 
    else 
    {
      cout << "Order is full. Cannot add more items." << endl;
    }
  }

  float getTotal()
  {
    return payment.amount;
  }
};

class Restaurant 
{
  Menu menu;

public:
  void addMenuItem(MenuItem item) 
  {
    menu.addItem(item);
  }

  void removeMenuItem(int index) 
  {
    menu.removeItem(index);
  }

  MenuItem getItem(string name) 
  {
    return menu.getItem(name);
  }

  void displayMenu() 
  {
    menu.display();
  }

  Order placeOrder(MenuItem items[], int itemCount) 
  {
    Order order;
    for (int i = 0; i < itemCount; ++i) 
    {
      order.addItem(items[i]);
    }
    return order;
  }
};

int main() 
{
  Restaurant restaurant;
  Order order;

  restaurant.addMenuItem(MenuItem{"Burger", 5.99f});
  restaurant.addMenuItem(MenuItem{"Pizza", 8.99f});
  restaurant.addMenuItem(MenuItem{"Salad", 6.49f});

  cout << "Menu:\n";
  restaurant.displayMenu();

  while(true) 
  {
    int choice;
    cout << "\t1. Enter menu item\n\t2. Place Order\n";
    cin >> choice;

    if (choice == 1) 
    {
      string name;
      cout << "Enter name: ";
      cin >> name;
      order.addItem(restaurant.getItem(name));
    } 
    else if (choice == 2) 
    {
      cout << "Total: " << order.getTotal() << endl;
      break;
    } 
    else 
    {
      cout << "Incorrect input\n";
      continue;
    }
  }

  return 0;
}
