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
  void aaa(){cout << "ljjk";}
  //ostream& operator <<(operator&,personnelle&);


  //get set
    string getId(){return id;}
    string getPassword(){return password;}


};
class employer:public personnelle
{
 protected:    
    int num_telf;
public:
     employer();
     employer(string,int);
     employer(string="",string="",string="",string="",string="",int=0);
     void afficherc();
     void archiver();
     void enregistrer();
     void Modifier();
     //ostream& operator <<(operator&,employer&);
};

employer::employer(string line, int x){
    std::stringstream ss(line);
    ss >> id >> nom>> prenom>> email >> password >> num_telf;
}


class client: public personnelle
{
   public:
    client();
    client(string, int);
    client(string a="",string b="",string c="",string d="",string e=""):personnelle(a,b,c,d,e){}
    Container<client> LoadClients();
    void ModifierClient();
};
Container<client> client::LoadClients(){
    Fichier f("clients");
    Container<std::string> c ;
    c=f.fillContainer();

    Container<client> clients;
    for (unsigned int i = 0; i < c.taille(); i++ ){
        clients.ajouter(client(c[i],1));
    }
    return clients;
}
client::client(string line, int x){
    std::stringstream ss(line);
    ss >> id >> nom>> prenom>> email >> password;
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
    cout<<"1-id"<<endl<<"2-nom"<<endl<<"3-prenom"<<endl<<"4-email"<<endl<<"5-password"<<endl<<"6-num_tel"<<endl;  
    int i;
    cin>>i;
    switch (i)
    {
    case 1:cin>>id;break;
    case 2:cin>>nom;break;
    case 3:cin>>prenom;break;
    case 4:cin>>email;break;
    case 5:cin>>password;break;
    default:cin>>num_telf;
    
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