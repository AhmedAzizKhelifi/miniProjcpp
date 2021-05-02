using namespace std;
void header(std::string path = ""){
    system("cls");
    std::cout << "APPLICATION NAME\\" << path << "\n\n";
}

int menuPrincipale(){
    int r;
    std::cout << "1. Produits\n2. Alksdjflksdj\n3. Sslkdjflk\4. lkdfgklf\n\n";

    bool validation = true;
    cin.exceptions(std::istream::failbit);
    do {
        try {
            cout << ">>>";
            cin >> r;
            validation = r>0 && r<4; // menu tests
        }
        catch (const std::exception& e) {
            validation = false;
            //cout << "PLEASE INSERT A VALID OPTION." << endl;
            cin.clear();
            std::string tmp;
            getline(cin, tmp);
        }
       
    } while (validation == false);

    return r;
}