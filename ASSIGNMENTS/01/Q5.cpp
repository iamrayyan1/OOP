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
    int r_count;
    int a_count;

    User(string n, int a, string m)
    {
      name = n;
      age = a;
      mobile_number = m;
      r_count = 0;
      a_count = 0;
    }

    void accumulate_coupon(BOGOCoupon coupon)
    {
      coupons_list[a_count] = coupon;
      a_count++;
      cout << "Coupon accumulated: " << coupon.coupon_code << endl;
    }

    bool has_valid_coupon(string restaurant_code)
    {
      for(int i = 0; i < a_count; i++)
      {
        if(coupons_list[i].is_valid(restaurant_code, current_date)
        {
          return true;
          cout << "Coupon is valid." << endl;
        }
        else
        {
          return false;
          cout << "Coupon is not valid." << endl;
        }
      }
    }

    void redeem_coupon(string coupon_code)
    {
      for(int i = 0; i < a_count; i++)
      {
        if(coupons_list[i].coupon_code == coupon_code)
        {
          if(coupons_list[i].is_valid(restaurant_code, current_date))
          {
            redeemed_coupons_list[r_count] = coupons_list[i];
            r_count++;
            cout << "Coupon redeemed: " << coupons_list[i].coupon_code << endl;
            coupons_list[i] = coupons_list[a_count-1];
            a_count--;
            return;
          }
        }
      }
    }

  };


  int main() 
  {
      cout << "Rayyan Merchant- 23k-0073" << endl;

      Restaurant food_haven("Food Haven", "City Center");
      Restaurant pixel_bites("Pixel Bites", "Cyber Street");

      BOGOCoupon coupon1("FH-BOGO-12345", "2023-05-01", "2023-05-31", "Food Haven");
      BOGOCoupon coupon2("PB-BOGO-67890", "2023-06-01", "2023-06-30", "Pixel Bites");

      User user1("Rayyan", 19, "45543");
      User user2("Simran", 20, "55443");

      user1.accumulate_coupon(coupon1);
      user1.accumulate_coupon(coupon2);
      user2.accumulate_coupon(coupon1);
      user2.accumulate_coupon(coupon2);
      user1.redeem_coupon("FH-BOGO-12345");
      user2.redeem_coupon("PB-BOGO-67890");

      int choice;
      string restaurant_name;
      cout << "Welcome to the BOGO" << endl;
      do {
          cout << "Main Menu:" << endl;
          cout << "1. Select a Restaurant" << endl;
          cout << "2. Exit" << endl;
          cout << "Enter your choice: ";
          cin >> choice;

          switch (choice) 
          {
          case 1:
              cout << "Select a restaurant:" << endl;
              cout << "1. Food Haven" << endl;
              cout << "2. Pixel Bites" << endl;
              cout << "Enter your choice: ";
              cin >> choice;

              if (choice == 1) 
              {
                  restaurant_name = "Food Haven";
              } 
              else if (choice == 2) 
              {
                  restaurant_name = "Pixel Bites";
              } 
              else
              {
                  cout << "Invalid choice" << endl;
                  continue;
              }

              if (restaurant_name == "Food Haven") 
              {
                  food_haven.display_menu();
              } 
              else if 
              (restaurant_name == "Pixel Bites")
              {
                  pixel_bites.display_menu();
              }

              do
              {
                  cout << "Restaurant Operations:" << endl;
                  cout << "1. Generate Bill" << endl;
                  cout << "2. Apply Discount" << endl;
                  cout << "3. Redeem Coupon" << endl;
                  cout << "4. Return to Main Menu" << endl;
                  cout << "Enter your choice: ";
                  cin >> choice;

                  switch (choice) 
                  {
                      case 1:
                          if (restaurant_name == "Food Haven")
                          {
                            food_haven.generate_bill();
                          }
                          else
                          {
                            pixel_bites.generate_bill();
                          }
                      break;
                      case 2:
                          if (restaurant_name == "Food Haven")  
                          {
                            food_haven.apply_discount();
                          }
                          else
                          {
                            pixel_bites.apply_discount();
                          }
                      break;
                      case 3:
                          if (restaurant_name == "Food Haven")  
                          {
                            food_haven.redeem_coupon();
                          }
                          else
                          {
                            pixel_bites.redeem_coupon();
                          }
                      break;
                      case 4:
                      break;
                      default:
                      cout << "Invalid choice" << endl;
                  }
              } while (choice != 4);
              break;
      case 2:
        cout << "Exiting..." << endl;
    break;
              default:
                  cout << "Invalid choice" << endl;
          }
      } while (choice != 2);

      return 0;
  }
  
