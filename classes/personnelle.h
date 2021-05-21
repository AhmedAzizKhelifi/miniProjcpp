#ifndef PERSONELLE_H
#define PERSONELLE_H

#include<iostream>
#include"string.h"
#include<ostream>
#include<vector>

using namespace std;
class personnelle
{
 protected:   
    string id;
    string nom;
    string prenom;
    string email;
    string password;
    

public:
  personnelle(string ="",string ="",string ="",string ="",string ="");
  void afficher(); 
  

  //ostream& operator <<(operator&,personnelle&);


  //get set
    string getId(){return id;}
    string getNom(){return nom;}
    string getPrenom(){return prenom;}
    string getEmail(){return email;}
    string getPassword(){return password;}


};
class employer:public personnelle
{
 protected:    
    int num_telf;
    bool estGerant = false;
    float salaire;
public:
     //employer();
     employer(string,int);
     employer(string="",string="",string="",string="",string="",int=0);
     void afficherc();
     void archiver();
     void enregistrer();
     void Modifier();
     string toStr();
     void saisirEmployer(Container<employer>);
     //ostream& operator <<(operator&,employer&);
     int getTel(){return num_telf;}
     void setEstGerant(bool g){estGerant = g;}
     bool getEstGerant(){return estGerant;}
     int getSalaire(){return salaire;}
     void setSalaire(float s){salaire = s;}
};

string employer::toStr(){
    string ch;
    ch = id + " " + nom + " " + prenom + " " + email + " " + password + " " + to_string(num_telf) + " " + to_string(salaire) + " ";
    if(estGerant)
        ch += "1";
    else
        ch += "0";
    return ch;
}

employer::employer(string line, int x){
    std::stringstream ss(line);
    ss >> id >> nom>> prenom>> email >> password >> num_telf >> salaire >> estGerant;
}
void employer::saisirEmployer(Container<employer> employes){
    cout << "ID Employer: e"<< employes.taille();
        /* string id;
    string nom;
    string prenom;
    string email;
    string password; */
    id = "e" + std::to_string(employes.taille());
    cout << "\nSaisir le nom de l'employer: \n>>> ";
    cin >> nom;
    cout << "Saisir le prenom de l'employer: \n>>> ";
    cin >> prenom;   
    cout << "Saisir l'email de l'employer: \n>>> ";
    cin >> email;
    cout << "Saisir le mot de passe:\n>>> ";
    password = readPassword();
    estGerant = false;
    num_telf = readInt("","Saisir le num tel:\n",0);
    salaire = readFloat("","Saisir le salaire:\n",0);
   /*  cin >> id;
    idPersonelle = idP;
   // cout << "Saisir le remise en %: \n>>>";
    if(carteF){
        cout << "Vous obtenez une remise de 5% (Carte fidelite):  \n>>>";
        remise = 5;
    }else
    {remise =_remise;}
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
    prix_total = _prix_total- ((_prix_total*remise)/100); */
}


class client: public personnelle
{
    bool carteFidele = false;
    char printTo = '0';
   public:
    //client();
    
    client(string, int);
    client(string a="",string b="",string c="",string d="",string e=""):personnelle(a,b,c,d,e){}
    Container<client> LoadClients();
    void afficherClient();
    void ModifierClient();
    bool acarteFidele(){return carteFidele;}
    void recevoirCarteFidele(){carteFidele=true; }
    void saisirClient(Container<client>);

    
    void setPrintTo(char c){printTo = c;cout<<"Pt: " << printTo <<endl;}
    /* friend std::ostream& operator << (std::ostream&,client&); //afich */
    string clientToStr();

};

string client::clientToStr(){
    string ch;
    ch = id + " " + nom + " " + prenom + " " + email + " " + password + " ";
    if(carteFidele)
        ch += "1";
    else
        ch += "0";
    return ch;
}
/* 
std::ostream& operator<< (std::ostream& out,client& cli){
    if (cli.printTo='0'){
        cout << "0";
        cli.afficherClient();
    }else
    {
        cout << "1\n";
        out << cli.id << " " << cli.nom << " "<< cli.prenom << " " << cli.email << " " << cli.password;   
    }
    return out;
    
}
 */


void client::saisirClient(Container<client> clients){
    cout << "ID Client: c"<< clients.taille();
        /* string id;
    string nom;
    string prenom;
    string email;
    string password; */
    id = "c" + std::to_string(clients.taille());
    cout << "\nSaisir votre nom: \n>>> ";
    cin >> nom;
    cout << "Saisir votre prenom: \n>>> ";
    cin >> prenom;   
    cout << "Saisir votre email: \n>>> ";
    cin >> email;
    cout << "Saisir votre mot de passe:\n>>> ";
    password = readPassword();
   /*  cin >> id;
    idPersonelle = idP;
   // cout << "Saisir le remise en %: \n>>>";
    if(carteF){
        cout << "Vous obtenez une remise de 5% (Carte fidelite):  \n>>>";
        remise = 5;
    }else
    {remise =_remise;}
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
    prix_total = _prix_total- ((_prix_total*remise)/100); */
}

void client::afficherClient(){
    afficher();
    cout<<"A carte fidelite? "<< carteFidele<<endl;
}
/* Container<client> client::LoadClients(){
    Fichier f("clients");
    Container<std::string> c ;
    c=f.fillContainer();

    Container<client> clients;
    for (unsigned int i = 0; i < c.taille(); i++ ){
        clients.ajouter(client(c[i],1));
    }
    return clients;
} */
client::client(string line, int x){
    std::stringstream ss(line);
    ss >> id >> nom>> prenom>> email >> password >> carteFidele;
}
employer::employer(string a,string b,string c,string d,string e,int i):personnelle(a,b,c,d,e)
{
    num_telf=i;
}
void employer::afficherc()
{
    afficher();
    cout<<"num-telf "<<num_telf<<endl;
}
personnelle::personnelle(string a,string b,string c,string d,string e)
{
    id=a;
    nom=b;
    prenom=c;
    email=d;
    password=e;
}
void personnelle::afficher()
{
  cout<<"id "<<id<<endl;
  cout<<"nom "<<nom<<endl;
  cout<<"prenom "<<prenom<<endl;
  cout<<"email "<<email<<endl;
  cout<<"password "<<password<<endl;
}
/*ostream& operator <<(operator& out,personnelle& c)
{
    out<<c.id<<","<<c.nom<<","<<c.prenon<<","<<c.email<<","<<c.password<<","<<c.num_tel<<"#"<<endl;
    return out;
}
ostream& operator <<(operator& out,employer& c)
{
    out<<c.id<<","<<c.nom<<","<<c.prenon<<","<<c.email<<","<<c.password<<","<<c.num_tel<<"#"<<endl;
    return out;
}*/
void employer::Modifier()
{
    cout<<"---modification----"<<endl;
    cout<<"1-id"<<endl<<"2-nom"<<endl<<"3-prenom"<<endl<<"4-email"<<endl<<"5-password"<<endl<<"6-num_tel"<< "7-salaire"<<endl;  
    int i;
    cin>>i;
    switch (i)
    {
    case 1:cin>>id;break;
    case 2:cin>>nom;break;
    case 3:cin>>prenom;break;
    case 4:cin>>email;break;
    case 5:cin>>password;break;
    case 6: cin>>num_telf;break;
    case 7: cin>>salaire;break;
    default:break; 
    }
}
void client::ModifierClient()
{
    cout<<"---modification_client----"<<endl;
    cout<<"1-id"<<endl<<"2-nom"<<endl<<"3-prenom"<<endl<<"4-email"<<endl<<"5-password"<<endl<<"6-num_tel"<<endl;
    cout<<"7-adresse"<<endl;
    int i;
    cin>>i;
    switch (i)
    {
    case 1:cin>>id;break;
    case 2:cin>>nom;break;
    case 3:cin>>prenom;break;
    case 4:cin>>email;break;
    default:cin>>password;
    
    }
}

#endif