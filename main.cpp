#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <string>
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
        return commonDiv;
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



bool checkArguments(int argc, char **argv, int * action)
{
    if(argc == 2)
    {
        string arg = argv[1];
        if(arg.size() == 2 && isdigit(arg[0]) && isdigit(arg[1]))
        {
            *action = stoi(arg);
            return true;
        }
    }
    return false;
}

int getActionNumber()
{
    // On créé les variables importantes dès le début
    int numChoix;
    int numRubrique;
    string rep;

    // On créé des dictionnaires qui associent le numéro de la rubrique/option avec leur description
    map<string, string> rubriques;
    map<string, string> options;


    // On associe pour chaque rubrique
    rubriques["1"] = "Operations";
    rubriques["2"] = "Arithetiques";
    rubriques["3"] = "Theoremes";
    rubriques["4"] = "Fonctions";
    rubriques["5"] = "Formules";

    cout << "Bienvenue sur math-utils,\n\nVeuillez choisir une rubrique parmi celles ci : \n\n";


    // Pour chaque paires de numéro-nom
    for(map<string, string>::iterator it = rubriques.begin(); it != rubriques.end(); ++it)
    {
        string out;
        out += "[";
        out += it->first;
        out += "] "; // On écrit le nombre entre crochets
        out += it->second; // Puis on marque la définition
        out += "\n";
        cout << out;
    }
    cout << "\nRubrique n.";
    getline(cin, rep); // On récupère son numérp de manière sécurisée

    // Si c'est vide/trop grand, on annule
    if(rep.size() > 2 || rep.empty())
    {
        cerr << "La rubrique choisie n'existe pas !\nVeuillez reessayer : \n\n";
        return getActionNumber();
    }

    // On cherche dans le dictionnaire, la paire qui correspond au numéro qu'il a entré
    map<string, string>::iterator it = rubriques.find(rep);


    if(it == rubriques.end()) // Si on trouve pas
    {
        if(rep.size() == 2) // Si il a tapé le numéro d'action, on va direct à la fin
        {
            return stoi(rep);
        }
        cerr << "La rubrique choisie n'existe pas !\nVeuillez reessayer : \n\n"; // Sinon on le renvoie au début
        return getActionNumber();
    }
    cout << " --> " << it->second << "\n"; // On affiche ce qu'il a choisi

    // Maintenant qu'on a notre rubrique, on peut lui demander quelle fonction il veut
    // Donc on commence par faire un menu si il veut revenir au début

    options["0"] = "Retour aux rubriques";

    numRubrique = stoi(it->first); // On écrit le numéro de la rubrique mais en int et pas en string car switch ne fonctionne que avec les int
    switch(numRubrique)
    { // En fonction de la rubrique, on lui propose les choix adéquats
        case 1:
            options["1"] = "Addition";
            options["2"] = "Soustracteur";
            options["3"] = "Multiplicateur";
            options["4"] = "Diviseur";
            break;
        case 2:
            options["1"] = "Trouver diviseurs";
            options["2"] = "Est premier ?";
            options["3"] = "Chercheur de nombres premiers";
            options["4"] = "Chercheur de diviseurs communs";
            options["5"] = "Reducteur de fractions";
            break;
        case 3:
            options["1"] = "Pythagore";
            options["2"] = "Thales";
            options["3"] = "Triangles semblables";
            break;
        case 4:
            options["1"] = "Sinus";
            options["2"] = "Cosinus";
            options["3"] = "Tangante";
            break;
        case 5:
            options["1"] = "Vitesse";
            options["2"] = "Puissance electrique";
            options["3"] = "Resistance";
            break;
        default:
            if(numRubrique <= 10)
            {
                return numRubrique;
                break;
            }
            else
            {
                cerr << "La rubrique choisie n'existe pas !\nVeuillez reessayer : \n\n";
                return getActionNumber();
            }
            break;
    }
    demandeOption:
    cout << "\n\nVeuillez choisir une option parmis les suivantes : \n";
    // On affiche les rubriques pareil mais cette fois pour les options
    for(map<string, string>::iterator it = options.begin() ; it != options.end() ; ++it)
    {
        string out;
        out += "[";
        out += it->first;
        out += "] ";
        out += it->second;
        out += "\n";
        cout << out;
    }
    // Renvoie "Hourra" sur Discord si tu lis vraiment les commentaires
    cout << "\nOperation n.";
    rep.clear();
    getline(cin, rep); // On récupère sa réponse

    // Encore tout pareil
    if(rep.size() > 2 || rep.empty())
    {
        cerr << "Le choix est incorrect !\nVeuillez reessayer : \n\n";
        goto demandeOption;
    }
    it = options.find(rep);
    if(it == options.end())
    {
        cerr << "Le choix est incorrect !\nVeuillez reessayer : \n\n";
        goto demandeOption;
    }
    if(it->first == "0") // Si il a mis 0 (retour) on le remet au début
    {
        return getActionNumber();
    }
    cout << " --> " << it->second << "\n";
    numChoix = stoi(it->first);
    return numRubrique*10 + numChoix; // On calcule le numéro d'action en mettant rubrique et choix ( on fait *10 pour passer en dizaine )
}

void executeAction(int action)
{
    cout << "\n\nL'action a effectuer est la n." << action << "\n";
    switch(action) // En fonction du numéro d'action, on fait une fonction en partiulier.
    {
        case 11: // Adder
            addition();
            break;
        case 12: // Substracter
            soustraction();
            break;
        case 13: // Multiplicator
            multiplication();
            break;
        case 14: // Divisor
            division();
            break;
        case 21: // Divisor finder
            diviseurs();
            break;
        case 22: // Is primary
            isPrimary();
            break;
        case 23: // Primary numbers finder
            findPrimary();
            break;
        case 24: // Common divisors
            commonDivisors();
            break;
        case 25: // Fraction reduction
            reduceFraction();
            break;
        case 31: // Pythagore
            cerr << "[ERREUR] : Fonction pas encore assignee !!\n\n";
            break;
        case 32: // Thales
            cerr << "[ERREUR] : Fonction pas encore assignee !!\n\n";
            break;
        case 33: // Similar triangles
            cerr << "[ERREUR] : Fonction pas encore assignee !!\n\n";
            break;
        case 41: // Sinus
            cerr << "[ERREUR] : Fonction pas encore assignee !!\n\n";
            break;
        case 42: // Cosinus
            cerr << "[ERREUR] : Fonction pas encore assignee !!\n\n";
            break;
        case 43: // Tangent
            cerr << "[ERREUR] : Fonction pas encore assignee !!\n\n";
            break;
        case 51: // Speed
            cerr << "[ERREUR] : Fonction pas encore assignee !!\n\n";
            break;
        case 52: // Power
            cerr << "[ERREUR] : Fonction pas encore assignee !!\n\n";
            break;
        case 53: // Resistance
            cerr << "[ERREUR] : Fonction pas encore assignee !!\n\n";
            break;
        default:
            cerr << "[ERREUR] : L'action est invalide !!\n\n";
            break;
    }
}

void menu(int argc, char **argv)
{
    int action;
    if(!checkArguments(argc, argv, &action))
    {
        action = getActionNumber();
    }
    executeAction(action);
}

int main(int argc, char **argv)
{
    menu(argc, argv);
}
