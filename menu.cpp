#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;
int main(int argc, char **argv) {

    int action;
    int numChoix;
    int numRubrique;
    // vector -> map(map(number, name), vector
    map<string, string> rubriques;
    map<string, string> options;
    rubriques["1"] = "Operations";
    rubriques["2"] = "Arithetiques";
    rubriques["3"] = "Theoremes";
    rubriques["4"] = "Fonctions";
    rubriques["5"] = "Formules";
    cout << "Bienvenue sur math-utils,\nVeuillez choisir une rubrique parmi celles ci : \n";
    for(map<string, string>::iterator it = rubriques.begin(); it != rubriques.end(); ++it)
    {
        string out;
        out += "[";
        out += it->first;
        out += "] ";
        out += it->second;
        out += "\n";
        cout << out;
    }
    cout << "Rubrique n.";
    string rep;
    getline(cin, rep);
    if(rep.size() > 2 || rep.empty())
    {
        cerr << "La rubrique choisie n'existe pas !\nVeuillez reessayer : \n\n";
        return main(argc, argv);
    }
    map<string, string>::iterator it = rubriques.find(rep);
    if(it == rubriques.end())
    {
        if(rep.size() == 2)
        {
            action = stoi(rep);
            goto actions;
        }
        cerr << "La rubrique choisie n'existe pas !\nVeuillez reessayer : \n\n";
        return main(argc, argv);
    }
    cout << " --> " << it->second << "\n";

    options["0"] = "Retour aux rubriques";
    numRubrique = stoi(it->first);
    switch(numRubrique)
    {
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
                action = numRubrique;
                goto actions;
                break;
            }
            else
            {
                cerr << "La rubrique choisie n'existe pas !\nVeuillez reessayer : \n\n";
                return main(argc, argv);
            }
            break;
    }
    demandeOption:
    cout << "\n\n\nVeuillez choisir une option parmis les suivantes : \n";
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
    cout << "Operation n.";
    rep.clear();
    getline(cin, rep);
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
    if(it->first == "0")
    {
        return main(argc, argv);
    }
    cout << " --> " << it->second << "\n";
    numChoix = stoi(it->first);
    action = numRubrique*10 + numChoix;

    actions:

    cout << "L'action a effectuer est la n." << action;

    switch(action)
    {
        case 11: // Adder
            break;
        case 12: // Substracter
            break;
        case 13: // Multiplicator
            break;
        case 14: // Divisor
            break;
        case 21: // Divisor finder
            break;
        case 22: // Is primary
            break;
        case 23: // Primary numbers finder
            break;
        case 24: // Common divisors
            break;
        case 25: // Fraction reduction
            break;
        case 31: // Pythagore
            break;
        case 32: // Thales
            break;
        case 33: // Similar triangles
            break;
        case 41: // Sinus
            break;
        case 42: // Cosinus
            break;
        case 43: // Tangent
            break;
        case 51: // Speed
            break;
        case 52: // Power
            break;
        case 53: // Resistance
            break;
        default:
            cerr << "L'action est invalide !!";
            break;
    }
    return 0;
}
