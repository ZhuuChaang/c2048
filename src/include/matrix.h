#ifndef _MATRIX_H_
#define _MATRIX_H_ 

#include<iostream>
#include<string>
#include<vector>
#include "def.h"
using namespace std;


class Matrix{
    int size;
    vector<vector<int>> M;

    public:
        Matrix():size(4),M(4,vector<int>(4,0)){}
        Matrix(int size):size(size),M(size,vector<int>(size,0)){}

        ~Matrix(){}

};

bool Pushforward(vector<int>& stack,int& top);

#endif