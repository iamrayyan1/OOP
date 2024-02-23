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
    Book() : totalPages(1000), currentPage(0) {}

    void setName(string Name)
    {
      name = Name;
    }
    void setAuthor(string Author)
    {
      author = Author;
    }
    void setISBN(int isbn)
    {
      ISBN = isbn;
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


    showBookInfo()
    {
      cout<<"Name: "<<name<<endl;
      cout<<"Author: "<<author<<endl;
      cout<<"ISBN: "<<ISBN<<endl;
      cout<<"Total Pages: "<<totalPages<<endl;
      cout<<"Current Page: "<<currentPage<<endl;
    }


};

int main()
{
  Book book;
  book.setName("MERI KITAAB");
  book.setAuthor("RAYYAN");
  book.setISBN(3244);
  book.reading();
  book.showBookInfo();
  return 0;
}
