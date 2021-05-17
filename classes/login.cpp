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


bool rechercheLogin(Container<client> clients, Container<employer> employes){
         for (unsigned int i = 0; i < clients.taille(); i++ ){
        clients[i].afficher();
        cout << "\n\n";
    }
    
    return true;
}


void login(Container<client> clients, Container<employer> employes){
    int id;
    std::string password;
    utilityFunctions uc;
    uc.header("login");
    std::cin.exceptions(std::istream::failbit);
    bool validation = true;
    do
    {
        try
        {
            std::cout << "Id :";
            std::cin >> id;
            validation = true;
        }
        catch(const std::exception& e)
        {
                        validation = false;
                //cout << "PLEASE INSERT A VALID OPTION." << endl;
                std::cin.clear();
                std::string tmp;
                std::getline(std::cin, tmp);
        }

    } while (validation == false);
    std::cout << "Mot de passe: ";
    std::cin >> password;

    rechercheLogin(clients,employes);
} 

void menu1(Container<client> clients, Container<employer> employes){
   int r = menu1Choix("page1");
    if(r==1) //cnx
    {
        login(clients,employes);
    }
    else{
        std::cout << "cree nombre";
    }
}
