#include "Column.h"
#include <iostream>

using namespace std;

Column::Column() : x(0) {} 

Column::Column(int xCoord) : x(xCoord) {
    for(int y = 0; y<3; y++) {
        square_list[y] = Square(xCoord,y);
    }
}

int Column::getX() const { return x; }

int y = 0;

void Column::display() {
    
    cout << y;
    cout << "|";
    for(int i = square_list.size() -1; i>= 0; --i) {
        square_list[i].display();
    }
    cout << "|" << endl;
    y++;
    if (y > 2) {
        y = 0;
    }
}

Square& Column::getSquare(int yCoord) {
    return square_list[yCoord];
};

int Column::getSquareNumber(){
    return square_list.size();
}

bool Column::squareExist(int yCoord){
    return yCoord >= 0 && yCoord < square_list.size();
}