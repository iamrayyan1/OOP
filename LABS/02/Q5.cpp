#include<iostream>
#include<string>
using namespace std;

struct Product
{
  string id;
  string name;
  int price;
  int quantity;
  bool inStock;
  string description;
};

//Adding Products
void addProduct(Product products[], int& numProducts)
{
  if(numProducts >= 100)
  {
    cout<<"Maximum number of products reached."<<endl;
  }
  else
  {
    Product newProduct;
    cout<<"Enter product ID: ";
    getline(cin, newProduct.id);
    cout<<"Enter product name: ";
    getline(cin, newProduct.name);
    cout<<"Enter product price: ";
    cin>>newProduct.price;
    cout<<"Enter product quantity: ";
    cin>>newProduct.quantity;
    if(newProduct.quantity > 0) newProduct.inStock = true;
    else newProduct.inStock = false;
    cout<<"Enter product description: ";
    getline(cin, newProduct.description);

    products[numProducts] = newProduct;
    numProducts++;
    cout<<"Product added successfully."<<endl;
  }
}

//Displaying Products
void displayProduct(Product products[], int numProducts, string productId)
{
  bool found = false;
  for(int i = 0; i < numProducts; i++)
  {
    if(products[i].id == productId)
    {
      cout<<"Product ID: "<<products[i].id<<endl;
      cout<<"Product name: "<<products[i].name<<endl;
      cout<<"Product price: "<<products[i].price<<endl;
      cout<<"Product quantity: "<<products[i].quantity<<endl;
      cout<<"Product description: "<<products[i].description<<endl;
      found = true;
      break;
    }
  }
  if(found == false) cout<<"Product not found."<<endl;
}

//Updating Products
void updateProduct(Product products[], int numProducts, string productId)
{
  for(int i = 0; i < numProducts; i++)
  {
    if(products[i].id == productId)
    {
      int choice;
      cout<<"What do you want to update: "<<endl;
      cout<<"1. Product name"<<endl<<"2. Product price"<<endl<<"3. Product quantity"<<endl<<"4. Product description"<<endl;
      cin>>choice;
      switch(choice)
      {
        case 1:
          cout<<"Enter new product name: ";
          getline(cin, products[i].name);
          break;
        case 2:
          cout<<"Enter new product price: ";
          cin>>products[i].price;
          break;
        case 3:
          cout<<"Enter new product quantity: ";  
          cin>>products[i].quantity;
          break;
        case 4:
          cout<<"Enter new product description: ";
          getline(cin, products[i].description);
          break;
        default:
          cout<<"Invalid choice."<<endl;
      }
      cout<<"Product updated successfully."<<endl;
    }
  }
}

int main()
{
  Product products[100];
  int numProducts = 0;
  int choice;
  string productId;
  do
  {
    cout<<"Product Management System"<<endl;
    cout<<"1. Add product"<<endl;
    cout<<"2. Display product"<<endl;
    cout<<"3. Update product"<<endl;
    cout<<"4. Exit"<<endl;

    cout<<"Enter your choice: ";
    cin>>choice;

    switch(choice)
    {
      case 1:
        addProduct(products, numProducts);
        break;
      case 2:
        cout<<"Enter product ID: ";
        getline(cin, productId);
        displayProduct(products, numProducts, productId);
        break;
      case 3:
        cout<<"Enter product ID: ";
        getline(cin, productId);
        updateProduct(products, numProducts, productId);
        break;
      case 4:
        cout<<"Exiting the program."<<endl;
        break;
      default:
        cout<<"Invalid choice. Please try again."<<endl;
    }
  } while(choice > 4);
  return 0;
}
