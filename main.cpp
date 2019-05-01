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
    cout << listeVide << endl;

    listeVide.append(1);
    listeVide.append(2);
    listeVide.append(3);
    listeVide.append(4);
    listeVide.append(5);

    cout << listeVide << " de taille " << listeVide.size() << endl;

    List<int> listeCopie(listeVide);
    cout << "ListeCopie : " << listeCopie << endl << endl;

    listeCopie.insert(6);
    List<int> listeEgal = listeCopie;

    cout << "ListeVide : " << listeVide << endl;
    cout << "ListeCopie : " << listeCopie << endl;
    cout << "ListeEgal : " << listeEgal << endl;

    listeEgal.append(7);

    cout << "ListeEgal : " << listeEgal << endl;

    List<int> listeAssign;
    cout << "$ListeAssign : " << listeAssign << endl;
    listeAssign.assign(listeEgal);
    cout << "$ListeAssign : " << listeAssign << endl;
    listeAssign.append(8);
    listeAssign.insert(9);

    cout << "ListeAssign : " << listeAssign << endl;
    cout << "ListeEgal : " << listeEgal << endl;


    cout << "Before Remove : " << listeVide << endl;
    listeVide.removeAt(2);
    cout << "After : " << listeVide << endl;

    listeVide.removeAt(0);
    cout << "ListeVide : " << listeVide << endl;
    listeVide.removeAt(listeVide.size() - 1);
    cout << "ListeVide : " << listeVide << endl;

    try {
        listeVide.removeAt(listeVide.size());
    } catch(out_of_range e) {
        cout << e.what() << endl;
    }
    cout << "ListeVide : " << listeVide << endl;


    List<int> l12 = {1, 1, 2, 1, 2, 2, 1, 1, 2};
    cout << l12 << endl;
    cout << "Premier 1 : " << l12.find(1) << "___ premier 2 : " << l12.find(2) << endl;

    l12.remove(1);
    cout << "l12 sans les 1 : " << l12 << endl;

    l12.remove(2);
    cout << "l12 vide : " << l12 << endl;

    l12.remove(0);
    cout << "l12 toujours vide : " << l12 << endl;

    return EXIT_SUCCESS;
}