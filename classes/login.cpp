
#include "personnelle.h"
#include "LoadData.cpp"
#include"historique.h"
#include "settings.h"
#include <conio.h>


void saveProductToFile(Container<Produit>& produits){
    Produit p;  
    std::cin >> p;
    produits.ajouter(p);
    Fichier f("produits");
    f.appendProduit(p);
    std::cout << "\nProduit ajoute avec success.\n\n>>> ";
    system("PAUSE");
}

void saveFacture(Container<Facture>& factures,Container<Produit> produits){
    Facture fact;  
    fact.saisir_fact(produits);
    factures.ajouter(fact);
    Fichier f("facture");
    f.appendFacture(fact);
    std::cout << "\nFacture ajoutee avec success.\n\n>>> ";
}

void saveFacture(Container<Facture>& factures,Container<Produit> produits, std::string idP){
    Facture fact;  
    fact.saisir_fact(produits,idP);
    factures.ajouter(fact);
    Fichier f("facture");
    f.appendFacture(fact);
    std::cout << "\nFacture ajoutee avec success.\n\n>>> ";
}

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
            std::cout << "1. Les produits\n2. Commander\n3. Historique\n\n0. Deconnecter\n\n";
            std::cout << ">>>";
            std::cin >> r;
            system("cls");
            validation = (r>=0 && r<4); // menu tests
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
void menuClient(int &logged,Container<Produit> produits,Container<Facture>& factures){
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
            header("Commender");
            saveFacture(factures,produits,s.id);
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
    case 0:
        logged = 0;
        /* log out */
        break;  
    
    default:
        break;
    }
    
}

int choixEmployer(std::string path = "Acceuil"){
    int r;
    bool validation = true;
    std::cin.exceptions(std::istream::failbit);
    do {
        try {
            //system("cls");
            header(path);
            std::cout << "1. Produits\n2. Commandes\n3. Personnel\n4. ______\n\n0. Deconnecter\n\n";
            std::cout << ">>>";
            std::cin >> r;
            system("cls");
            validation = r>=0 && r<=4; // menu tests
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

int choixEmployerProduits(){
    int r;
    bool validation = true;
    std::cin.exceptions(std::istream::failbit);
    do {
        try {
            system("cls");
            header("Produits");
            std::cout << "1. Afficher\n2. Ajouter\n3. Modifier\n4. Supprimer\n\n0. Retour\n\n";
            std::cout << ">>>";
            std::cin >> r;
            system("cls");
            validation = (r>=0 && r<5); // menu tests
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


int choixEmployerCommandes(){
    int r;
    bool validation = true;
    std::cin.exceptions(std::istream::failbit);
    do {
        try {
            system("cls");
            header("Commandes");
            std::cout << "1. Archive des factures\n2. Nouvelle commande\n3. Supprimer commande\n\n0. Retour\n\n";
            std::cout << ">>>";
            std::cin >> r;
            system("cls");
            validation = (r>=0 && r<=3); // menu tests
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

void menuEmployerCommande(Container<Produit> produits,Container<Facture>& factures){
    int r = choixEmployerCommandes();
    switch (r)
    {
    case 0:
        break;
    case 1:
        header("Commandes\\Archive des factures");
        std::cout << "Nombre de commandes total: " <<  factures.taille() <<  std::endl;
        for (unsigned int i = 0; i < factures.taille(); i++){
            Facture fact;
            fact = factures[i];
            std::cout << fact << "\n\n"; 
        }
        std::cout << ">>> ";
        system("PAUSE");
        break;
    case 2:
        header("Commandes\\Nouvelle Commande");
        saveFacture(factures,produits);
        std::cout << ">>> ";
        system("PAUSE");
        break;
    case 3:
        {
/*             header("suppr");
            system("PAUSE");    */  
            r  = ouiNon("supprimer une commande","Commandes\\Supprimer");
            if (r == 1){
                header("Commande\\Supprimer");
                std::string id;
                std::cout << "Saisir l'id du commande a supprimer.\n\n>>> ";
                std::cin >> id;
                Facture fact = factures.getBystrId(id);
                if (factures.idstrExist(id))
                {
                    header("Commandes\\Supprimer");
                    std::cout << fact;
                    r  = ouiNon("supprimer commande ID:  "+ id + " ","Commandes\\Supprimer",0);
                    Facture fact = factures.getBystrId(id);
                    std::cout << fact;
                    if (r == 1){
                        factures.supprimer(id);
                        Fichier f("facture");
                        f.reset();
                        for (unsigned int i =0;i <factures.taille();i++){
                            Facture fact = factures[i];
                            f.appendFacture(fact);
                            header("Commandes\\Ajouter");
                            std::cout << "Commande supprimer avec succes.\n\n>>> ";
                            system("PAUSE");
                        }
                    }else  break;

                }else{
                        std::cout << "Id n'existe pas.\n\n>>> ";
                        system("PAUSE");
                        break;
                }
            }
        }
        break;
    default:
        break;
    }
}


void menuEmployerProduits(Container<Produit>& produits){
    int r = choixEmployerProduits();
    switch (r)
    {
    case 0:
        break;
    case 1:
        {
            header("Produits\\Afficher");
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
            //oui non
            r = ouiNon("ajouter un nouveau produit","Produits\\Ajouter");
            if (r==1){
                header("Produits\\Ajouter");
                saveProductToFile(produits);
                break;
            }
            
            // do until confirmer
            header("Produits\\Ajouter");
            std::cout << ">>> ";
            system("PAUSE");
        }
    break;
    case 3:
        {
            r  = ouiNon("modifier un produit","Produits\\Modifier");
            if (r == 1){
                header("Produits\\Modifier");
                std::string id;
                std::cout << "Saisir l'id du produit a modifier.\n\n>>> ";
                std::cin >> id;
                if(produits.idintExist(id)){
                    header("Produits\\Modifier");
                    Produit p = produits.getByintId(id);
                    std::cout << p;
                    r  = ouiNon("modifier produit ID:  "+ id + " ","Produits\\Modifier",0);

                    if (r == 1){
                        do
                        {    
                            produits.modifier(id);
                            r = ouiNon("continuer a modifier le produit ID:  "+ id + " ","Produits\\Modifier",0);
                            Produit p = produits.getByintId(id);
                            std::cout << p;
                        } while (r==1);
                        
                        
                        
                        Fichier f("produits");
                        f.reset();
                        for (unsigned int i =0;i <produits.taille();i++){
                            Produit p = produits[i];
                            f.appendProduit(p);
                        }
                        std::cout << "Produit modifier avec succes.\n\n>>> ";
                        //header("Produits\\Ajouter");
                        system("PAUSE");
                    }
                    else {
                        std::cout << "\n\n>>> ";
                        system("PAUSE");
                        break;
                    }

                }else{
                    std::cout << "Id n'existe pas.\n\n>>> ";
                    system("PAUSE");
                    
                }

            }
        }
        break;  
    case 4:
        {
/*             header("suppr");
            system("PAUSE");    */  
            r  = ouiNon("supprimer un produit","Produits\\Supprimer");
            if (r == 1){
                header("Produits\\Supprimer");
                std::string id;
                std::cout << "Saisir l'id du produit a supprimer.\n\n>>> ";
                std::cin >> id;
                if(produits.idintExist(id)){

                    r  = ouiNon("supprimer produit ID:  "+ id + " ","Produits\\Supprimer");
                    Produit p = produits.getByintId(id);
                    std::cout << p;
                    
                    if (r == 1){
                    produits.supprimer(id);
                    Fichier f("produits");
                    f.reset();
                    for (unsigned int i =0;i <produits.taille();i++){
                        Produit p = produits[i];
                        f.appendProduit(p);
                    }
                    header("Produits\\Ajouter");
                    std::cout << "Produit supprimer avec succes.\n\n>>> ";
                    system("PAUSE");
                    }
                    else {
                        break;
                    }

                }else{
                    std::cout << "Id n'existe pas.\n\n>>> ";
                    system("PAUSE");
                    
                }

            }
        }
        break;
    default:
        break;
    }    
}

void menuEmployer(int& logged,Container<employer>& employes, Container<Produit>& produits,Container<Facture>& factures){
    int r = choixEmployer();
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
            system("PAUSE");     
        }
    default:
        break;
    }
}
void menuLogin(int &logged,Container<client> clients, Container<employer> employes,Container<Produit> produits,Container<Facture>& factures){
    int r = choixLogin(clients,employes);
    switch (r)
    {
    case 0:
        /* code */
        logged = 0;
        break;
    case 10:
        logged = 1;
        menuClient(logged,produits,factures);
        break;
    case 11:
        logged = 2;
        menuEmployer(logged,employes,produits,factures);
        break;
    default:
        break;
    }
}

void menu1(int &logged,Container<client> clients, Container<employer> employes, Container<Produit>& produits,Container<Facture>& factures){
    int r = menu1Choix("page1");
    switch (r)
    {
    case 1: //cnx
        menuLogin(logged, clients,employes,produits,factures);
        break;
    
    case 2: //inscri
        break;

    default:
        break;
    }
}
