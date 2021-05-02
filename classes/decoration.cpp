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
            //system("cls");
            header(path);
            std::cout << "1. Produits\n2. Boozerzer\n3. Sslkdjflk\4. lkdfgklf\n\n";
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
            std::cout << "1. Ajouter Produits\n2. Afficher Produits\n3. Sslkdjflk\4. lkdfgklf\n\n";
            std::cout << ">>>";
            std::cin >> r;
            system("cls");
            validation = (r>0 && r<4); // menu tests
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

void menuProduit(std::vector<Produit>& v){
    int r = menuProduitChoix();
    switch (r)
    {
    case 1:
        {
            header("Produit\\Ajouter");
            
            Produit P1;
            std::cin>> P1;
            v.push_back(P1);

        }
        break;
    case 2:
        {
            header("Produit\\Afficher");
            if(v.size() == 0)
                std::cout<< "Il n'y a rien a afficher.\n";
            std::cout<<"Nombre de produits: " << v.size() << "\n\n";

            for(size_t i = 0; i < v.size(); ++i) 
                std::cout << v[i];
            std::cout << ">>>\n";
            system("PAUSE");           
        }
        break;
    default:
        break;
    }
}


void menuPrincipale(std::vector<Produit>& v){
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
