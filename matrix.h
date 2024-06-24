#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Matrix{
    vector<vector<int>> MatData;
    int size;

    public:
        Matrix(){
            size=4;
            
        }

        Matrix(int size):size(size){

        }


};