#ifndef GRID_H
#define GRID_H

#include <array>
#include "Column.h"

class Grid {
    private:
        array<Column,7> column_list;
    public:
        Grid();
        void display();
        Column& getColumn(int xCoord);
        void reset();
        bool columnExist(int xCoord);
};

#endif