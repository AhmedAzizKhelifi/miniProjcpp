class Login{
    private:
        int id;
        std::string password;
        Container<Login> accounts;
    public:
        Login();
        Login(std::string); 
        void fillAccountsFromfile();
        void page();


        //get set
        int getId(){return id;}
        std::string getPassword(){return password;}
        Container<Login> getAccounts(){return accounts;}
    
};

Login::Login(){

}
Login::Login(std::string line){
    std::stringstream ss(line);
    ss >> id >> password;
}

void Login::fillAccountsFromfile(){
    Fichier f("accounts");
    Container<std::string> c ; // hedha container eli fih les lignes mtaa el fichier text, kol ligne f element
    c=f.fillContainer(); // lena 3abina c b les lignes mtaa el fichiers
    std::cout << c;
    for (unsigned int i = 0; i < c.taille(); i++){
        accounts.ajouter(Login(c[i]));
    }
}
/*
Login::Login(){
    Fichier f("accounts");
    Container<std::string> c ; // hedha container eli fih les lignes mtaa el fichier text, kol ligne f element
    c=f.fillContainer(); // lena 3abina c b les lignes mtaa el fichiers
    for (unsigned int i = 0; i< c.taille(); i++){
       // cout<< c[i]<<endl;
        produits.ajouter(Produit(c[i])); // lena 7awalna kol ligne men string l Produit w zidneh lel container produit 
    }

    cout << produits; // Affichage mtaa container produit.
} */
void Login::page(){
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

    

}
