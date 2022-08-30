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

tab commonDivisors(int * nombre1 = nullptr, int * nombre2 = nullptr)
{
    // demander deux int
    if(nombre1 != nullptr && nombre2 != nullptr)
    {
        tab div1 = diviseurs(nombre1);
        tab div2 = diviseurs(nombre2);

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
        return commonDiv;
    }
    else
    {
        int nb1 , nb2;
        cout << "Entrez le premier nombre : ";
        cin >> nb1;
        cout << "\nEntrez le deuxieme nombre : ";
        cin >> nb2;

        cout << endl;

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


}

string slice(string chaine, int beg, int end)
{
    string sliced;
    if(beg > end || beg > chaine.size() || end > chaine.size())
    {
        return "-1";
    }
    for(int i = beg; i < end; i++)
    {
        sliced += chaine[i];
    }
    return sliced;
}

int max(tab nums)
{
    int max = 1;
    for(int i : nums)
    {
        if(i > max)
        {
            max = i;
        }
    }
    return max;
}

void reduceFraction()
{
    // demander une chaine avec / pour la fraction
    string in;
    cout << "Entrez la fraction : ";
    cin >> in;
    cout << endl;
    // trouver le /
    int index = in.find('/');
    if(index == in.npos)
    {
        cout << "Pas de signe / trouve";
        return;
    }
    // prendre ce qu'il y a avant et mettre en nombre avec stoi
    int numerateur = stoi(slice(in, 0, index));
    int denominateur = stoi(slice(in, index+1, in.size()));

    // trouver les diviseurs communs aux deux
    tab commons = commonDivisors(&numerateur, &denominateur);
    // les diviser par leurs pgcd
    int pgcd = max(commons);
    int ppNumerateur = numerateur / pgcd;
    int ppDenominateur = denominateur /pgcd;
    // renvoyer la fraction
    cout << "La fraction reduite de " << numerateur << "/" << denominateur << " est " << ppNumerateur << "/" << ppDenominateur;
    return;
}




int main()
{
reduceFraction();
return 0;
}