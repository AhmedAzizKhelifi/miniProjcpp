#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>


#include"classes/decoration.cpp"
#include"classes/fichier.h" // + #include"classes/container.h"

//#include "classes/produit.h"

using namespace std;
int main(){
   






    /*
    Fichier f("test1");
    
    Produit p("1 label 50");
    string ch;
    cout << p;

    fstream file;
    file.open("saves\\test.txt",std::ios::in|std::ios::app);
    file << ch << std::endl;
    file.close();
    file.seekg(0);
        while(true){
        file.getline(ch,100,'\n');
        //std::cout << ch<<std::endl;
        if (ch=="") std::cout << "fergh";
        cout << ch << std::endl;

        if(file.eof()) break;
    }
*/
  
/*
    
    vector<Produit> v;
    Produit p("khobz",50);
    p.setPrintTo('0');
    Container<Produit> c;
    c.ajouter(p);


    Fichier f("test");
 
    f.appendProduit(c[0]);

    std::fstream& h = f.getFile();



    
    h.seekg(0);
    char ch[101];
    while(true){
        cout << "'";
        h.getline(ch,100,'\n');
        cout << ch << "'\n";
        if(!isdigit(ch[0])) break;
        Produit p2(ch);
        c.ajouter(p2);
        if(h.eof()) break;
    }
    h.close();
    
    
    cout << c;

    
/*     cout << c;
    Fichier f("test");
    f.appendStr("saha frr");
    cout << f;
    f.reset();
    cout<< "apres:" << f;
    f.appendStr(p);
    cout << f; */
/* 
*/
/* vector<Produit> v;
     while (true)
    {
        menuPrincipale(v);

    }  */
     
}