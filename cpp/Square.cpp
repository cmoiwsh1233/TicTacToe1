#include "Square.h"
#include <iostream>

using namespace std;

Square::Square() : x(0), y (0), token() {}

Square::Square(int xCoord, int yCoord) : x(xCoord), y (yCoord), token() {}

int Square::getX() const { return x; }
int Square::getY() const { return y; }
Optional<string>& Square::getToken() {
    return token;
     }

void Square::setToken(const string& value) {
    token = value;
}

void Square::clearToken() {
    token.reset();
}

void Square::display() {
    cout << "[";
    if(token.has_value()){
        cout << token.value_ref();
    }else{
        cout << " ";
    }
    cout << "]";
}

bool Square::hasToken(){
    return token.has_value();
}