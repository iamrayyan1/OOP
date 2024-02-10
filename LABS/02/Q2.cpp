#include<iostream>
#include<string>
using namespace std;
const int MAX_BOOKS = 100;

struct Book{
  string title;
  string author;
  int year;
  string genre;
};

//adding books
void addBook(Book books[], int& numBooks)
{
  if(numBooks >= MAX_BOOKS)
  {
    cout<<"Library is full. Cannot add more books."<<endl;
    return;
  }
  Book newBook;
  cout<<"Enter book title: ";
  getline(cin, newBook.title);
  cout<<"Enter book author: ";
  getline(cin, newBook.author);
  cout<<"Enter book year: ";
  cin>>newBook.year;
  cout<<"Enter book genre: ";
  getline(cin, newBook.genre);

  books[numBooks] = newBook;
  numBooks++;
  cout<<"Book added successfully."<<endl;
}

//display books
void displayBooks(Book books[], int numBooks)
{
  if(numBooks == 0)
  {
    cout<<"No books in the library."<<endl;
  }
  else
  {
    cout<<"Books in the library:"<<endl;
    for(int i=0; i<numBooks; i++)
    {
      cout<<"Title: "<<books[i].title<<endl;
      cout<<"Author: "<<books[i].author<<endl;
      cout<<"Year: "<<books[i].year<<endl;
      cout<<"Genre: "<<books[i].genre<<endl;
      cout<<"------------------------"<<endl;
    }
  }
}

//search books
void searchBooks(Book books[], int numBooks)
{
  string search;
  cout<<"Enter book title or author to search: ";
  getline(cin, search);
  for(int i=0; i<numBooks; i++)
  {
    if(books[i].title == search || books[i].author == search)
    {
      cout<<"Book found:"<<endl;
      cout<<"Title: "<<books[i].title<<endl;
      cout<<"Author: "<<books[i].author<<endl;
      cout<<"Year: "<<books[i].year<<endl;
      cout<<"Genre: "<<books[i].genre<<endl;
      cout<<"------------------------"<<endl;
    }
  }
  cout<<"Book not found."<<endl;
}

// Update book
void updateBook(Book books[], int numBooks) 
{  
  string search;
  cout << "Enter book title or author to update: ";
  getline(cin, search);
  for (int i = 0; i < numBooks; i++) 
  {
    if (books[i].title == search || books[i].author == search) 
    {
      int choice;
      cout << "What changes you want to make: " << endl << "1. Book Title" << endl << "2. Book Author" << endl << "3. Book Year" << endl << "4. Book Genre" << endl;
      cin >> choice;

      switch (choice) 
      {
        case 1:
          cout << "Enter new book title: ";
          getline(cin, books[i].title);
          break;
        case 2:
          cout << "Enter new book author: ";
          getline(cin, books[i].author);
          break;
        case 3:
          cout << "Enter new book year: ";
          cin >> books[i].year;
          cin.ignore(); // Ignore newline character
          break;
        case 4:
          cout << "Enter new book genre: ";
          getline(cin, books[i].genre);
          break;
        default:
          cout << "Invalid choice. Please try again." << endl;
      }
      cout << "Book updated successfully." << endl;
      return; 
    }
  }
  cout << "Book not found." << endl;
}


int main()
{
  Book books[MAX_BOOKS];
  int numBooks = 0;
  int choice;
  do
  {
    cout<<"Library Management System"<<endl;
    cout<<"1. Add Book"<<endl;
    cout<<"2. Display Books"<<endl;
    cout<<"3. Search Books"<<endl;
    cout<<"4. Update Book"<<endl;
    cout<<"5. Exit"<<endl;

    cout<<"Enter your choice: ";
    cin>>choice;
    cin.ignore();

    switch(choice) 
    {
      case 1:
        addBook(books, numBooks);
        break;
      case 2:
        displayBooks(books, numBooks);
        break;
      case 3:  
        searchBooks(books, numBooks);
        break;
      case 4:
        updateBook(books, numBooks);
        break;
      case 5:
        cout<<"Exiting the program."<<endl;
        break;
      default:
        cout<<"Invalid choice. Please try again."<<endl;
    }
  } while (choice != 5);
  return 0;
}
