#ifndef FACTURE_H
#define FACTURE_H

#include<string>
#include<vector>
#include<iostream>
#include<istream>
#include<ostream>
#include<fstream>

#include"date.h"

using namespace std;
class Facture
{
    string id;
    string idPersonelle;
    Container<string> idProduits;
    float remise;
    float prix_total;
    date Date ;
    char printTo = '0'; //si =0 print to screen else to file
public:
    Facture(){}
    Facture(string,string);
    Facture(string ,string ,float ,int ,int ,int, Container<Produit>);
    string getid(){return id;}
    void saisir_fact(Container<Produit>);
    int nombreDeProduit(){return idProduits.taille();}

    void setPrintTo(char c) {printTo = c;}
    string getId(){return id;}

    friend ostream& operator<<(ostream&,Facture&);
    bool operator==(std::string); // == bel id 
    //friend istream& operator>>(istream&,Facture&);
};

Facture::Facture(string line1,string line2){
    // Facture fact("id idpers 6 100 31 12 2000", "10 12 13 14 15");
   /* 
    (line 1)
    // id idpers 6 100 31 12 2000
    string id;
    string idPersonelle;
    float remise;
    float prix_total;
    date Date ;
    -----------
    (line2)
    // 10 12 13 14 15 
    Container<string> idProduits;
     */
    int j,m,a;
    stringstream ss0(line1);
    ss0 >> id >> idPersonelle >> remise >> prix_total >> j >> m >> a;
    Date.set_jour(j);
    Date.set_mois(m);
    Date.set_annee(a);
    
    stringstream ss(line2);
    stringstream s1(line2);
    string x;
    string tmp;
    while(s1 >> tmp) {      
        ss >> x;     
        idProduits.ajouter(x);
    }      

}
void Facture::saisir_fact(Container<Produit> produits){
    cout << "Saisir l'ID du facture: \n>>>";
    cin >> id;
    cout << "Saisir l'ID du personne: \n>>>";
    cin >> idPersonelle;
   // cout << "Saisir le remise en %: \n>>>";
    remise = readFloat("path","Saisir le remise en %:",0);
    Date.saisir_date();
    int r;
    bool validation = false;
    //liste des produits :
    do
    {
        validation = false;
        cout << "Saisir l'ID du produit: \n>>>";
        string idProduit;
        cin >> idProduit;
        if(produits.idintExist(idProduit))
            idProduits.ajouter(idProduit);
        else
            cout << "\nID invalide.\n";
        if(idProduits.taille()>0) 
            r = ouiNon("Ajouter un autre produit?","path",0,1);
        if(r==1) validation=true;
        if(idProduits.taille()==0) validation = true;
    } while (validation);
    float _prix_total = 0.0;
    for (unsigned int i = 0; i < idProduits.taille(); i++){
        Produit p;
        p = produits.getByintId(idProduits[i]);
        _prix_total= _prix_total + p.getPrix();
    }
    prix_total = _prix_total- ((_prix_total*remise)/100);


}


Facture::Facture(string _id,string _idPersonelle,float _remise,int j,int m,int a, Container<Produit> produits)
{
    id = _id;
    idPersonelle = _idPersonelle;
    remise = _remise;
    //prix_total = _prix_total;
    Date.set_jour(j);
    Date.set_mois(m);
    Date.set_annee(a);
    int r;
    bool validation = false;
    //liste des produits :
    do
    {
        validation = false;
        cout << "Saisir l'ID du produit: \n>>>";
        string idProduit;
        cin >> idProduit;
        if(produits.idintExist(idProduit))
            idProduits.ajouter(idProduit);
        else
            cout << "\nID invalide.\n";
        if(idProduits.taille()>0) 
            r = ouiNon("Ajouter un autre produit?","path",0,1);
        if(r==1) validation=true;
        if(idProduits.taille()==0) validation = true;
    } while (validation);
    float _prix_total = 0.0;
    for (unsigned int i = 0; i < idProduits.taille(); i++){
        Produit p;
        p = produits.getByintId(idProduits[i]);
        _prix_total= _prix_total + p.getPrix();
    }
    prix_total = _prix_total- ((_prix_total*remise)/100);
}

ostream& operator<<(ostream& out,Facture& f)
{
    if(f.printTo=='0') { //to screen
        //out<<"\n Affichage de la facture : "<<endl;
        out<<"ID du facture: "<<f.id<<endl;
        out<<"\tID Personne: "<<f.idPersonelle<<endl;
        out<<"\tDate: "<<f.Date.jour<<"/"<<f.Date.mois<<"/"<<f.Date.annee<<endl;
        out<<"\tId de(s) " << f.nombreDeProduit() << " produits: "<<f.idProduits;
        out << "\tRemise: " << f.remise << "%\n";
        out << "\tPrix apres remise: " << f.prix_total <<endl;
        out << "\tPrix sans remise:" << f.prix_total / (1 - (f.remise/100));
    }
    else{
        // Facture fact("id idpers 6 100 31 12 2000", "10 12 13 14 15");
        out << f.id << " " << f.idPersonelle << " " << f.remise << " ";
        out << f.Date.get_jour()<< " "  << f.Date.get_mois()<< " " << f.Date.get_annee() << endl;
        for (unsigned int i = 0; i < f.idProduits.taille(); i++){
            out << f.idProduits[i] << " ";
        }
        out <<endl;
    }
    return out;
} 


bool Facture::operator==(std::string _id){ //id
    if (id==_id)
        return true;
    else
        return false;
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

#endif