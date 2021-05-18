class utilityFunctions{
    private:
    public:
    void header(std::string = "");
    int ouiNon(std::string = "____", std::string ="____");
};


void utilityFunctions::header(std::string path){
    system("cls");
    std::cout << "APPLICATION NAME\\" << path << "\n\n";
}
int utilityFunctions::ouiNon(std::string text , std::string path){ // y =1, n =0
    utilityFunctions uf;
    std::string r;
    bool validation = true;
    std::cin.exceptions(std::istream::failbit);
    do {
        try {
            uf.header(path);
            std::cout << "Vous voulez vraiment " << text << "?[O/n]\n\n";
            std::cout << ">>>";
            std::cin >> r;
            system("cls");
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