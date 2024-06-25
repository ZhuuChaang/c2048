#ifndef _NODE_H_
#define _NODE_H_

#include<vector>

#include"def.h"

using namespace std;




class Node{
    int value=0;
    vector<Node*> neighbers=vector<Node*>(4);

    public:
        Node(){}
        Node(int n):value(n){
            int a=UP;
        }
        
};


#endif