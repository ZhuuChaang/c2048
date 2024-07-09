#include "../src/include/matrix.h"

int main(){
    vector<vector<int>> test={
                                {0,0,0,0},
                                {2,2,0,0},
                                {4,2,0,0},
                                {4,2,0,2}
                             };

    bool ret=false;
    int top=-1;
    for(int i=0;i<test.size();i++){
        ret=Pushforward(test[i],top);
        for(int j=0;j<test[i].size();j++){
            cout<<test[i][j]<<" ";
        }
        cout<<"top:"<<top<<" ret:"<<ret;
        cout<<endl;
    }
    
}