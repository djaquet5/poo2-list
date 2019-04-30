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




    return EXIT_SUCCESS;
}