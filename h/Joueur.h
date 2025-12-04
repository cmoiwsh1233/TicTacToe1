#ifndef JOUEUR_H
#define JOUEUR_H

#include <string>
using namespace std;

class Joueur {
    private:
        string nom;
        string token;

    public:
        Joueur();
        Joueur(string n);
        string getNom() const;  
        void setNom(const string& value);
        void setToken(const string& value);
        string getToken() const;
};

#endif