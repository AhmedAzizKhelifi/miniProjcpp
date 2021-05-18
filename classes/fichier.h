
#include"container.h"

class Fichier{
    private:
        std::string nom;
        std::fstream file;
    public:
        Fichier(std::string);
        void afficher();
        Container<std::string> fillContainer(); // fill container by strings from file, line by line
        void appendStr(std::string);
        void appendProduit(Produit);
        void reset(); //supprimer le contenu du fichier
        //surchage
        friend std::ostream& operator << (std::ostream&,Fichier&);
      //  friend std::istream& operator >> (std::istream&,Fichier&);

        //get set
        std::fstream& getFile(){
            this->file.open("saves\\"+nom+".txt",std::ios::in|std::ios::app);
            return file;
        }
        std::string getNom(){return nom;}

};


Fichier::Fichier(std::string nom){
    this-> nom = nom;
    this->file.open("saves\\"+nom+".txt",std::ios::in|std::ios::app);
    if(!file.is_open()) std::cout << "not open";
    file.close();
}

void Fichier::afficher(){
    char ch[101];
    file.seekg(0);
    file.open("saves\\"+nom+".txt",std::ios::in|std::ios::app);
        while(true){
        file.getline(ch,100,'\n');
        std::cout << ch<<std::endl;
        if(file.eof()) break;
    }
    file.close();
}


Container<std::string> Fichier::fillContainer(){
    Container<std::string> c;
    char ch[101];
    file.seekg(0);
    file.open("saves\\"+nom+".txt",std::ios::in|std::ios::app);
    while(true){
        file.getline(ch,100,'\n');
        if(isdigit(ch[0]) | ch[0] == 'c' | ch[0] == 'e') c.ajouter(ch);
        if(file.eof()) break;
    }
    file.close();
    return c;
}

void Fichier::appendStr(std::string ch){
    file.open("saves\\"+nom+".txt",std::ios::in|std::ios::app);
    file << ch << std::endl;
    file.close();
}
/* 
std::fstream  Fichier::getFile()
{return this->file;} */

void Fichier::appendProduit(Produit p){
    file.open("saves\\"+nom+".txt",std::ios::in|std::ios::app);
    p.setPrintTo('1');
    file <<p;
    p.setPrintTo('0');
    file.close();   
}

void Fichier::reset(){
    file.open("saves\\"+nom+".txt",std::ios::out | std::ios::trunc);
    file.close();
}

//surchage
std::ostream& operator << (std::ostream& out,Fichier& f){
    char ch[101];
    f.file.open("saves\\"+f.nom+".txt",std::ios::in|std::ios::app);
    f.file.seekg(0);
        while(true){
        f.file.getline(ch,100,'\n');
        //std::cout << ch<<std::endl;
        if (ch=="") std::cout << "taw";
        out << ch << std::endl;

        if(f.file.eof()) break;
    }
    f.file.close();
    return out;
}

