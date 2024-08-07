#ifndef _MATRIX_H_
#define _MATRIX_H_ 

#include<iostream>
#include<string>
#include<vector>
#include<stdlib.h>
#include<time.h>
#include<ncurses.h>

#include "def.h"
using namespace std;


class Matrix{
    int size;
    vector<vector<int>> M;
    vector<int> stack;

    public:
        Matrix():size(4),M(4,vector<int>(4,0)),stack(vector<int>(4,0)){
            srand(time(0));
            int row=rand()%4;
            int col=rand()%4;
            M[row][col]=2;
        }
        Matrix(int size):size(size),M(size,vector<int>(size,0)),stack(vector<int>(size,0)){}
        Matrix(vector<vector<int>> save):size(save.size()),M(size,vector<int>(size,0)),stack(vector<int>(size,0)){
            for(int i=0;i<size;i++){
                for(int j=0;j<size;j++){
                    M[i][j]=save[i][j];
                }
            }
        }

        ~Matrix(){}

        bool pushMatrix(int direction);
        bool loadStack (int direction, int index);
        void throwStack(int direction, int index);
        bool Pushforward(vector<int>& stack,int& top);
        vector<int> getRandomPosition(vector<int> freeSpace, int direction);
        void reSet();
        

        void print(){
            cout<<"-----------"<<endl;
            for(int i=0;i<size;i++){
                for(int j=0;j<size;j++){
                    cout<<M[i][j]<<" ";
                }
                cout<<endl;
            }
            cout<<"-----------"<<endl;
        }

        void show(){
            for (int i = 0; i < size; ++i) {
                for (int j = 0; j < size; ++j) {
                    mvprintw(i, j * 4, "%d", M[i][j]); // 假设每个元素最多占4个字符宽度
                }
            }
            refresh(); // 刷新屏幕以显示更新内容
        }
        
};



#endif