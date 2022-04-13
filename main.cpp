#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include "./sources/Matrix.hpp"


using namespace std;
using namespace zich;

int main(){
    Matrix mat1{{1, 1, 1, 1, 1, 1, 1, 1, 1},3,3};
    Matrix mat2({5, 5, 6, 7, 5, 5, 5, 5, 5}, 3, 3);
    Matrix mat3({7, 10, 16, 10, 2, 1, 1, 1, 1}, 3, 3);

    cout<< "please choose a operator form the list:"<< endl;
    cout << "[-unary , +unary, +, -, * , *scalar , ++, -- , *=scalar, +=scalar, -=scalar, -=matrix, +=matrix]"<<endl;
    string str;
    cin >> str;

    if(str == "-unary"){
        cout << endl << "- unary of matrix 1: " << endl << (-mat1)<< endl;
        cout << endl << "- unary of matrix 2: " << endl << (-mat2)<< endl;
        cout << endl << "- unary of matrix 3: " << endl << (-mat3)<< endl;
    }

    if(str == "+unary"){
        cout << endl << "+ unary of matrix 1: " << endl << (mat1)<< endl;
        cout << endl << "+ unary of matrix 2: " << endl << (mat2)<< endl;
        cout << endl << "+ unary of matrix 3: " << endl << (mat3)<< endl;
    }

    if(str == "+"){
        cout << endl << "matrix 1 + matrix 2 : " << endl << (mat1+mat2)<< endl;
    }

    if(str == "-"){
        cout << endl << "matrix 2 - matrix 1 : " << endl << (mat2-mat1)<< endl;
    }

    if(str == "*"){
        cout << endl << "matrix2 * matrix 1 : " << endl << (mat2*mat1)<< endl;
        cout << endl << "matrix3 * matrix 1 : " << endl << (mat3*mat1)<< endl;
    }

    if(str == "*scalar"){
        int scalar;
        cout << "please choose the scalar: "<< endl;
        cin >> scalar;
        cout << endl << "matrix1 * scalar : " << endl << (mat1*scalar)<< endl;
        cout << endl << "matrix2 * scalar : " << endl << (mat2*scalar)<< endl;
        cout << endl << "matrix3 * scalar : " << endl << (mat3*scalar)<< endl;
    }

    if(str == "++"){
        cout << endl << "matrix++ : " << endl << (++mat1)<< endl;
        cout << endl << "matrix3++ : " << endl << (++mat3)<< endl;
    }

    
    if(str == "--"){
        cout << endl << "--matrix : " << endl << (--mat1)<< endl;
        cout << endl << "--matrix3 : " << endl << (--mat3)<< endl;
    }

     if(str == "*=scalar"){
        int scalar;
        cout << "please choose the scalar: "<< endl;
        cin >> scalar;
        cout << endl << "matrix1 *= scalar : " << endl << (mat1*scalar)<< endl;
        cout << endl << "matrix2 *= scalar : " << endl << (mat2*scalar)<< endl;
        cout << endl << "matrix3 *= scalar : " << endl << (mat3*scalar)<< endl;
    }

     if(str == "+=scalar"){
        int scalar;
        cout << "please choose the scalar: "<< endl;
        cin >> scalar;
        cout << endl << "matrix1 += scalar : " << endl << (mat1+=scalar)<< endl;
        cout << endl << "matrix2 += scalar : " << endl << (mat2+=scalar)<< endl;
        cout << endl << "matrix3 += scalar : " << endl << (mat3+=scalar)<< endl;
    }

    if(str == "-=scalar"){
        int scalar;
        cout << "please choose the scalar: "<< endl;
        cin >> scalar;
        cout << endl << "matrix1 -= scalar : " << endl << (mat1-=scalar)<< endl;
        cout << endl << "matrix2 -= scalar : " << endl << (mat2-=scalar)<< endl;
        cout << endl << "matrix3 -= scalar : " << endl << (mat3-=scalar)<< endl;
    }

    if(str == "-=matrix"){
        string strMat;
        cout << "please choose the matrix from [matrix1 , matrix2, matrix3]: "<< endl;
        cin >> strMat;
        if(strMat == "matrix1"){
            cout << endl << "matrix1 -= matrix2 : " << endl << (mat1-=mat2)<< endl;
            cout << endl << "matrix1 -= matrix3 : " << endl << (mat1-=mat3)<< endl;
        }
        if(strMat == "matrix2"){
            cout << endl << "matrix2 -= matrix1 : " << endl << (mat2-=mat1)<< endl;
            cout << endl << "matrix2 -= matrix3 : " << endl << (mat2-=mat3)<< endl;
        }
        
        if(strMat == "matrix3"){
            cout << endl << "matrix3 -= matrix1 : " << endl << (mat3-=mat2)<< endl;
            cout << endl << "matrix3 -= matrix2 : " << endl << (mat3-=mat1)<< endl;
        }
    }

     if(str == "+=matrix"){
        string strMat;
        cout << "please choose the matrix from [matrix1 , matrix2, matrix3]: "<< endl;
        cin >> strMat;
        if(strMat == "matrix1"){
            cout << endl << "matrix1 += matrix2 : " << endl << (mat1+=mat2)<< endl;
            cout << endl << "matrix1 += matrix3 : " << endl << (mat1+=mat3)<< endl;
        }
        if(strMat == "matrix2"){
            cout << endl << "matrix2 += matrix1 : " << endl << (mat2+=mat1)<< endl;
            cout << endl << "matrix2 += matrix3 : " << endl << (mat2+=mat3)<< endl;
        }
        
        if(strMat == "matrix3"){
            cout << endl << "matrix3 += matrix1 : " << endl << (mat3+=mat2)<< endl;
            cout << endl << "matrix3 += matrix2 : " << endl << (mat3+=mat1)<< endl;
        }
    }

    return 0;
}