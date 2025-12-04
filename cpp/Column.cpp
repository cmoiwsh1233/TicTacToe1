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

void Column::display() {
    cout << "|";
    for(int i = square_list.size() -1; i>= 0; --i) {
        square_list[i].display();
    }
    cout << "|" << endl;
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