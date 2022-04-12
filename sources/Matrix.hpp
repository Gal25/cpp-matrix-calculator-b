
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>

using namespace std;

namespace zich{
    class Matrix{
        private:
            vector<vector<double>> vec;
            int row;
            int col;

        public:
            
            Matrix(vector<double> vec, int row, int col);
            Matrix(int row, int col);
            Matrix operator+(const Matrix& other) const; //return a new mat= mat+mat2, const this
            Matrix& operator+=(int scalar); //change the mat - mat += scalar . change 'this' becouse of that return by refernce
            Matrix& operator+=(const Matrix& other);
            Matrix operator+() const; // Unary Operation, const this
            Matrix operator-(const Matrix& other) const; // return a new mat=mat-mat2 , const this
            Matrix& operator-=(int scalar); //change the mat - mat-=scalar.  change 'this' becouse of that return by refernce
            Matrix operator-() const; // unary operation, const this
            Matrix& operator-=(const Matrix& other);

            double sumOfMatrix() const; // return the sum of all the numbers in the matrix 
            bool operator<(const Matrix& other) const ; //return true is mat1 < mat2
            bool operator>(const Matrix& other) const; //return true if mat1> mat2
            bool operator<=(const Matrix& other) const; //return true if mat1<= mat2
            bool operator>=(const Matrix& other) const; //return true if mat1>= mat2
            bool operator==(const Matrix& other) const; //return true if mat1== mat2
            bool operator!=(const Matrix& other) const; //return true if mat1!=mat2
            
            Matrix& operator++(); // return a mat++ .  change 'this' becouse of that return by refernce
            Matrix& operator--(); //return a mat--.  change 'this' becouse of that return by refernce
            Matrix operator--(int num); //return a --mat.  change 'this' becouse of that return by refernce
            Matrix operator++(int num); // return a ++mat.  change 'this' becouse of that return by refernce
            
            Matrix& operator*=(double scalar); //change the mat *=scalar  .change 'this' becouse of that return by refernce
            Matrix& operator*=(Matrix&  other); //change the mat *=mat . change 'this' becouse of that return by refernce

            friend Matrix operator*(double scalar,Matrix& mat);   //change the mat=scalar*mat 
            friend Matrix operator*(Matrix&  mat, double scalar);   // change the mat = mat*scalar

            Matrix operator*(const Matrix& other) const; // return a mew mat = mat*mat2 , const this

            friend ostream& operator<<(ostream& is,const Matrix &mat);// opreator output <<
            friend istream& operator>>(istream& in, Matrix &mat); // operator input >>

    };

}