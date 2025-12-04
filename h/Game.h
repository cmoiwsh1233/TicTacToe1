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
         
    public:
        Game();
        void start();
        void selectNames();
        Square play(int col);
        vector<array<Square*, 4>> getCombinaisons(Square square);
        bool checkWin(vector<array<Square*, 4>> combinaison_list);
        void drawCombinaison();
};

#endif