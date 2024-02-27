#include<iostream>
#include <cmath>
#include <string> 
using namespace std;

class ChessPiece
{
private:
    string name;
    string color;
    char symbol;

public:
    ChessPiece()
    {
        name = "Pawn";
        color = "White";
        symbol = 'P';
    }

  ChessPiece(string n, string c, char s)
      {
          name = n;
          color = c;
          symbol = s;
      }

      string getName()
      {
          return name;
      }
      string getColor()
      {
          return color;
      }
      char getSymbol()
      {
          return symbol;
      }
      void setName(string n)
      {
          name = n;
      }
      void setColor(string c)
      {
          color = c;
      }
      void setSymbol(char s)
      {
          symbol = s;
      }
  };

  class ChessBoard
  {
  private:
      ChessPiece board[8][8];

  public:
      ChessBoard()
      {
          for (int i = 0; i < 8; i++)
          {
              for (int j = 0; j < 8; j++)
              {
                  board[i][j] = ChessPiece();
              }
          }
          board[0][0] = ChessPiece("Rook", "White", 'R');
          board[0][1] = ChessPiece("Knight", "White", 'N');
          board[0][2] = ChessPiece("Bishop", "White", 'B');
          board[0][3] = ChessPiece("Queen", "White", 'Q');
          board[0][4] = ChessPiece("King", "White", 'K');
          board[0][5] = ChessPiece("Bishop", "White", 'B');
          board[0][6] = ChessPiece("Knight", "White", 'N');
          board[0][7] = ChessPiece("Rook", "White", 'R');
          board[1][0] = ChessPiece("Pawn", "White", 'P');
          board[1][1] = ChessPiece("Pawn", "White", 'P');
          board[1][2] = ChessPiece("Pawn", "White", 'P');
          board[1][3] = ChessPiece("Pawn", "White", 'P');
          board[1][4] = ChessPiece("Pawn", "White", 'P');
          board[1][5] = ChessPiece("Pawn", "White", 'P');
          board[1][6] = ChessPiece("Pawn", "White", 'P');
          board[1][7] = ChessPiece("Pawn", "White", 'P');
          board[7][0] = ChessPiece("Rook", "Black", 'r');
          board[7][1] = ChessPiece("Knight", "Black", 'n');
          board[7][2] = ChessPiece("Bishop", "Black", 'b');
          board[7][3] = ChessPiece("Queen", "Black", 'q');
          board[7][4] = ChessPiece("King", "Black", 'k');
          board[7][5] = ChessPiece("Bishop", "Black", 'b');
          board[7][6] = ChessPiece("Knight", "Black", 'n');
          board[7][7] = ChessPiece("Rook", "Black", 'r');
          board[6][0] = ChessPiece("Pawn", "Black", 'p');
          board[6][1] = ChessPiece("Pawn", "Black", 'p');
          board[6][2] = ChessPiece("Pawn", "Black", 'p');
          board[6][3] = ChessPiece("Pawn", "Black", 'p');
          board[6][4] = ChessPiece("Pawn", "Black", 'p');
          board[6][5] = ChessPiece("Pawn", "Black", 'p');
          board[6][6] = ChessPiece("Pawn", "Black", 'p');
          board[6][7] = ChessPiece("Pawn", "Black", 'p');
      }

      void display() 
      {
          cout << "  a b c d e f g h" << endl;
          for (int i = 0; i < 8; i++)
          {
              cout << 8 - i << " ";
              for (int j = 0; j < 8; j++)
              {
                  cout << board[i][j].getSymbol() << " ";
              }
              cout << 8 - i << endl;
          }
          cout << "  a b c d e f g h" << endl;
      }

bool movePiece(string source, string destination)  //TOOK HELP FROM AI
{
    
    int srcCol = source[0] - 'a';
    int srcRow = '8' - source[1];
    int destCol = destination[0] - 'a';
    int destRow = '8' - destination[1];

    if (srcRow < 0 || srcRow > 7 || srcCol < 0 || srcCol > 7 ||
        destRow < 0 || destRow > 7 || destCol < 0 || destCol > 7)
    {
        cout << "Invalid source or destination position." << endl;
        return false;
    }


    ChessPiece sourcePiece = board[srcRow][srcCol];
    ChessPiece destPiece = board[destRow][destCol];


    if (sourcePiece.getName() == "None")
    {
        cout << "No piece at the source position." << endl;
        return false;
    }
    if (destPiece.getName() != "None" && sourcePiece.getColor() == destPiece.getColor())
    {
        cout << "Cannot capture your own piece." << endl;
        return false;
    }
    char pieceSymbol = sourcePiece.getSymbol();
    int rowDiff = abs(destRow - srcRow);
    int colDiff = abs(destCol - srcCol);

    switch (pieceSymbol)
    {
      case 'P'
      {
        if (srcCol == destCol && destPiece.getName() == "None")
        {
          if ((srcRow == 6 && destRow == 4 && rowDiff == 2) ||
          (srcRow - destRow == 1 && rowDiff == 1))
          {
            return true;
          }
        }
        else if (colDiff == 1 && rowDiff == 1 &&
        destPiece.getName() != "None" && destPiece.getColor() != sourcePiece.getColor())
        {
          return true;
        }
            break;
        }
        case 'N':
        {
          if ((rowDiff == 2 && colDiff == 1) || (rowDiff == 1 && colDiff == 2))
          {
             return true;
          }
          break;
        }
    }

    cout << "Invalid move for the selected piece." << endl;
    return false;
}

  };

  int main()
  {
      cout << "RAYYAN MERCHANT-23K-0073" << endl;

      ChessBoard board;
      board.display();
      string source, destination;
      while (true)
      {
        cout << "Enter source position ";
        cin >> source;
        cout << "Enter destination position ";
        cin >> destination;
        if (board.movePiece(source, destination))
        {
          board.display();
        }
        else
        {
          
        }
      }

      return 0;
  }
