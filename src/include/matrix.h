#ifndef _MATRIX_H_
#define _MATRIX_H_ 

#include<iostream>
#include<string>
#include<vector>
using namespace std;


class Matrix{
    int size;

    public:
        Matrix(){
            size=4;
            
        }

        Matrix(int size):size(size){

        }


};

#endif