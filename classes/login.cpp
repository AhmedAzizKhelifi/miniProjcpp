#ifndef LOGIN_CPP
#define LOGIN_CPP

#include "personnelle.h"
#include "LoadData.cpp"
#include"historique.h"
#include "settings.h"
#include "fichier.h"
#include <conio.h>
#include "statistique.cpp"
#include "menuEmployer.cpp"




int menu1Choix(std::string path = "___"){
    int r;
    bool validation = true;
    std::cin.exceptions(std::istream::failbit);
    do {
        try {
            //system("cls");
            header(path);
            std::cout << "1. Connexion\n2. Inscription\n\n";
            std::cout << ">>>";
            std::cin >> r;
            system("cls");
            validation = r>0 && r<3; // menu tests
        }   
        catch (const std::exception& e) {
            validation = false;
            //cout << "PLEASE INSERT A VALID OPTION." << endl;
            std::cin.clear();
            std::string tmp;
            std::getline(std::cin, tmp);
        }
       
    } while (validation == false);

    return r;
}


int rechercheLogin(std::string id, std::string password,Container<client> clients, Container<employer> employes){
    Setting s;
    if(id[0] == 'c'){
        for(int i = 0; i<clients.taille(); i++){
            if(clients[i].getId() == id)
            {
                if(clients[i].getPassword() == password){
                    s.setNom(clients[i].getNom());
                    s.setPrenom(clients[i].getPrenom());
                    s.setId(clients[i].getId());
                    s.setEmail(clients[i].getEmail());
                    s.setCarteF(clients[i].acarteFidele());
                    return 10;
                }
            }

        }
    }else if(id[0] == 'e'){
        for(int i = 0; i<employes.taille(); i++){
            if(employes[i].getId() == id){
                if(employes[i].getPassword() == password){
                    s.setNom(employes[i].getNom());
                    s.setPrenom(employes[i].getPrenom());
                    s.setId(employes[i].getId());
                    s.setEmail(employes[i].getEmail());
                    s.setTel(employes[i].getTel());
                    s.setEstGerant(employes[i].getEstGerant());
                    return 11;
                }
            }
        }
    }/* else if(id[0] == 'g'){
        for(int i = 0; i<employes.taille(); i++){
            if(employes[i].getId() == id)
                if(employes[i].getPassword() == password)
                    return 11;
        }
    } */
    return 0;
}


int choixLogin(Container<client> clients, Container<employer> employes){
    std::string id;
    std::string password;
    std::cin.exceptions(std::istream::failbit);
    bool validation = true;
    do
    {
        header("Login");
        std::cout << "0: Quitter\n\n";
        try
        {
            std::cout << "Saisir votre identifiant\n>>> ";
            std::cin >> id;
            if (id=="0") return 0;
        }
        catch(const std::exception& e)
        {
                validation = false;
                //cout << "PLEASE INSERT A VALID OPTION." << endl;
                std::cin.clear();
                std::string tmp;
                std::getline(std::cin, tmp);
        }
     

    header("Login");
    std::cout << "0: Quitter\n\n";
    std::cout << "Saisir votre mot de passe\n>>> " ;
    char c = ' ';
    password = "";
    while (c!=13){  // c = 13 is 'Enter' key.
    c = getch();
    if (c!=13){
        password +=c;
        std::cout << "*";
        }
    }
    if (password=="0") return 0;

    validation = rechercheLogin(id, password,clients,employes) != 0;
    } while (validation == false) ;
    return rechercheLogin(id, password,clients,employes);
} 



int choixClient(){
    int r;
    bool validation = true;
    std::cin.exceptions(std::istream::failbit);
    do {
        try {
            system("cls");
            header("Acceuil");
            std::cout << "1. Les produits\n2. Commander\n3. Historique\n4. Recevoir une carte fidelite\n\n0. Deconnecter\n\n";
            std::cout << ">>>";
            std::cin >> r;
            system("cls");
            validation = (r>=0 && r<=4); // menu tests
        }
        catch (const std::exception& e) {
            validation = false;
            //cout << "PLEASE INSERT A VALID OPTION." << endl;
            std::cin.clear();
            std::string tmp;
            std::getline(std::cin, tmp);
        }
       
    } while (validation == false);

    return r;
}
void menuClient(int &logged,Container<Produit> produits,Container<Facture>& factures,Container<client>& clients){
    int r = choixClient();
    Setting s;
    switch (r)
    {
    case 1:
        {
            header("Les produits");
            std::cout << "\nNombre total des produits est: " << produits.taille() << ".\n";
            produits = LoadProduit();
            for (unsigned int i =0;i <produits.taille();i++){
                Produit p = produits[i];
                std::cout << p;
            }
            std::cout << ">>> ";
            system("PAUSE");           
        }
        break;
    case 2:
        {
            header("Commander");
            saveFacture(factures,produits,s.id,s.carteF);
            std::cout << ">>> ";
            system("PAUSE");           
        }
        break;
    case 3:{
        header("Historique des commandes");
        int nbFactures = 0;
        for (unsigned int i = 0; i < factures.taille(); i++){
            Facture fact;
            fact = factures[i];
            if (fact.getIdPersonelle() == s.id){
                std::cout << fact << "\n\n"; 
                nbFactures++;
            }
        }
        std::cout << "Nombre de commandes: " << nbFactures <<std::endl;
        std::cout << ">>> ";
        system("PAUSE");
    }
        break;
    case 4:{
        header("Carte  fid");
        if(s.carteF){
            std::cout << "Vous avez deja une carte de fidelite.\n";
        }else{
            std::cout << "working\n";
            for (unsigned int i =0;i <clients.taille();i++){
                if(clients[i].getId() == s.id){
                    client cli;
                    cli = clients[i];
                    cli.recevoirCarteFidele();
                    Fichier f("clients");
                    f.reset();
                    for (unsigned int j =0;j <clients.taille();j++){
                        client c;
                        if(i==j)
                            c= cli;
                        else
                            c = clients[j];
                        f.appendClient(c);
                    }
                    s.setCarteF(true);
                }
            }
            
        }
        std::cout << ">>> ";
        system("PAUSE");
    }
        break;
    case 0:
        logged = 0;
        /* log out */
        break;  
    
    default:
        break;
    }
    
}

void menuEmployer(int& logged,Container<employer>& employes, Container<Produit>& produits,Container<Facture>& factures,Container<client>& clients){
    int r = choixEmployer();
    Setting s;
     switch (r)
    {
    case 0:
        logged = 0;
        break;
    case 1:
        {
            menuEmployerProduits(produits);
        }
    break;
    case 2:
        {
            menuEmployerCommande(produits,factures);
        }
    break;
    case 3:
        {
            header("personelle");
            menuEmployerPersonelle();
            system("PAUSE");     
        }
    break;
    case 4:
        {
            header("Statistique");
            if (!s.estGerant){
                std::cout << "Seul le gerant peut voir cette page.\n\n>>> ";
                pause();
            }else
            {
                menuGerantStatistique(factures,employes,clients);
            }
            
        }
    break;
    case 5:
        {
            menuEmployerParametres();    
        }
    break;
    default:
        break;
    }
}
void menuLogin(int &logged,Container<client>& clients, Container<employer> employes,Container<Produit> produits,Container<Facture>& factures){
    int r = choixLogin(clients,employes);
    switch (r)
    {
    case 0:
        /* code */
        logged = 0;
        break;
    case 10:
        logged = 1;
        menuClient(logged,produits,factures,clients);
        break;
    case 11:
        logged = 2;
        menuEmployer(logged,employes,produits,factures,clients);
        break;
    default:
        break;
    }
}

void menuInscription(Container<client>& clients){
    header("Inscription");
    client c;
    c.saisirClient(clients);
    Fichier f("clients");
    clients.ajouter(c);
    f.appendClient(c);
    
    std::cout << "\nVous etes inscri.\n\n>>> "; 
    pause();
}
void menu1(int &logged,Container<client>& clients, Container<employer> employes, Container<Produit>& produits,Container<Facture>& factures){
    int r = menu1Choix("page1");
    switch (r)
    {
    case 1: //cnx
        menuLogin(logged, clients,employes,produits,factures);
        break;
    
    case 2: //inscri
        menuInscription(clients);
        break;

    default:
        break;
    }
}

#endif