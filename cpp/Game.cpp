#include "Game.h"
#include <iostream>

using namespace std;

Game::Game() : j1(), j2(), grid()
{
    currentPlayer = &j1;
}

void Game::start()
{
    int selectedCol;
    while (true)
    {
        grid.display();
        cout << "Joueur : " << currentPlayer->getNom() << endl;
        cout << "Choisissez une colonne entre 0 et 6" << endl;
        cin >> selectedCol;
        Square square = play(selectedCol);
        vector<array<Square *, 4>> combinaison_list = getCombinaisons(square);
        if (checkWin(combinaison_list))
        {
            grid.display();
            break;
        }
        if (currentPlayer == &j1)
        {
            currentPlayer = &j2;
        }
        else
        {
            currentPlayer = &j1;
        }
    }
    cout << "Vainqueur :" << currentPlayer->getNom() << endl;
    cout << "Partie terminee" << endl;
    system("pause");
}
void Game::selectNames()
{
    cout << "Veuillez saisir le nom du joueur 1 :";
    string name1;
    cin >> name1;
    j1.setNom(name1);
    cout << "Veuillez saisir le token du joueur 1 :";
    string token1;
    cin >> token1;
    j1.setToken(token1);
    cout << "Veillez saisir le nom du joueur 2 :";
    string name2;
    cin >> name2;
    j2.setNom(name2);
    cout << "Veillez saisir le token du joueur 2 :";
    string token2;
    cin >> token2;
    j2.setToken(token2);
}

Square Game::play(int col)
{
    Column &currentCol = grid.getColumn(col);
    for (int i = currentCol.getSquareNumber() - 1; i >= 0; i--)
    {
        if (!currentCol.getSquare(i).hasToken())
        {
            currentCol.getSquare(i).setToken(currentPlayer->getToken());
            return currentCol.getSquare(i);
        }
    }
}

vector<array<Square *, 4>> Game::getCombinaisons(Square square)
{
    vector<array<Square *, 4>> combinaison_list;
    for (int index = -3; index <= 0; index++)
    {
        int i = 0;
        array<Square *, 4> combinaison;
        bool exist = true;
        for (int x = square.getX() + index; x <= square.getX() + index + 3; x++)
        {
            if (grid.columnExist(x) && grid.getColumn(x).squareExist(square.getY()))
            {
                combinaison[i++] = &grid.getColumn(x).getSquare(square.getY());
            }
            else
            {
                exist = false;
                break;
            }
        }
        if (exist)
        {
            combinaison_list.push_back(combinaison);
        }
    }
    for (int index = -3; index <= 0; index++)
    {
        int i = 0;
        array<Square *, 4> combinaison;
        bool exist = true;
        for (int y = square.getY() + index; y <= square.getY() + index + 3; y++)
        {
            if (grid.columnExist(square.getX()) && grid.getColumn(square.getX()).squareExist(y))
            {
                combinaison[i++] = &grid.getColumn(square.getX()).getSquare(y);
            }
            else
            {
                exist = false;
                break;
            }
        }
        if (exist)
        {
            combinaison_list.push_back(combinaison);
        }
    }
    for (int index = -3; index <= 0; index++)
    {
        int i = 0;
        array<Square *, 4> combinaison;
        bool exist = true;
        for (int xy = index; xy <= index + 3; xy++)
        {
            if (grid.columnExist(square.getX() - xy) && grid.getColumn(square.getX() - xy).squareExist(square.getY() - xy))
            {
                combinaison[i++] = &grid.getColumn(square.getX() - xy).getSquare(square.getY() - xy);
            }
            else
            {
                exist = false;
                break;
            }
        }
        if (exist)
        {
            combinaison_list.push_back(combinaison);
        }
    }
    for (int index = -3; index <= 0; index++)
    {
        int i = 0;
        array<Square *, 4> combinaison;
        bool exist = true;
        for (int xy = index; xy <= index + 3; xy++)
        {
            if (grid.columnExist(square.getX() - xy) && grid.getColumn(square.getX() - xy).squareExist(square.getY() + xy))
            {
                combinaison[i++] = &grid.getColumn(square.getX() - xy).getSquare(square.getY() + xy);
            }
            else
            {
                exist = false;
                break;
            }
        }
        if (exist)
        {
            combinaison_list.push_back(combinaison);
        }
    }
    return combinaison_list;
}

void Game::drawCombinaison()
{
    auto combinaison_list = getCombinaisons(grid.getColumn(4).getSquare(4));
    for (int c = 0; c <= combinaison_list.size() - 1; c++)
    {
        for (int s = 0; s <= combinaison_list[c].size() - 1; s++)
        {
            combinaison_list[c][s]->setToken("x");
        }
        grid.display();
        system("pause");
        grid.reset();
    }
}

bool Game::checkWin(vector<array<Square *, 4>> combinaison_list)
{
    for (int index = 0; index < combinaison_list.size(); index++)
    {

        array<Square *, 4> combinaison = combinaison_list[index];
        if (combinaison[0]->getToken().has_value() &&
            combinaison[1]->getToken().has_value() &&
            combinaison[2]->getToken().has_value() &&
            combinaison[3]->getToken().has_value())
        {
            string token = combinaison[0]->getToken().value_ref();
            if (token == combinaison[1]->getToken().value_ref() &&
                token == combinaison[2]->getToken().value_ref() &&
                token == combinaison[3]->getToken().value_ref())
            {
                
                return true;
            }
        }
    }
    return false;
}