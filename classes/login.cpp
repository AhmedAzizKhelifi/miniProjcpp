#include "personnelle.h"


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


bool rechercheLogin(std::string id, std::string password,Container<client> clients, Container<employer> employes){
    for(int i = 0; i<clients.taille(); i++){
        if(clients[i].getId() == id)
            if(clients[i].getPassword() == password)
                return true;
    }
    
    return false;
}


int choixLogin(Container<client> clients, Container<employer> employes){
    std::string id;
    std::string password;
    utilityFunctions uc;
    std::cin.exceptions(std::istream::failbit);
    bool validation = true;
    do
    {
        uc.header("Login");
        std::cout << "q: quit\n\n";
        try
        {
            std::cout << "Id \n\n>>> ";
            std::cin >> id;
            if (id=="q") return 0;
        }
        catch(const std::exception& e)
        {
                validation = false;
                //cout << "PLEASE INSERT A VALID OPTION." << endl;
                std::cin.clear();
                std::string tmp;
                std::getline(std::cin, tmp);
        }

    uc.header("Login");
    std::cout << "q: quit\n\n";
    std::cout << "Mot de passe\n\n>>> " ;
    std::cin >> password;
    if (password=="q") return 0;

    validation = rechercheLogin(id, password,clients,employes);
    } while (validation == false) ;
    std::cout <<"loged";
    return 10;
} 



int choixClient(){
    int r;
    bool validation = true;
    std::cin.exceptions(std::istream::failbit);
    do {
        try {
            system("cls");
            header("Menu Client");
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
void menuClient(bool &logged,Container<Produit> produits){
    logged = true;
    int r = choixClient();
    switch (r)
    {
    case 1:
        //produits:
        header("Les produits");
        cout << produits;
        system("PAUSE");   
        break;
    case 0:
        logged = false;
        /* log out */
        break;  
    
    default:
        break;
    }
    
}

void menuLogin(bool &logged,Container<client> clients, Container<employer> employes,Container<Produit> produits){
    int r = choixLogin(clients,employes);
    switch (r)
    {
    case 0:
        /* code */
        logged = false;
        break;
    case 10:
        logged = true;
        menuClient(logged,produits);
        break;
    default:
        break;
    }
}

void menu1(bool &logged,Container<client> clients, Container<employer> employes, Container<Produit> produits){
    int r = menu1Choix("page1");
    switch (r)
    {
    case 1: //cnx
        menuLogin(logged, clients,employes,produits);
        break;
    
    case 2: //inscri
        break;

    default:
        break;
    }
}
