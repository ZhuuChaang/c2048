#include "include/matrix.h"

bool Matrix::pushMatrix(int direction){
    bool changed=false;
    vector<int> freeSpace(size,0);

    for(int i=0;i<size;i++){
        loadStack(direction,i);
        changed|=Pushforward(stack,freeSpace[i]);
        throwStack(direction,i);
    }

    if(changed){
        vector<int> pos=getRandomPosition(freeSpace,direction);
        this->M[pos[0]][pos[1]]=pos[2];
    }

    return changed;
}

bool Matrix::loadStack(int direction, int index){
    bool ret=true;
    switch (direction){
        case LEFT:
            for(int i=0;i<size;i++){
                stack[i]=M[index][i];
            }
            break;

        case RIGHT:
            for(int i=0;i<size;i++){
                stack[i]=M[index][size-i-1];
            }
            break;

        case UP:
            for(int i=0;i<size;i++){
                stack[i]=M[i][index];
            }
            break;

        case DOWN:
            for(int i=0;i<size;i++){
                stack[i]=M[size-i-1][index];
            }
            break;

        default:
            ret=false;
            break;
    }
    return ret;
}

void Matrix::throwStack(int direction, int index){
    switch (direction){
        case LEFT:
            for(int i=0;i<size;i++){
                M[index][i]=stack[i];
            }
            break;

        case RIGHT:
            for(int i=0;i<size;i++){
                M[index][size-i-1]=stack[i];
            }
            break;

        case UP:
            for(int i=0;i<size;i++){
                M[i][index]=stack[i];
            }
            break;

        case DOWN:
            for(int i=0;i<size;i++){
                M[size-i-1][index]=stack[i];
            }
            break;

        default:
            break;
    }
}

bool Matrix::Pushforward(vector<int>& stack,int& top){
    int gndValue=0;
    int gndIndex=-1;
    int size=stack.size();
    bool changed=false;
    bool newborn=false;


    for(int i=0;i<size;i++){
        if(stack[i]==0){
            continue;
        }else if(stack[i]==gndValue&&newborn==false){
            changed=true;
            gndValue=gndValue<<1;
            stack[gndIndex]=gndValue;
            stack[i]=0;
            gndValue=stack[gndIndex];
            newborn=true;
        }else{
            gndIndex++;
            newborn=false;
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

vector<int> Matrix::getRandomPosition(vector<int> freeSpace, int direction){
    int freeCnt=0;
    int numBorn=0;
    int valBorn=0;
    vector<int> ret(3,0);

    for(int i=0;i<size;i++){
        freeSpace[i]=size-freeSpace[i]-1;
        freeCnt+=freeSpace[i];
    }

    srand(time(0));
    numBorn=rand()%freeCnt+1;
    valBorn=(rand()%10<=7)?2:4;

    for(int i=0;i<size;i++){
        if(numBorn<=freeSpace[i]){
            switch (direction){
            case LEFT:
                ret[0]=i;
                ret[1]=size-numBorn;
                break;

            case RIGHT:
                ret[0]=i;
                ret[1]=numBorn-1;
                break;
            
            case UP:
                ret[0]=size-numBorn;
                ret[1]=i;
                break;
            
            case DOWN:
                ret[0]=numBorn-1;
                ret[1]=i;
            
            default:
                break;
            }
            break;
        }else{
            numBorn-=freeSpace[i];
        }
    }

    ret[2]=valBorn;
    return ret;
}

// test
int main(){
    Matrix t({
        {2,2,2,2},
        {2,0,2,0},
        {2,2,4,4},
        {8,0,2,0}
    });

    // vector<vector<int>> test={
    //                             {0,0,0,0},
    //                             {2,2,0,0},
    //                             {4,2,0,0},
    //                             {4,2,0,2},
    //                             {2,0,2,4},
    //                             {2,2,4,4}
    //                          };

    // bool ret=false;
    // int top=-1;
    // for(int i=0;i<test.size();i++){
    //     ret=t.Pushforward(test[i],top);
    //     for(int j=0;j<test[i].size();j++){
    //         cout<<test[i][j]<<" ";
    //     }
    //     cout<<"top:"<<top<<" ret:"<<ret;
    //     cout<<endl;
    // }


    t.pushMatrix(DOWN);
    t.print();

}

        // {0,0,0,0},
        // {2,0,4,0},
        // {4,0,4,2},
        // {8,4,2,4}