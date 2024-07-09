#include "include/matrix.h"



bool Pushforward(vector<int>& stack,int& top){
    int gndValue=0;
    int gndIndex=-1;
    int size=stack.size();
    bool changed=false;


    for(int i=0;i<size;i++){
        if(stack[i]==0){
            continue;
        }else if(stack[i]==gndValue){
            changed=true;
            gndValue=gndValue<<1;
            stack[gndIndex]=gndValue;
            stack[i]=0;
            gndValue=stack[gndIndex];
        }else{
            gndIndex++;
            if(gndIndex!=i){
                changed=true;
                stack[gndIndex]=stack[i];
                stack[i]=0;
            }
            gndValue=stack[gndIndex];
            
        }
    }
    top=gndIndex;
    return changed;

}