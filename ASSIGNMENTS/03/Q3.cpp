#include <iostream>
using namespace std;

template <class T> class Matrix{
protected:
  T **mat;
  int rows, cols;
public:
  Matrix(int r, int c) : rows(r), cols(c){
    mat = new T*[r];
    for(int i = 0; i < r; i++){
      mat[i] = new T[c];
      for(int j = 0; j < c; j++){
        mat[i][j] = T();
      }
    }
  }

  ~Matrix() {
    for (int i = 0; i < rows; i++){
      delete[] mat[i];
    }
      delete[] mat;
  }

  void set(int r, int c, T val){mat[r][c] = val;}
  T get(int r, int c){return mat[r][c];}

  Matrix<T>& operator+(Matrix<T> &other){
    //T result(rows, cols);
    for (int i = 0; i < rows; i++){
      for (int j = 0; j < cols; j++){
        mat[i][j] += other.mat[i][j];
      }
    }
    return *this;
}

  Matrix<T>& operator-(Matrix<T> &other){
    //T result(rows, cols);
    for (int i = 0; i < rows; i++){
      for (int j = 0; j < cols; j++){
        mat[i][j] -= other.mat[i][j];
      }
    }
    return *this;
}

  Matrix<T>& operator * (Matrix<T>& other) {
    T result[rows][cols] = { T() };
    for (int i = 0; i < rows; ++i)
      for (int j = 0; j < cols; ++j)
        for (int k = 0; k < rows; ++k)
          result[i][j] += mat[i][k] * other.mat[k][j];

    for (int i = 0; i < rows; ++i)
      for (int j = 0; j < cols; ++j)
        mat[i][j] = result[i][j];

    return *this;
  }


    virtual void display() const = 0;


};

class IntMatrix : public Matrix<int>{
public:
  IntMatrix(int r, int c) : Matrix<int>(r, c){}
  void display() const override{
    for(int i = 0; i < this->rows; i++){
      for(int j = 0; j < this->cols; j++){
        cout << this->mat[i][j] << "\t";
      }
      cout << endl;
    }
    cout << endl;
  }
};

class DoubleMatrix : public Matrix<double>{
public:
  DoubleMatrix(int r, int c) : Matrix<double>(r, c){}
  void display() const override{
    for(int i = 0; i < this->rows; i++){
      for(int j = 0; j < this->cols; j++){
        cout << this->mat[i][j] << "\t";
      }
      cout << endl;
    }
    cout << endl;
  }
};

int main() {
  IntMatrix m1(2, 2);
  m1.set(0, 0, 1);
  m1.set(0, 1, 6);
  m1.set(1, 0, 5);
  m1.set(1, 1, 3);
  m1.display();

  IntMatrix m2(2, 2);
  m2.set(0, 0, 2);
  m2.set(0, 1, 4);
  m2.set(1, 0, 1);
  m2.set(1, 1, 5);
  m2.display();

  DoubleMatrix m3(2, 2);
  m3.set(0, 0, 1.1);
  m3.set(0, 1, 6.6);
  m3.set(1, 0, 5.5);
  m3.set(1, 1, 3.3);
  m3.display();

  DoubleMatrix m4(2, 2);
  m4.set(0, 0, 2.2);
  m4.set(0, 1, 4.4);
  m4.set(1, 0, 1.1);
  m4.set(1, 1, 5.5);
  m4.display();

  Matrix<int> *m5 = new IntMatrix(2, 2);
  *m5 = m1 + m2;
  cout << "M1 + M2 = " << endl;
  m5->display();

  Matrix<double> *m6 = new DoubleMatrix(2, 2);
  *m6 = m4 - m3;  
  cout << "M4 - M3 = " << endl;
  m6->display();

  Matrix<int> *m7 = new IntMatrix(2, 2);
  *m7 = m1 * m2;
  cout << "M1 * M2 = " << endl;
  m7->display();

  delete m5;
  delete m6;
  delete m7;
}
