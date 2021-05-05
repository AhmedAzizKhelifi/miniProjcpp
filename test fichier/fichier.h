
class Fichier{
    private:
        std::string nom;
        std::fstream file;
    public:
        Fichier(std::string);
        void afficher();
        void appendStr(std::string);
        friend std::ostream& operator << (std::ostream&,Fichier&);
};

Fichier::Fichier(std::string nom){
    this-> nom = nom;
    this->file.open("saves\\"+ nom+".txt",std::ios::in|std::ios::app);
    if(!file.is_open()) std::cout << "not open";
    file.close();
}

void Fichier::afficher(){
    char ch[101];
    file.seekg(0);
    file.open(".\\saves\\"+nom+".txt",std::ios::in|std::ios::app);
        while(true){
        file.getline(ch,100,'\n');
        std::cout << ch<<std::endl;
        if(file.eof()) break;
    }
    file.close();
}

void Fichier::appendStr(std::string ch){
    file.open(".\\saves\\"+,std::ios::in|std::ios::app);
    file << ch << std::endl;
    file.close();   
}


//surchage
std::ostream& operator << (std::ostream& out,Fichier& f){
    char ch[101];
    f.file.seekg(0);
    f.file.open(f.nom+".txt",std::ios::in|std::ios::app);
        while(true){
        f.file.getline(ch,100,'\n');
        //std::cout << ch<<std::endl;
        out << ch << std::endl;
        if(f.file.eof()) break;
    }
    f.file.close();
    return out;
}


