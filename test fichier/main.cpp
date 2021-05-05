#include <iostream>
#include <fstream>

#include "fichiers/fichier.h"
using namespace std;

int main(){
    
    fstream f;
    Fichier file("sv");
    //file.afficher();
    //file.appendStr("no");
    //cout << file;
    //file.afficher();
    //std::string ch;
    char ch[101];

    f.open("test.txt",ios::in|ios::app); //ajouter a la findu contenu actuel
    if(!f.is_open()) exit(-1);
    
    f <<"aaa\nbbb\nccc\nddd";
    //f<< "ll";
    f.seekg(0); //nraj3ou l cursor f awel el fichier texte
/*     while(true){
        f.getline(ch,100,'\n');
        cout << ch<<endl;
        if(f.eof()) break;
    } */
    f.close();
    cout << "-1\n0\n1\n2fin";
}