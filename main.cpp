/*
 -----------------------------------------------------------------------------------
 Laboratoire : 03
 Fichier     : main.cpp
 Auteur(s)   : David Jaquet & Christoph Rueff
 Date        : 01.05.2019
 But         : Programme de test de l'implémentation d'une liste personnalisée

 Remarque(s) : - Il n'y a pas de blocs pour tester les méthodes append, insert
                 et l'operateur de flux car elles sont testées tout au long du
                 programme

 -----------------------------------------------------------------------------------
*/

#include <iostream>
#include "List.h"
#include "Boat.h"
#include "Yacht.h"
#include "Sailing.h"

using namespace std;

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

int main() {

    cout << "/*********************** Code Donnee ***********************/" << endl;
    codeDonnee();
    cout << endl;

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

    cout << "/********************** Assign et = **********************/" << endl;
    l3.assign(l1);
    l3.append("five");
    cout << "Test de l3.assign(l1), puis on append \"five\" à l3" << endl
         << R"(l3 doit valoir {"one", "two", "three", "five"} et l1 est inchange)" << endl
         << "l1 : " << l1 << endl
         << "l3 : " << l3 << endl << endl;

    l3 = l2;
    l3.insert("zero");
    cout << "Test de l3 = l2, puis on insert \"zero\" à l3" << endl
         << R"(l3 doit valoir {"zero", "one", "two", "three", "four"} et l2 est inchange)" << endl
         << "l2 : " << l2 << endl
         << "l3 : " << l3 << endl << endl;


    cout << "/********************** Get et [] **********************/" << endl;
    const List<string> lConst = { "ceci", "est", "une", "liste", "constante" };

    cout << "Avec la liste contante lConst : " << lConst << endl
         << "lConst.get(0) : " << lConst.get(0) << endl
         << "lConst.get(2) : " << lConst.get(2) << endl
         << "lConst.get(lConst.size() - 1) : " << lConst.get(lConst.size() - 1) << endl;

    cout << "lConst[0] : " << lConst[0] << endl
         << "lConst[2] : " << lConst[2] << endl
         << "lConst[lConst.size() - 1] : " << lConst[lConst.size() - 1] << endl << endl;

    cout << "Avec la liste l3 : " << l3 << endl
         << "l3.get(0) : " << l3.get(0) << endl
         << "l3.get(2) : " << l3.get(2) << endl
         << "l3.get(l3.size() - 1) : " << l3.get(l3.size() - 1) << endl;

    cout << "l3[0] : " << l3[0] << endl
         << "l3[2] : " << l3[2] << endl
         << "l3[l3.size() - 1] : " << l3[l3.size() - 1] << endl << endl;

    cout << "On teste un get et un operateur [] avec des index trop grand : ";
    bool success1;
    bool success2;
    bool success3;
    bool success4;

    try {
        lConst.get(lConst.size());
        success1 = false;
    } catch(out_of_range& e) {
        success1 = true;
    }

    try {
        lConst[lConst.size()];
        success2 = false;
    } catch(out_of_range& e) {
        success2 = true;
    }

    try {
        l3.get(l3.size());
        success3 = false;
    } catch(out_of_range& e) {
        success3 = true;
    }

    try {
        l3[l3.size()];
        success4 = false;
    } catch(out_of_range& e) {
        success4 = true;
    }

    if (success1 && success2 && success3 && success4) {
        cout << "Test reussi :)" << endl << endl;
    } else {
        cout << "Test echoue :(" << endl << endl;
    }

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

    l1.remove("two");
    l1.remove("six");
    l1.remove("seven");
    l1.remove("seven");
    cout << "On a tout supprime avec remove, on a fait un remove sur la liste vide l1 : " << l1 << endl << endl;


    cout << "/********************** Find **********************/" << endl;
    cout << "l3 : " << l3 << endl
         << "l3.find(\"zero\") : " << l3.find("zero") << endl
         << "l3.find(\"two\") : " << l3.find("two") << endl
         << "l3.find(\"four\") : " << l3.find("four") << endl
         << "l3.find(\"five\") : " << l3.find("five") << endl << endl;

    cout <<"/*********************** Operateur -> ***********************/" << endl;
    List<string> l4 = {"Hello"};
    cout << "List l4 : " << l4 << endl;
    List<string>::Iterator iter = l4.begin();
    iter->append(" World");
    cout << "List l4 après modification : " << l4 << endl << endl;

    cout << "/********************** Bateaux **********************/" << endl;
    Boat *b1 = new Boat("Le INF1", 100);
    Boat *b2 = new Boat("Le Parisien", 150);
    Sailing *s1 = new Sailing("Celui qui prend la mer", 500);
    Sailing *s2 = new Sailing("Celui qui prend l'eau", 1000);
    Yacht *y1 = new Yacht("The place to be", 10000);
    Yacht *y2 = new Yacht("The home", 100000);

    const List<Boat*> boats({b1, b2, s1, s2, y1, y2});
    cout << "Mes bateaux : " << endl;

    // On fait les deux boucles pour tester les opérateur d'incrémentation/décrémentation en suffixe
    for(List<Boat*>::ConstIterator it = boats.begin(); it != boats.end(); it++) {
        cout << **it << endl;
    }

    cout << endl << "Dans l'autre ordre : " << endl;
    for(List<Boat*>::ConstIterator it = boats.end(); it != boats.begin(); it--) {
        cout << **it << endl;
    }

    delete b1;
    delete b2;
    delete s1;
    delete s2;
    delete y1;
    delete y2;

    return EXIT_SUCCESS;
}