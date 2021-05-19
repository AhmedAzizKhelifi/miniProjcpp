#include<string>
#include<vector>
#include<iostream>
#include<istream>
#include<ostream>
#include<fstream>
using namespace std;
class Facture
{
    string id;
    string idPersonelle;
    Container<string> idProduits;
    float remise;
    float prix_total;
    date Date ;
public:
    Facture(){}
    Facture(string ,string ,float ,int ,int ,int, Container<Produit>);
    string getid(){return id;}
    void saisir_fact();
    void afficher_fact();

    friend ostream& operator<<(ostream&,Facture&);
    friend istream& operator>>(istream&,Facture&);
};


Facture::Facture(string _id,string _idPersonelle,float _remise,int j,int m,int a, Container<Produit> produits)
{
    id = _id;
    idPersonelle = _idPersonelle;
    remise = _remise;
    //prix_total = _prix_total;
    Date.set_jour(j);
    Date.set_mois(m);
    Date.set_annee(a);

    //liste des produits :
    do
    {
        ouiNon("text","path",0);
        cout << "Saisir l'ID du produit: \n\n>>>";
        string idProduit;
        cin >> idProduit;
        if(produits.idExist(idProduit))
            cout << "add";
        else
            cout << "no produit";
    } while (true);
    


}
/* 
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
} */