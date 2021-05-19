#include<string>
#include<iostream>
#include<istream>
#include<ostream>
#include<fstream>
using namespace std;
class Facture
{
    string id;
    string code_fac;
    float prix_total ;
    date Date ;
public:
    Facture(){}
    Facture(string,string,float,int,int,int);
    string getid(){return id;}
    void saisir_fact();
    void afficher_fact();

    friend ostream& operator<<(ostream&,Facture&);
    friend istream& operator>>(istream&,Facture&);
};


Facture::Facture(string d,string ch,float p,int j,int m,int a)
{
    id=d;
    code_fac=ch;
    prix_total=p;
    Date.set_jour(j);
    Date.set_mois(m);
    Date.set_annee(a);
}

void Facture::saisir_fact()
{
    cout<<"\n entrez le code de la facture :"<<endl;
    cin>>code_fac;
    cout<<"\n entrez le prix total :"<<endl;
    cin>>prix_total;
    Date.saisir_date();
}

void Facture::afficher_fact()
{
    cout<<"\n le code de la facture est :"<<code_fac<<endl;
    cout<<"\n le prix total est :"<<prix_total<<endl;
    Date.afficher_date();
}
ostream& operator<<(ostream& out,Facture& f)
{
    out<<"\n Affichage de la facture : "<<endl;
    out<<"\n le code de la facture est : "<<f.code_fac<<endl;
    out<<"\n le prix total est : "<<f.prix_total<<endl;
    out<<"\n la date de la facture est : "<<f.Date.jour<<"/"<<f.Date.mois<<"/"<<f.Date.annee<<endl;
    return out;
}
istream& operator>>(istream& in,Facture& f)
{
    cout<<"\n *** saisie de la facture ***"<<endl;
    cout<<"\n entrez le code de la facture :"<<endl;
    in>>f.code_fac;
    cout<<"\n entrez le prix total :"<<endl;
    in>>f.prix_total;
    cout<<"\n entrez la date de la facture :"<<endl;
    in>>f.Date.jour>>f.Date.mois>>f.Date.annee;
    return in;
}