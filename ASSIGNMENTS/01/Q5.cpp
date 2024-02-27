#include <iostream>
#include <string>
using namespace std;

class Restaurant
{
private:
  string restaurant_name;
  string location;
  string menu_list[10];
  int price_list[10];
  string valid_coupon_codes_list[10];
  int coupons_redeemed_count;
  static int total_coupons_redeemed;

public:
  Restaurant()
  {
    restaurant_name = "";
    location = "";
    for (int i = 0; i < 10; i++)
    {
      menu_list[i] = "";
      price_list[i] = 0;
      valid_coupon_codes_list[i] = "";
    }
    coupons_redeemed_count = 0;
  }

  Restaurant(string name, string loc)
  {
    restaurant_name = name;
    location = loc;
    for (int i = 0; i < 10; i++)
    {
      menu_list[i] = "";
      price_list[i] = 0;
      valid_coupon_codes_list[i] = "";
    }
    coupons_redeemed_count = 0;
    
  }

  void display_menu()
  {
    cout << "Menu of " << restaurant_name << ":" << endl;
    for (int i = 0; i < 10; i++)
    {
      if (menu_list[i] != "")
      {
        cout << menu_list[i] << " - $" << price_list[i] << endl;
      }
    }
  }

  void generate_bill()
  {
    for (int i : bill) 
    {
      cout << "[" << i << "]: " <<  menu_list[i] << " -> $" << price_list[i] << endl;
      total += price_list[i];
    }
    cout << "Total: $" << total << endl;
  }
  
  void apply_discount() 
  {
    int count = 0;
      for (int i : bill) 
      {
        for (int j : bill)
        {
          if (i == j) count++;
          {
            if (count >= 2) 
            { 
              cout << "Discounted: $" << total - price_list[i] << endl; 
              return;
            }
          }  
        }
      }
    cout << "No discount applied." << endl;
  }
};

int Restaurant::total_coupons_redeemed = 0;

class BOGOCoupon
{
public:
  string coupon_code;
  string valid_from;
  string valid_until;
  string restaurant_code;

public:
  BOGOCoupon(string code, string from, string until, string restaurant)
  {
    coupon_code = code;
    valid_from = from;
    valid_until = until;
    restaurant_code = restaurant;
  }

  bool is_valid(string restaurant_code, string current_date)
  {
    if (this->restaurant_code == restaurant_code && current_date >= valid_from && current_date <= valid_until)
    {
      return true;
    }
    return false;
  }
                                      
};


class User
{
public:
  string name;
  int age;
  string mobile_number;
  int bill[10];
  int coupons_list[10];
  int redeemed_coupons_list[10];
  int coupons_redeemed_count;

  
}
              
                                  
