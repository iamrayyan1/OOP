#include<iostream>
#include<string>
using namespace std;

class Book
{
private:
  string name;
  string author;
  int ISBN;
  int totalPages;
  int currentPage;

public:
  Book()
  {
    name = "";
    author = "";
    ISBN = 0;
    totalPages = 0;
    currentPage = 0;
  }
  Book(string Name, string Author, int isbn, int TotalPages, int CurrentPage)
  {
    name = Name;
    author = Author;
    ISBN = isbn;
    totalPages = TotalPages;
    currentPage = CurrentPage;
  }

  void reading()
  {
    if(currentPage == totalPages)
    {
      cout<<"You have finished the book"<<endl;
    }
    else if(currentPage < totalPages)
    {
      currentPage++;
      cout<<"You have read page"<<currentPage<<endl;
    }
    else(currentPage > totalPages)
    {
      cout<<"Invalid input"<<endl;
    }
    
  }

};


int main()
{
  Book book = {"MERI KITAAB", "RAYYAN", 123, 7, 0};
  book.reading();
  for(int i=0; i<7; i++)
  {
    book.reading();
  }
  
  
}

