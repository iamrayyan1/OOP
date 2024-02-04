#include<iostream>
#include<string>
using namespace std;
struct Event{
  string name;
  string date;
  string venue;
  string organizer;
  };

int main()
{
  int n;
  cout<<"Enter the number of events: ";  
  cin>>n;

  Event* events = new Event[n];
  for(int i=0;i<n;i++)
  {
    cout<<"Enter the name of event "<<i+1<<": ";
    cin>>events[i].name;
    cout<<"Enter the date of event "<<i+1<<": ";
    cin>>events[i].date;
    cout<<"Enter the venue of event "<<i+1<<": ";
    cin>>events[i].venue;
    cout<<"Enter the organizer of event "<<i+1<<": ";
    cin>>events[i].organizer;
  }

  cout<<"All events: "<<endl;
  for(int i=0;i<n;i++)
  {
    cout<<"Event "<<i+1<<": "<<endl;
    cout<<"Name: "<<events[i].name<<endl;
    cout<<"Date: "<<events[i].date<<endl;
    cout<<"Venue: "<<events[i].venue<<endl;
    cout<<"Organizer: "<<events[i].organizer<<endl;
  }

  string search_date;
  cout<<"Enter the date to search for events: ";
  cin>>search_date;
  cout<<"Events on "<<search_date<<":"<<endl;
  for(int i=0;i<n;i++)
  {
    if(events[i].date == search_date)
    {
      cout<<"Event "<<i+1<<": "<<endl;
      cout<<"Name: "<<events[i].name<<endl;
      cout<<"Date: "<<events[i].date<<endl;
      cout<<"Venue: "<<events[i].venue<<endl;
      cout<<"Organizer: "<<events[i].organizer<<endl;
    }
  } 
  delete[] events;
}
