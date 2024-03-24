#include<iostream>
#include<string>
using namespace std;

class Book{
protected:
  string title;
  string author;
  string publisher;

public:

  Book(string title, string author, string publisher) : title(title), author(author), publisher(publisher) {}

  void display(){
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "Publisher: " << publisher << endl;
  }

};

class FictionBook : public Book{

private:
  string genre;
  string protagonist;

public:  
  FictionBook(string title, string author, string publisher, string genre, string protagonist) : Book(title, author, publisher), genre(genre), protagonist(protagonist) {}

  void display(){
    Book::display();
    cout << "Genre: " << genre << endl;
    cout << "Protagonist: " << protagonist << endl;
  }

};

int main(){
  FictionBook book1("Hobbit", "JK Rowling", "ABC", "Fantasy", "Frodo");
  FictionBook book2("MERI KAHANI", "RAYYAN", "XYZ", "BIOGRAPHY", "KAHANI");
  book1.display();
  book2.display();
  return 0;
}
