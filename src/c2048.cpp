#include "include/matrix.h"
#include <ncurses.h>

int main(){
    Matrix m;
    char input='0';
    bool exit=false;

    initscr();
    cbreak();
    noecho();

    clear();
    cout<<"welcome to the game!!!"<<endl;
    m.show();
    refresh();

    while(true){
        input=getch();
        switch (input){
        case 'q':
            exit=true;
            break;

        case 'r':
            m.reSet();
            break;

        case 'w':
            m.pushMatrix(UP);
            break;

        case 's':
            m.pushMatrix(DOWN);
            break;

        case 'a':
            m.pushMatrix(LEFT);
            break;   

        case 'd':
            m.pushMatrix(RIGHT);
            break;

        default:
            break;
        }

        clear();
        m.show();
        refresh();
        if(exit){
            break;
        }
    }

    endwin();
    cout<<"good bye!!!"<<endl;
}