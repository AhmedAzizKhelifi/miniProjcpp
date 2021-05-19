#include<string>
#include<iostream>
#include<istream>
#include<ostream>
#include<fstream>
using namespace std;

class Commande
{
   std::string ID_comm;
   int quantite;
   date t;
   public:
       Commande(string,int,date);
       void saisir_comm();
       void archiver();
       void afficher_comm();
       date getdate(){return t;}
       int getquantite(){return quantite;}
       friend ostream& operator<<(ostream&,Commande&);
       friend istream& operator>>(istream&,Commande&);
};
Commande::Commande(string ch,int q,date d)
{
    ID_comm=ch;
    quantite=q;
    t=d;
}

void Commande::saisir_comm()
{
    cout<<"\n entrez l'identifiant de produit :"<<endl;
    cin>>ID_comm;
    cout<<"\n entrez la prix :"<<endl;
    cin>>quantite;
    t.saisir_date();
}

void Commande::afficher_comm()
{
    cout<<"\n l'identifiant de la commande est :"<<ID_comm<<endl;
    cout<<"\n la prix est :"<<quantite<<endl;
    cout<<t;
}
void Commande::archiver()
{
    
}
ostream& operator<<(ostream& out,Commande& c)
{
    out<<"\n *** Affichage de la commande ***"<<endl;
    out<<"\n l'identifiant de la commande est :"<<c.ID_comm<<endl;
    out<<"\n la quantite est :"<<c.quantite<<endl;
    return out;
}

istream& operator>>(istream& in,Commande& c)
{
    cout<<"\n *** Saisie de la commande ***"<<endl;
    cout<<"\n entrez l'identifiant de la commande :"<<endl;
    in>>c.ID_comm;
    cout<<"\n entrez la quantite :"<<endl;
    in>>c.quantite;
    return in;
}