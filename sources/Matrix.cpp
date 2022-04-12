
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include "Matrix.hpp"


using namespace std;
namespace zich{


    /*
    In this constructor the matrix is constructed based on columns and rows.
    During the function we put in the column vector of the matrix zeros
    and the same vector is put into the main vector of the matrix.
    */
    Matrix:: Matrix(int row, int col){
        this->col = col;
        this->row = row;
        double size = 0;

        
        for (size_t i = 0; i< row ; i++){
            vector<double> m;
            for(size_t j = 0; j< col; j++){
                m.push_back(size);
            }
            this->vec.push_back(m);
        }

    }
    
    /*
    In this constructor the matrix is constructed based on columns,rows and vector.
    During the function we put in the column vector of the matrix (that we defined) the constructor vector
    and the same vector put into the main vector of the matrix.
    Finally the matrix will be constructed of a column vector within a vector rows.
    */
    Matrix::Matrix(vector<double> vec, int row, int col){
        if ( row < 0 || col < 0 ){
            throw invalid_argument( "the size of the matrix must be positive");
        }
        if ( row* col != vec.size()){
            throw invalid_argument( "11the size of the matrix must be positive");
        }

        size_t size = 0;
        this->col = col;
        this->row = row;

        for (size_t i = 0; i< row ; i++){
            vector<double> m;
            m.reserve(vec.size());
            for(size_t j = 0; j< col; j++){
                m.push_back(vec[size++]);
            }
            this->vec.push_back(m);
        }
    }

    /*
    In this operator we connect 2 matrices. Go through the whole matrix and connect the variables in similar places.
    If the matrices are not the same size we will throw an error.
    */
    Matrix Matrix::operator+(const Matrix& other) const{
        if (this->col != other.col || this->row != other.row){
            throw invalid_argument("The size of 2 matrix must be the same") ;
        }

        Matrix mat_copy = Matrix(*(this));
        for (size_t i=0; i<this->row; i++){
            for(size_t j=0; j<this->col; j++){
                mat_copy.vec[i][j] = this->vec[i][j]+other.vec[i][j];
            }
        }
        return mat_copy;    
    }

    /*
    In this operator we will add a variable into the matrix values.
    we want in this operator to override the existing matrix in the class
    and change it according to the connection with the variable.
    Therefore the function will return the class variable *this after the change.
    */
    Matrix& Matrix::operator+=(int scalar){
        for (size_t i=0; i<this->row; i++){
            for(size_t j=0; j<this->col; j++){
                this->vec[i][j]=this->vec[i][j]+ scalar;
            }
        }
        return *this;    
    }

    /*
    In this operator we will connect 2 matrices.
    Unlike operator+ here we want to override the existing matrix in the class
    and change it according to the connection with the second matrix.
    Therefore the function will return the class variable *this after the change.
    */
    Matrix& Matrix::operator+=(const Matrix& other){
         if (this->col != other.col || this->row != other.row){
            throw invalid_argument ("The size of 2 matrix must be the same");
        }
        for (size_t i=0; i<this->row; i++){
            for(size_t j=0; j<this->col; j++){
                this->vec[i][j]= this->vec[i][j]+ other.vec[i][j];
            }
        }
        return *this;  
    }

    /*
    This operator is + unary. We do not change the matrix at all and therefore return the original matrix.
    */
    Matrix Matrix::operator+() const{
        return *(this);
    }

    /*
    This operator is missing between 2 matrices.
    If the matrices are not equal then return an error.
    */
    Matrix Matrix::operator-(const Matrix& other) const{
         if (this->col != other.col || this->row != other.row){
            throw invalid_argument ("The size of 2 matrix must be the same");
        }
        
       Matrix mat_copy= Matrix(*(this));
        for (size_t i=0; i<this->row; i++){
            for(size_t j=0; j<this->col; j++){
                mat_copy.vec[i][j] = this->vec[i][j]-other.vec[i][j];
            }
        }
        return mat_copy;  
    }

    /*
    This operator is missing the matrix values of the variable.
    we want in this operator to override the existing matrix in the class
    and change it according to the connection with the variable.
    Therefore the function will return the class variable *this after the change.
    */
    Matrix& Matrix::operator-=(int scalar){
        for (size_t i=0; i<this->row; i++){
            for(size_t j=0; j<this->col; j++){
                this->vec[i][j] = this->vec[i][j]- scalar;
            }
        }
        return *this;  
    }

    /*
    This operator is missing between 2 matrices.
    we want in this operator to override the existing matrix in the class
    and change it according to the connection with the variable.
    Therefore the function will return the class variable *this after the change.
    */
    Matrix& Matrix::operator-=(const Matrix& other){
        if (this->col != other.col || this->row != other.row){
            throw invalid_argument("The size of 2 matrix must be the same");
        }
        for (size_t i=0; i<this->row; i++){
            for(size_t j=0; j<this->col; j++){
                this->vec[i][j] = this->vec[i][j]- other.vec[i][j];
            }
        }
        return *this;  
    }

    /*
    This operator is -unary.
    We replace the matrix values with values smaller than zero.
    Go through the whole matrix and multiply each value by (-1).
    */
    Matrix Matrix::operator-() const{  
        Matrix mat_copy = Matrix(*(this));
        for (size_t i=0; i<this->row; i++){
            for(size_t j=0; j<this->col; j++){
                mat_copy.vec[i][j] = this->vec[i][j]*(-1);
            }
        }
        return mat_copy;  
    }

    /*
    In this function the sum of the organ values in the matrix is calculated.
    */
    double Matrix::sumOfMatrix()const{
        double ans= 0;
        for (size_t i=0; i<this->row; i++){
            for(size_t j=0; j<this->col; j++){
               ans += this->vec[i][j]; 
            }
        }
        return ans;
    }

    /*
    In this function we compare 2 matrices, 
    if the sum of the other matrix values is greater than the sum of the matrix members of the class then we return true,otherwise false.
    */
    bool Matrix::operator<(const Matrix& other) const{
         if (this->col != other.col || this->row != other.row){
            throw "The size of 2 matrix must be the same";
        }
        
        double ans= 0;
        for (size_t i=0; i<this->row; i++){
            for(size_t j=0; j<this->col; j++){
               ans = ans+ other.vec[i][j]; 
            }
        }
        double sumMat = sumOfMatrix();

        return (sumMat < ans);
  
    }

    /*
    In this function we compare 2 matrices,
    if the sum of the other matrix values is less than the sum of the matrix members of the class then we return true, otherwise false.
    */
    bool Matrix::operator>(const Matrix& other) const{
         if (this->col != other.col || this->row != other.row){
            throw "The size of 2 matrix must be the same";
        }
        
        double ans= 0;
        for (size_t i=0; i<row; i++){
            for(size_t j=0; j<col; j++){
               ans = ans+ other.vec[i][j]; 
            }
        }
        double sumMat = sumOfMatrix();

        return (sumMat > ans);
    }

    /*
    In this function we compare 2 matrices,
     if the sum of the other matrix values is greater than or equal to the sum of the matrix members of the class then we return true,
    otherwise false.
    */
    bool Matrix::operator<=(const Matrix& other)const{
         if (this->col != other.col || this->row != other.row){
            throw "The size of 2 matrix must be the same";
        }
        
        double ans= 0;
        for (size_t i=0; i<row; i++){
            for(size_t j=0; j<col; j++){
               ans = ans+ other.vec[i][j]; 
            }
        }
        double sumMat = sumOfMatrix();

        return (sumMat <= ans);
    }

    /*
    In this function we compare 2 matrices,
    if the sum of the OTHER matrix values is less than or equal to the sum of the matrix members of the class then we return true,
    otherwise false.
    */
    bool Matrix::operator>=(const Matrix& other)const{
         if (this->col != other.col || this->row != other.row){
            throw "The size of 2 matrix must be the same";
        }
        
        double ans= 0;
        for (size_t i=0; i<row; i++){
            for(size_t j=0; j<col; j++){
               ans = ans+ other.vec[i][j]; 
            }
        }
        double sumMat = sumOfMatrix();

        return (sumMat >= ans);
    }

    /*
    In this function we will compare 2 matrices,
    if all the matrix values of the class are equal to the values of the other matrix.
    If there is an unequal organ we will return a false, if all the organs are equal we will return a true.
    */
    bool Matrix::operator==(const Matrix& other)const{
         if (this->col != other.col || this->row != other.row){
            throw "The size of 2 matrix must be the same";
        }
        
        for (size_t i=0; i<this->row; i++){ 
            for(size_t j=0; j<this->col; j++){
                if(this->vec[i][j] != other.vec[i][j]){
                    return false;
                }
            }
        }
        return true;
    }
    
    /*
    In this function we will compare 2 matrices,
    if all the matrix values of the class are not equal to the values of the OTHER matrix,
    therefore we will return the negation of the operator ==.
    */
    bool Matrix::operator!=(const Matrix& other)const{
         if (this->col != other.col || this->row != other.row){
            throw "The size of 2 matrix must be the same";
         }
        return !(operator==(other));
    }

    /*
    In this operator we will advance the matrix values by 1 each time.
    */
    Matrix& Matrix::operator++(){
        for (size_t i=0; i<this->row; i++){
            for(size_t j=0; j<this->col; j++){
                this->vec[i][j]+=1;
            }
        }
        return *this;  
    }
    
    /*
    This operator is missing the matrix values at 1 each time.
    */
    Matrix& Matrix::operator--(){
        for (size_t i=0; i<this->row; i++){
            for(size_t j=0; j<this->col; j++){
                this->vec[i][j]-=1;
            }
        }
        return *this;
    }

    /*
    In this operator we first save the matrix and then subtract from the matrix of the class in 1.
    */
    Matrix Matrix::operator--(int num){
        Matrix mat_rev = Matrix(*this);
        for (size_t i=0; i<this->row; i++){
            for(size_t j=0; j<this->col; j++){
                this->vec[i][j]-=1;
            }
        }
        return mat_rev;
    }
    
    
    /*
    In this operator we will first save the matrix and then advance the matrix of the class by 1.
    */
    Matrix Matrix::operator++(int num){
        Matrix mat_rev = Matrix(*this);
        for (size_t i=0; i<this->row; i++){
            for(size_t j=0; j<this->col; j++){
                this->vec[i][j]+=1;
            }
        }
        return mat_rev;
    }

    /*
    In this operator the matrix values are multiplied by a variable.
    we want in this operator to override the existing matrix in the class
    and change it according to the connection with the variable.
    Therefore the function will return the class variable *this after the change.
    */       
    Matrix& Matrix::operator*=(double scalar){
        for (size_t i=0; i<this->row; i++){
            for(size_t j=0; j<this->col; j++){
                this->vec[i][j]*=scalar;
            }
        }
        return *this;
    }

    /*
    In this operator the matrix values are multiplied by the other matrix values.
    we want in this operator to override the existing matrix in the class
    and change it according to the connection with the variable.
    Therefore the function will return the class variable *this after the change.
    */
    Matrix& Matrix::operator*=(Matrix& other){
        if (this->col != other.row){
                throw invalid_argument("The size of 2 matrix must be the same");
          }

        Matrix mat_copy = Matrix::operator*(other);
        this->col = mat_copy.col;
        this->row = mat_copy.row;
        this->vec = mat_copy.vec;
        return *(this);
    }

    /*
    In this operator the matrix values are multiplied by the other matrix values.
    The result matrix consists of the matrix columns on the left and the rows of the matrix on the right,
    so we will go through 3 loops on the rows of one matrix and then on the rows and columns of the other matrix and double between the members.
    */
    Matrix Matrix::operator*(const Matrix& other) const{
        if (this->col != other.row){
            throw "The size of 2 matrix must be the same";
        }
        Matrix mat_copy = Matrix(this->row, other.col);
        for (size_t i = 0; i < this->row; i++){
            for(size_t j=0; j< other.col; j++){
                mat_copy.vec[i][j] = 0;
                for(size_t k=0; k < other.row; k++){
                    mat_copy.vec[i][j] += this->vec[i][k] * other.vec[k][j];
                }
            }
        }
        return mat_copy;
    }

    Matrix operator*(double scalar, Matrix &mat){
        Matrix mat_copy= Matrix((mat));;
        for (size_t i=0; i<mat.row; i++){
            for(size_t j=0; j<mat.col; j++){
                mat_copy.vec[i][j] = mat.vec[i][j] * scalar;
            }
        }
        return mat_copy; 
    }


    Matrix operator*(Matrix&  mat, double scalar){
        Matrix mat_copy= Matrix((mat));;
        for (size_t i=0; i<mat.row; i++){
            for(size_t j=0; j<mat.col; j++){
                mat_copy.vec[i][j] = mat.vec[i][j] * scalar;
            }
        }
        return mat_copy; 
    }

    istream& operator>>(istream& in,  Matrix &mat){ // operator input >>       
        int row =0;
        int col= 0;
        string  getMat;
        vector<double> vec;
        
        // until we have a line in the input - until the char ','
        while(getline(in, getMat, ',') ){
                string matString;
                for(size_t i = 0; i < getMat.size(); i++){
                    if(getMat[i] != '[' && getMat[i] != ' ' && getMat[i] != ',' && getMat[i] != ']' && getMat[i] != '\n'){
                        matString = getMat[i];  
                        double d = stod(matString);
                        vec.push_back(d);
                    }
                    else if(in.get() == '\n' || getMat[i] == '\n'){
                        break;
                    }
                }
            row++;
        }
         
        // check the column number 
        for (size_t i = 0; i < getMat.size(); i++){
            if( getMat[i] != '[' && getMat[i] != ']' && getMat[i] != ' ' && getMat[i] != '\n'){
                col++;
            }
        }
        mat = Matrix(vec, row, col);
        return in;
    
    }
    
    ostream& operator<<(ostream& is,const Matrix &mat){ // opreator output <<
        for (size_t i=0; i< mat.row; i++){
            is << "[";
            for(size_t j=0; j< mat.col; j++){
                is << mat.vec[i][j];
                if ( j != mat.col-1){
                    is << " ";
                }          
            }
            is << "]";

            //So that in the end there will be no line drop
            if(i != mat.row -1){
                is << "\n";
            }
         
        }
        return is;
    }  


}