#include <iostream>
#include <cmath>
using namespace std;

//Operation

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

void diviseurs()
{
int nb,rep;
cout<<"Entrez le nombre : ";
cin>>nb;
cout << endl << "Les diviseurs de " << nb << " sont ";
 
for(rep=1;rep<=sqrt(nb);++rep)
{
if(nb%rep==0)
cout << " ; " << rep;
}
}




int main()
{
diviseurs()
return 0;
}