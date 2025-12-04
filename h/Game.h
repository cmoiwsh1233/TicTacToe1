#ifndef GAME_H
#define GAME_H

#include "Joueur.h"
#include "Grid.h"
#include <array>
#include <vector>

class Game
{
    private:
        Joueur j1;
        Joueur j2;
        Joueur* currentPlayer;
        Grid grid;
        int moveCount = 0;
         
    public:
        Game();
        void start();
        void selectNames();
        Square play(int col, int row);
        vector<array<Square*, 3>> getCombinaisons(Square square);
        bool checkWin(vector<array<Square*, 3>> combinaison_list);
        void drawCombinaison();
};

#endif