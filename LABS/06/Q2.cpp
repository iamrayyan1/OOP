#include <iostream>
#include <string>
using namespace std;

class Image
{
private:
  int width;
  int height;
  int* data;

public:
  Image(int width, int height) : width(width), height(height)
  {
    data = new int[width * height];
  }
  Image(const Image& other) : width(other.width), height(other.height) {
    data = new int[width * height];
    for (int i = 0; i < width * height; i++)
    {
      data[i] = other.data[i];
    }
  }

  ~Image()
  {
    delete[] data;
  }

  void display()
  {
    for (int i = 0; i < height; i++)
    {
      for (int j = 0; j < width; j++)
      {
        cout << data[i * width + j] << " ";
      }
      cout << endl;
    }
  }

  void updateData(int* originalData)
  {
    for (int i = 0; i < width * height; i++)
    {
      if (originalData[i] == 0 && originalData[i] < 0)
      {
        data[i] = rand() % 256;
      }
      else
      {
        data[i] = originalData[i];
      }
    }
  }

};

int main()
{
  int originalData[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  Image image(2, 3);
  image.updateData(originalData);
  image.display();
}
