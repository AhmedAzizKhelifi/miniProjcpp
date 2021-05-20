#include "produit.h"
#include<ctime>

void timeline()
{
  time_t t;
  time(&t);
  std::string curtime=ctime(&t);
  std::cout<<curtime<<std::endl;
}
void header(std::string path = ""){
    system("cls");
    std::cout << "APPLICATION NAME\\" << path << "\n";
    timeline();
}
int ouiNon(std::string text = "_text_", std::string path ="_path_",int h = 1,int fullText = 0){
    std::string r;
    bool validation = true;
    std::cin.exceptions(std::istream::failbit);
    do {
        try {
            if (h==1)
                header(path);
            else
                std::cout << "\n";
            if (fullText==1)
                std::cout << text << "[O/n]\n\n";
            else
                std::cout << "(deco)Vous voulez vraiment " << text << "?[O/n]\n\n";
            std::cout << ">>>";
            std::cin >> r;
            //system("cls");
            validation = r=="O" || r =="o" || r=="N" || r =="n";
        }
        catch (const std::exception& e) {
            validation = false;
            //cout << "PLEASE INSERT A VALID OPTION." << endl;
            std::cin.clear();
            std::string tmp;
            std::getline(std::cin, tmp);
        }
       
    } while (validation == false);
    if (r=="O" || r =="o"  )
        return 1;
    else 
        return 0;
}



int readInt(std::string path ="___",std::string text ="___", int h = 1){
    int r;
    bool validation = true;
    std::cin.exceptions(std::istream::failbit);
    do {
        try {
            if (h ==1)
                header(path);
            else
                std::cout << "\n";
            std::cout << text;
            std::cout << ">>> ";
            std::cin >> r;
           // validation = (r>=0 && r<3); // menu tests
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

float readFloat(std::string path ="___",std::string text ="___", int h = 1){
    float r;
    bool validation = true;
    std::cin.exceptions(std::istream::failbit);
    do {
        try {
            if (h ==1)
                header(path);
            else
                std::cout << "\n";
            std::cout << text;
            std::cout << ">>> ";
            std::cin >> r;
           // validation = (r>=0 && r<3); // menu tests
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

/* 
int menuPrincipaleChoix(std::string path = "Acceuil"){
    int r;
    bool validation = true;
    std::cin.exceptions(std::istream::failbit);
    do {
        try {
            //system("cls");
            header(path);
            std::cout << "1. Produits\n2. Commandes\n3. Personnel\n4. ______\n\n";
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
            std::cout << "1. Ajouter\n2. Afficher\n3. Modifier\n4. Supprimer\n5. Statistique\n\n0. Retour\n\n";
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

void menuProduit(std::vector<Produit>& v){
    int r = menuProduitChoix();
    switch (r)
    {
    case 0:
        break;
    case 1:
        {
            int yn = ouiNon("ajouter un nouveau produit","Produit\\Ajouter");
            if (yn == 1){
                header("Produit\\Ajouter"); 
                Produit P1;
                std::cin>> P1;
                
                v.push_back(P1);
            }
            else
                break;


        }
        break;
    case 2:
        {
            header("Produit\\Afficher");
            if(v.size() == 0)
                std::cout<< "Il n'y a rien a afficher.\n";
            else
                std::cout<<"Nombre de produits: " << v.size() << "\n";

            for(size_t i = 0; i < v.size(); ++i) 
                std::cout << v[i];
            std::cout << "\n>>> ";
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
 */