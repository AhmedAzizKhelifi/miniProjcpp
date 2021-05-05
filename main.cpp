#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>


#include"classes/decoration.cpp"
#include"classes/fichier.h"
#include"classes/container.h"
//#include "classes/produit.h"

using namespace std;
int main(){
    vector<Produit> v;
    Produit p("khobz",50);
    p.setPrintTo('0');
    Container<Produit> c;
    c.ajouter(p);

    Fichier f("test");
    f.reset();
    
    f.appendProduit(c[0]);
     
    
    cout <<"f:"<< f;

    cout <<"c:" <<c;
    std::fstream& h = f.getFile();
    h.seekg(0);
   
   
     char ch[101];
    while(true){
        cout << "'";
        h.getline(ch,100,'\n');
        cout << ch << "'\n";
        cout << ch[0]<<"\n";
        
        if(!isdigit(ch[0])) break;
        Produit pp(ch);
        cout << pp;
      
        if(h.eof()) break;
    }
    h.close();
    

    
/*     cout << c;
    Fichier f("test");
    f.appendStr("saha frr");
    cout << f;
    f.reset();
    cout<< "apres:" << f;
    f.appendStr(p);
    cout << f; */
/* 
     while (true)
    {
        menuPrincipale(v);

    } */
     
}