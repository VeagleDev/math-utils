#include <iostream>
#include <cmath>
using namespace std;

void addition()
{
    float nb1;
    float nb2;
    cout << "Entrez le premier nombre : ";
    cin >> nb1;
    cout << "\nEntrez le deuxieme nombre : ";
    cin >> nb2;
    float rep = nb1 + nb2;
    cout << endl << nb1 << " + " << nb2 << " est egal a " << rep;
}

int main()
{
    cout << "\nBienvenue sur le programme Math-Utils | par LC_Nomade de l'equipe MysteriousDev\n\n";
    
    cout << "Quel type de calcul voulez-vous effectuer ?\noperation(op) | arithetique(ar)\ntheoreme(th)  | fonction(f)\nformule(fo)" << endl;

    char rep;
    char rep2;

    cin >> rep;

    if (rep == "op")
    {
        cout << "Quelle operation voulez-vous effectuer ?\naddition(ad)        | soustraction(so)\nmultiplication(mu) | division(di)" << endl;
        cin >> rep2;
        if (rep2 == "ad")
        {
            double addition();
        }
    }
}