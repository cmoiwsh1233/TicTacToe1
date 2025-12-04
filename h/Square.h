#ifndef SQUARE_H
#define SQUARE_H

#include <string>
#include "Optional.h"

using namespace std;

class Square {
    private:
        int x;
        int y;
        Optional<string> token;

    public:
        Square();
        Square(int xCoord, int yCoord);
        int getX() const;
        int getY() const;
        void setToken(const string& value);
        Optional<string>& getToken();
        void clearToken();

        void display();
        bool hasToken();

};

#endif