#include<iostream>
#include<string>
using namespace std;

class DarazPersonData{
private:
  string lastName, firstName, address, city, state, zip, phone;

public:
  DarazPersonData(string lastName, string firstName, string address, string city, string state, string zip, string phone) : lastName(lastName), firstName(firstName), address(address), city(city), state(state), zip(zip), phone(phone) {}

  string getFirstName() { return firstName; }
  string getLastName() { return lastName; }
  string getAddress() { return address; }
  string getCity() { return city; }
  string getState() { return state; }
  string getZip() { return zip; }
  string getPhone() { return phone; }
  
  void setFirstName(string firstName) { this->firstName = firstName; }
  void setLastName(string lastName) { this->lastName = lastName; }
  void setAddress(string address) { this->address = address; }
  void setCity(string city) { this->city = city; }
  void setState(string state) { this->state = state; }
  void setZip(string zip) { this->zip = zip; }
  void setPhone(string phone) { this->phone = phone; }

};

class DarazCustomerData : public DarazPersonData{
private:
  int customerNumber, loyaltyPoints;
  static int CustomerNumber;
public:
  DarazCustomerData(string lastName, string firstName, string address, string city, string state, string zip, string phone) : DarazPersonData(lastName, firstName, address, city, state, zip, phone), customerNumber(CustomerNumber++), loyaltyPoints(0) {}

  int getCustomerNumber() { return customerNumber; }
  int getLoyaltyPoints() { return loyaltyPoints; }
  void setCustomerNumber(int customerNumber) { this->customerNumber = customerNumber; }
  void setLoyaltyPoints(int loyaltyPoints) { this->loyaltyPoints = loyaltyPoints; }
  void addLoyaltyPoints(int points) { loyaltyPoints += points; }
  void redeemLoyaltyPoints(int points) { loyaltyPoints -= points; }
  void displayLoyaltyPoints() { cout << "Total loyalty points: " << loyaltyPoints << endl; }

};

int DarazCustomerData::CustomerNumber = 1;

class DarazLoyaltyProgram{
  private:
    DarazCustomerData* customer;

  public:
    DarazLoyaltyProgram(DarazCustomerData* customer) : customer(customer) {}

    void addLoyaltyPoints(int points){
      customer->addLoyaltyPoints(points); 
    }
    void redeemLoyaltyPoints(int points){
      if(customer->getLoyaltyPoints() >= points){
        customer->redeemLoyaltyPoints(points);
        cout << "Loyalty points redeemed successfully!\t" << customer->getLoyaltyPoints() << " Loyalty Points Left" << endl;
      }
      else{
        cout << "Not enough loyalty points to redeem." << endl;
      }
    }
    void displayLoyaltyPoints() {
      cout << "Total Loyalty Points: " << customer->getLoyaltyPoints() << endl;
    }
      
};

void print(DarazCustomerData customer) {
  cout << "Customer ID: " << customer.getCustomerNumber() << endl;
  cout << "Name: " << customer.getFirstName() + " " + customer.getLastName() << endl;
  cout << "Total Loyalty Points: " << customer.getLoyaltyPoints() << endl;
  cout << "Address: " << customer.getAddress() << endl;
  cout << "City: " << customer.getCity() << endl;
  cout << "Phone: " << customer.getPhone() << endl;
  cout << "Zip: " << customer.getZip() << endl;
  cout << "State: " << customer.getState() << endl;
}

int main(){
  cout << "Rayyan Merchant\n23K-0073\n\n";
  cout << "Daraz Loyalty Program" << endl;
  DarazCustomerData customer("Rayyan", "Merchant", "abc st", "Karachi", "Sindh", "2286", "0335-2034811" );
  DarazLoyaltyProgram loyaltyProgram(&customer);
  loyaltyProgram.addLoyaltyPoints(10);
  loyaltyProgram.redeemLoyaltyPoints(5);
  loyaltyProgram.redeemLoyaltyPoints(10);
  loyaltyProgram.displayLoyaltyPoints();
  print(customer);
  return 0;
} 
