#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

//Operation

typedef vector<int> tab;

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


void soustraction()
{

    float nb1;
    float nb2;
    cout << "Entrez le premier nombre : ";
    cin >> nb1;
    cout << "\nEntrez le deuxieme nombre : ";
    cin >> nb2;
    float rep = nb1 - nb2;
    cout << endl << nb1 << " - " << nb2 << " est egal a " << rep;
}



void multiplication()
{

    float nb1;
    float nb2;
    cout << "Entrez le premier nombre : ";
    cin >> nb1;
    cout << "\nEntrez le deuxieme nombre : ";
    cin >> nb2;
    float rep = nb1 * nb2;
    cout << endl << nb1 << " X " << nb2 << " est egal a " << rep;
}



void division()
{
    float nb1;
    float nb2;
    cout << "Entrez le premier nombre : ";
    cin >> nb1;
    cout << "\nEntrez le deuxieme nombre : ";
    cin >> nb2;
    float rep = nb1 / nb2;
    cout << endl << nb1 << " / " << nb2 << " est egal a " << rep;
}



//Arithmetique

tab diviseurs(int * nombre = nullptr)
{
    tab diviseurs;
    int nb,rep;

    if(nombre == nullptr)
    {
        cout<<"Entrez le nombre : ";
        cin>>nb;
        cout << endl << "Les diviseurs de " << nb << " sont ";

        for( rep = 1; rep <= nb; ++rep)
        {
            if(nb%rep==0)
            {
                cout << rep << ";";
                diviseurs.push_back(rep);
            }

        }
    }
    else
    {
        nb = *nombre;
        for( rep = 1; rep <= nb; ++rep)
            if(nb%rep==0)
                diviseurs.push_back(rep);
    }
    return diviseurs;
}

void isPrimary()
{
    int nombre;
    cout << "Ce nombre est il un nombre premier : ";
    cin >> nombre;
    const tab div = diviseurs(&nombre);
    if(div.empty() or div.size() != 2)
    {
        cout << endl << nombre << " n'est pas premier";
    }
    else
    {
        cout << endl << nombre << " est premier";
    }


}

void findPrimary()
{
    int cb;
    cout << "Jusqu'a combien voulez-vous trouver des nombres premiers : ";
    cin >> cb;
    if(cb > 5000)
    {
        string in;
        cout << "Etes-vous surs de calculer autant de nombres (va prendre beaucoup de place) ( O / n ) : ";
        cin >> in;
        if(in != "O" and in != "o")
        {
            cout << endl << "Annulation";
            return;
        }
    }
    int compteur = 0;
    cout << "\nVoici une liste de nombres premiers : \n";
    while (compteur < cb)
    {
        if(diviseurs(&compteur).size() == 2)
        {
            cout << compteur << " ";
        }
        compteur++;
    }
}

void commonDivisors()
{
    // demander deux int
    int nb1 , nb2;
    cout << "Entrez le premier nombre\n";
    cin >> nb1;
    cout << "Entrez le deuxième nombre\n";
    cin >> nb2;

    tab div1 = diviseurs(&nb1);
    tab div2 = diviseurs(&nb2);

    tab commonDiv;

    for(int i : div1)
    {
        for(int j : div2)
        {
            if(i == j)
            {
                commonDiv.push_back(i);
            }
        }
    }
    if(commonDiv.size() == 1)
    {
        cout << nb1 << " et " << nb2 << " sont des nombres premiers mutuels";
    }
    else
    {
        cout << "Les diviseurs communs de " << nb1 << " et " << nb2 << " sont : ";
        for(int k : commonDiv)
        {
            cout << k << " ; ";
        }
    }

}




int main()
{
commonDivisors();
return 0;
}