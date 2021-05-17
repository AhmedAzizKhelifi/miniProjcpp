class Menu{
    private:
    public:
    int menuPrincipaleChoix(std::string path = "Acceuil");
};

int Menu::menuPrincipaleChoix(std::string path){
    int r;
    bool validation = true;
    utilityFunctions uf;
    std::cin.exceptions(std::istream::failbit);
    do {
        try {
            //system("cls");
            uf.header(path);
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