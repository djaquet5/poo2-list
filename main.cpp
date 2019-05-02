/*
 -----------------------------------------------------------------------------------
 Laboratoire : 03
 Fichier     : main.cpp
 Auteur(s)   : David Jaquet & Christoph Rueff
 Date        : 01.05.2019
 But         : Programme de test de l'implémentation d'une liste personnalisée

 Remarque(s) : - Il n'y a pas de blocs pour tester les méthodes append et insert
                 car elles sont testées tout au long du programme

 -----------------------------------------------------------------------------------
*/

#include <iostream>
#include "List.h"
#include "Boat.h"
#include "Yacht.h"
#include "Sailing.h"

using namespace std;

// TODO: les for ont été commentés tant que les opérateurs ne sont pas surchargés
void codeDonnee() {
    List<string> l;

    l.append("un");
    l.append("deux");
    l.append("trois");

    for(List<string>::Iterator it = l.begin(); it != l.end(); ++it){
        cout << *it << " ";
    }
    cout << endl;
    // Affichage: un deux trois

    const List<int> c = { 42, 3, 14 };
    for(List<int>::ConstIterator it = c.end(); it != c.begin(); --it){
        cout << *it << " ";
    }
    cout << endl;
    // Affichage: 14 3 42
}

void testListe() {
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
}

int main() {
//    codeDonnee();
//    testListe();

    cout << "/********************** Constructeurs **********************/" << endl;
    List<string> l1;
    cout << "Constructeur vide avec l1 : " << l1 << endl << endl;

    // On profite de tester append() et insert()
    // l1 doit valoir { "one", "two", "three" } après ces 3 instructions
    l1.append("two");
    l1.insert("one");
    l1.append("three");
    cout << "Ajout d'elements a l1 : " << l1 << endl << endl;

    List<string> l2(l1);
    cout << "Constructeur de copie l2 : " << l2 << endl << endl;

    l2.append("four");
    cout << "l2 a ete modifie, l1 doit maintenant etre different de l2 : " << endl
         << "l1 : " << l1 << endl
         << "l2 : " << l2 << endl << endl;

    List<string> l3 = { "eins", "zwei", "drei" };
    cout << "Constructeurs par liste d'initialiseurs l3 : " << l3 << endl << endl;

//    cout << "/********************** Assign et = **********************/" << endl;
//    l3.assign(l1);
//    l3.append("five");
//    cout << "Test de l3.assign(l1), puis on append \"five\" à l3" << endl
//         << "l3 doit valoir {\"one\", \"two\", \"three\", \"five\"} et l1 est inchange" << endl
//         << "l1 : " << l1 << endl
//         << "l3 : " << l3 << endl << endl;
//
//    l3 = l2;
//    l3.insert("zero");
//    cout << "Test de l3 = l2, puis on insert \"zero\" à l3" << endl
//         << "l3 doit valoir {\"zero\", \"one\", \"two\", \"three\", \"four\"} et l2 est inchange" << endl
//         << "l2 : " << l2 << endl
//         << "l3 : " << l3 << endl << endl;

    // TODO:
    cout << "/********************** Get et [] **********************/" << endl;
    List<string> lConst = { "ceci", "est", "une", "liste", "constante" };

    cout << endl << endl;

    cout << "/********************** Size **********************/" << endl;
    cout << "l1 : " << l1 << endl
         << "l1 a 3 element ? " << boolalpha << (l1.size() == 3) << endl << endl;

    cout << "/********************** Remove et RemoveAt **********************/" << endl;
    l1.insert("one");
    l1.append("one");
    l1.append("six");
    l1.append("one");
    l1.append("seven");
    l1.append("one");

    cout << "l1 : " << l1 << endl;
    l1.removeAt(0);
    cout << "Apres le removeAt(0) : " << l1 << endl;

    l1.removeAt(2);
    cout << "Apres le removeAt(2) : " << l1 << endl;

    l1.removeAt(l1.size() - 1);
    cout << "Apres le removeAt(l1.size() - 1) : " << l1 << endl;

    cout << "On passe index qui est hors de la liste : ";
    try {
        l1.removeAt(l1.size());
        cout << "Test rate :(" << endl << endl;
    } catch(out_of_range& e) {
        cout << e.what() << endl << endl;
    }

    l1.remove("one");
    cout << "On remove(\"one\") de l1 : " << l1 << endl << endl;



    return EXIT_SUCCESS;
}