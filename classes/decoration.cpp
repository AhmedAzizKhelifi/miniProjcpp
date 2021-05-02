#include "produit.h"
void header(std::string path = ""){
    system("cls");
    std::cout << "APPLICATION NAME\\" << path << "\n\n";
}

int menuPrincipaleChoix(std::string path = "Acceuil"){
    int r;
    bool validation = true;
    std::cin.exceptions(std::istream::failbit);
    do {
        try {
            system("cls");
            header(path);
            std::cout << "1. Produits\n2. Alksdjflksdj\n3. Sslkdjflk\4. lkdfgklf\n\n";
            std::cout << ">>>";
            std::cin >> r;
            system("cls");
            validation = r>0 && r<4; // menu tests
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







int menuProduitChoix(std::string path = "Produits"){
    int r;
    bool validation = true;
    std::cin.exceptions(std::istream::failbit);
    do {
        try {
            system("cls");
            header(path);
            std::cout << "1. Ajouter Produits\n2. Alksdjflksdj\n3. Sslkdjflk\4. lkdfgklf\n\n";
            std::cout << ">>>";
            std::cin >> r;
            system("cls");
            validation = r>0 && r<4; // menu tests
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

void menuProduit(std::vector<int>& v){
    int r = menuProduitChoix();
    switch (r)
    {
    case 1:
        {
            std::cout<< "ajouter habibi";
            Produit P1;
            std::cin>> P1;
            v.push_back(1000);

        }
        break;
    
    default:
        break;
    }
}


void menuPrincipale(std::vector<int>& v){
    int r = menuPrincipaleChoix();
    switch (r)
    {
    case 1:
        menuProduit(v);
        break;
    
    default:
        break;
    }
}
