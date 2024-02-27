


#include<iostream>
#include<string>
using namespace std;

class Table
{
private:
  int totalSeats;
  int seatsOccupied;
  int freeSeats;
  bool isClean;

public:

  Table()
  {
    totalSeats = 4;
    seatsOccupied = 0;
    freeSeats = totalSeats;
    isClean = true;
  }

  Table(int totalSeats)
  {
    if(totalSeats == 4 || totalSeats == 8)
    {
      this->totalSeats = totalSeats;
    }
    else
    {
      this->totalSeats = (totalSeats > 4) ? 8 : 4;
    }
    seatsOccupied = 0;
    freeSeats = totalSeats;
    isClean = true;
  }

  void useTable(int people)
  {
    if(isClean)
    {
      if(people <= freeSeats)
      {
        seatsOccupied += people;
        freeSeats -= people;
        cout << "A Table of" << totalSeats << " has been used by " << people << " people." << endl;
      }
      else
      {
        cout << "A Table of" << totalSeats << " cannot accommodate " << people << " people." << endl;
      }
    }
    else
    {
      cout << "The table is not clean." << endl;
    }
  }

  void haveLunch()
  {
    setCleanliness(false);
    cout<<"Having lunch"<<endl;
  }

  void leaveTable()
  {
    freeSeats = totalSeats;
    seatsOccupied = 0;
    cout<<"Leaving the table"<<endl;
  }

  void cleanTable()
  {
    if(seatsOccupied == 0)
    {
      isClean = true;
      cout<<"The table is clean"<<endl;
    }
    else
    {
      cout<<"The table is not empty"<<endl;
    }
  }

  void setCleanliness(bool isClean) 
  {
    this->isClean = isClean;
  }
  int getTotalSeats()
  {
    return totalSeats;
  }
  int getSeatsOccupied()
  {
    return seatsOccupied;
  }
  int getFreeSeats()
  {
    return freeSeats;
  }
  bool getCleanliness()
  {
    return isClean;
  }


};

void OccupyTable(Table tables[], int size)
{
  int n = -1;
  for(int i=0;i<size;i++)
  {
    if(tables[i].getSeatsOccupied() == 0 && tables[i].getCleanliness() == true && tables[i].getFreeSeats() >= size)
    {
      n = i;
      tables[i].useTable(size);
      break;
    }
    else
    {
      cout<<"Table "<<i+1<<" is occupied"<<endl;
    }
  }
  if(n == -1)
  {
    cout<<"No table is available"<<endl;
  }
}

void EmptyTable(int n, Table tables[])
{
  tables[n].leaveTable();
  tables[n].cleanTable();
  cout<<"Table "<<n+1<<" is empty"<<endl;
}

int main()
{  
  cout << "RAYYAN MERCHANT-23K-0073" << endl;
  
  Table tables[5] = {Table(), Table(8), Table(4), Table(8), Table(4)};
  OccupyTable(tables, 4);
  OccupyTable(tables, 6);
  tables[0].useTable(6);
  tables[0].haveLunch();
  tables[0].cleanTable();
  tables[0].leaveTable();
  EmptyTable(1, tables);
  return 0;
  
}

