#include <iostream>
#include <string>
using namespace std;

class User {
private:
    void display(){
    cout << "User Details: " << endl;
    cout << "Username: " << username << endl;  
    cout << "Email: " << email << endl;
    cout << "Password: " << password << endl;
  }
protected:
    string username;
    string email;
    string password;
    char pw[50];
    int encrypted[50];
public:
    User(string un, string em, string pw) : username(un), email(em), password(pw) {}

    string get_username() {
        return username;
    }
    string get_email() {
        return email;
    }
    string get_password() {
        return password;
    }

    void encrypt() {
        for (int i = 0; i < sizeof(password); i++) {
            pw[i] = password[i];
        }
        for (int i = 0; i < sizeof(password); i++) {
            encrypted[i] = pw[i] + 12;
        }
        cout << "Password encrypted" << endl;
    }

    virtual bool verifyPassword(string password) {
        if (password == this->password) {
            return true;
        }
        else {
            return false;
        }
    }
};

class Post {
protected:
    string postId;
    string content;
    int likes;
    int comments;
    int views;
public:
    Post(string id, string con) : postId(id), content(con), likes(0), comments(0), views(0) {}

    void addLikes() {
        likes++;
    }
    void addComments() {
        comments++;
    }
    void addViews() {
        views++;
    }

    void displayData() {
        cout << "--------------------------------" << endl;
        cout << "Post Id: " << postId << endl;
        cout << "Content: " << content << endl;
        cout << "Likes: " << likes << endl;
        cout << "Comments: " << comments << endl;
        cout << "Views: " << views << endl;
    }
};

class RegularUser : public User {
    static const int MAX_FEED_POSTS = 5;
    Post* posts[MAX_FEED_POSTS];
    int feedSize;
public:
    RegularUser(string un, string em, string pw) : User(un, em, pw) {
        feedSize = 0;
    }
    void addPost(Post* post) {
        if (feedSize < MAX_FEED_POSTS) {
            posts[feedSize] = post;
            feedSize++;
        }
        else {
            cout << "Cannot add post, Max feed size reached." << endl;
        }
    }
    void viewFeed() {
        cout << "Viewing feed...for " << username << endl;
        for (int i = 0; i < feedSize; i++) {
            posts[i]->displayData();
        }
    }
    bool verifyPassword(string password) override {
        if (password == this->password) {
            return true;
        }
        else {
            return false;
        }
    }
};

class BusinessUser : public User {
    static const int MAX_FEED_POSTS = 10;
    int promotedPosts;
public:
    BusinessUser(string un, string em, string pw) : User(un, em, pw) {
        promotedPosts = 0;
    }

    void promotePost(Post* post) {
        if (promotedPosts < MAX_FEED_POSTS) {
            post->addLikes();
            post->addLikes();
            post->addComments();
            post->addViews();
            post->addViews();
            post->addViews();
            post->displayData();
            cout << "Post promoted" << endl;
            promotedPosts++;
        }
        else {
            cout << "Cannot promote post, Max feed size reached." << endl;
        }
    }
    bool verifyPassword(string password) override {
        if (password == this->password) {
            return true;
        }
        else {
            return false;
        }
    }
};

int main() {
    cout << "RAYYAN MERCHANT\n23K-0073\n\n";
    Post* post1 = new Post("1", "My family");
    Post* post2 = new Post("2", "Allah is great");
    Post* post3 = new Post("3", "Football is life");
    Post* post4 = new Post("4", "Messi is Goat");
    Post* post5 = new Post("5", "Babar king");
    string password;


    int choice;
    cout << "1. Regular User" << endl;
    cout << "2. Business User" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    cout << endl << endl;
    if (choice == 1){
       RegularUser reg("rayyanmerchant_", "merchantrayyan43@gmail.com", "SabBataDun?");
       reg.encrypt();

       cout << "Enter regular password: ";
        cin >> password;

       if (reg.verifyPassword(password) == true) {
           cout << "Password verified" << endl;
           reg.addPost(post1);
           reg.addPost(post2);
           reg.addPost(post3);
           reg.addPost(post4);
           reg.addPost(post5);
           reg.viewFeed();
       }
       else {
           cout << "Incorrect Password" << endl;
       }
    }
    else if(choice == 2){
      cout << "Enter business password: ";
      cin >> password;
      BusinessUser bus("lionelmessi", "messi.shortking@gmail.com", "suisui");
      bus.encrypt();
      if (bus.verifyPassword(password) == true) {
          bus.promotePost(post5);
          bus.promotePost(post4);
      }
      else {
          cout << "Incorrect Password" << endl;
      }
      
    }
    else{
      cout << "Invalid choice" << endl;
    }
}


