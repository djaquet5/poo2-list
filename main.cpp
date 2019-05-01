#include <iostream>
#include "List.h"

using namespace std;

// TODO: les for ont été commentés tant que les opérateurs ne sont pas surchargés
void codeDonnee() {
    List<string> l;

    l.append("un");
    l.append("deux");
    l.append("trois");

//    for(List<string>::Iterator it = l.begin(); it != l.end(); ++it){
//        cout << *it << " ";
//    }
//    cout << endl;
    // Affichage: un deux trois

    const List<int> c = { 42, 3, 14 };
//    for(List<int>::ConstIterator it = c.end(); it != c.begin(); --it){
//        cout << *it << " ";
//    }
//    cout << endl;
    // Affichage: 14 3 42
}

int main() {
//    codeDonnee();
    List<int> listeVide;

    listeVide.append(1);
    listeVide.append(2);
    listeVide.append(3);
    listeVide.append(4);
    listeVide.append(5);

    cout << listeVide.size() << endl;

    List<int> listeCopie(listeVide);
    cout << listeCopie.size() << endl;

    listeCopie.insert(6);
    List<int> listeEgal = listeCopie;

    cout << listeCopie.size() << endl;
    cout << listeEgal.size() << endl;

    listeEgal.append(7);

    cout << listeEgal.size() << endl;

    List<int> listeAssign;
    listeAssign.assign(listeEgal);
    listeAssign.append(8);

    cout << listeAssign.size() << endl;
    cout << listeEgal.size() << endl;

    return EXIT_SUCCESS;
}