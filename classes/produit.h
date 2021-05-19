using namespace std;
class Produit
{
private:

    int id; //autoIncremented
    std::string label;
    float prix;
    //
    char printTo = '0'; //si =0 print to screen else to file
    static int nombreTotal;
public:
    Produit();
    Produit(float,std::string);
    Produit(std::string); // read from file line forme: "id label prix"
    void modifier();
    static int nombreTotalProduit(); //jsp static shiha wale lena
   
    //surchage
    friend std::ostream& operator << (std::ostream&,Produit&);
    friend std::istream& operator >> (std::istream&, Produit&);
    float operator+(Produit&); //somme mtaa el prix
    float operator-(Produit&);
    bool operator==(Produit&);
    bool operator==(int); // == bel id 
    bool operator==(std::string); // == bel id 
    bool operator> (Produit&);
    bool operator>(float);
    bool operator< (Produit&);
    bool operator<(float);
    bool operator<= (Produit&);
    bool operator<=(float);
    bool operator>= (Produit&);
    bool operator>=(float);
    // ==, >, < , <=, >=


    //get_set

    
    int getId(){return id;}
    char getPrintTo(){return printTo;}
    void setPrintTo(char c){printTo = c;}
    void setNombreTotal(int nb){nombreTotal= nb;}
    ~Produit();
};

//.cpp

int Produit::nombreTotal=0;

Produit::Produit()
{
    nombreTotal++;
    id = nombreTotal;
    label = "";
    prix = 0;
}

Produit::Produit( float prix,std::string label){
    nombreTotal++;
    this->id = nombreTotal;
    this->prix = prix;
    this->label = label;
}

Produit::Produit(std::string line){
    //"id label prix"
    nombreTotal++;
    if(!isdigit(line[0])) std::cout<<"erreur";
    
    std::stringstream ss(line);
    ss >> id >> label >> prix;;
}

/* std::ostream& operator<< (std::ostream& out,Produit& P){
    std::cout <<"\n\t";
    out << "Produit id " << P.id << "\n\t";
    std::cout <<"\t";
    out << "Label: " << P.label << ".\n\t";
    std::cout <<"\t";
    out << "Prix(DT): " << P.prix << ".";
    std::cout << "\n"; 
    return out;
} */
void Produit::modifier()
{
    cout<<"---modification----"<<endl;
    cout<<"1-label"<<endl<<"2-prix"<<endl;  
    int i;
    cin>>i;
    switch (i)
    {
    case 1:cin>>label;break;
    case 2:cin>>prix;break;
    
    }
}
std::ostream& operator<< (std::ostream& out,Produit& P){
    if(P.printTo=='0') { //to screen
        std::cout <<"\n\t";
        out << "Produit id " << P.id << "\n\t";
        std::cout <<"\t";
        out << "Label: " << P.label << ".\n\t";
        std::cout <<"\t";
        out << "Prix(DT): " << P.prix << ".";
        std::cout << "\n"; 
        return out;
    }else{ //pour fichier
        out << P.id << " "<< P.label<< " " << P.prix<<std::endl;
        return out;
    }
    
}

std::istream& operator>>(std::istream& in,Produit& P){
    //P.nombreTotal++;
    //P.id = P.nombreTotal;
    std::cout << "\n\tID: " << P.id << "\n\t\tLabel: ";
    in >> P.label;
    //std::getline(in, P.label);
   
    bool validation = true;
    do{
        try
        {
            std::cout << "\t\tPrix(DT): ";
            in >> P.prix;
            validation = P.prix>0;
        }
        catch(const std::exception& e)
        {
            validation = false;
            std::cin.clear();
            std::string tmp;
            std::getline(std::cin, tmp);
        }
        
    }while(validation==false);

    return in;
} 

float Produit::operator+(Produit& P){
    return (this->prix + P.prix);
}
float Produit::operator-(Produit& P){
    return (this->prix - P.prix);
}

bool Produit::operator==(Produit& P){
   // if(id == P.id) && (label == P.label) && (prix == P.prix))
    if(id == P.id)
        return true;
    else
        return false;

}
bool Produit::operator==(int _id){ //id
    if (id==_id)
        return true;
    else
        return false;
}
bool Produit::operator==(std::string _id){ //id
    std::string strId = std::to_string(id);
    if (strId==_id)
        return true;
    else
        return false;
}

bool Produit::operator>(Produit& P){
   // if(id == P.id) && (label == P.label) && (prix == P.prix))
    if(prix > P.prix)
        return true;
    else
        return false;

}

bool Produit::operator>=(Produit& P){
   // if(id == P.id) && (label == P.label) && (prix == P.prix))
    if(prix >= P.prix)
        return true;
    else
        return false;

}

bool Produit::operator>(float _prix){
   // if(id == P.id) && (label == P.label) && (prix == P.prix))
    if(prix > _prix)
        return true;
    else
        return false;

}

bool Produit::operator>=(float _prix){
   // if(id == P.id) && (label == P.label) && (prix == P.prix))
    if(prix >= _prix)
        return true;
    else
        return false;

}

bool Produit::operator<(Produit& P){
   // if(id == P.id) && (label == P.label) && (prix == P.prix))
    if(prix < P.prix)
        return true;
    else
        return false;

}

bool Produit::operator<=(Produit& P){
   // if(id == P.id) && (label == P.label) && (prix == P.prix))
    if(prix <= P.prix)
        return true;
    else
        return false;
}

bool Produit::operator<(float _prix){
   // if(id == P.id) && (label == P.label) && (prix == P.prix))
    if(prix < _prix)
        return true;
    else
        return false;
}

bool Produit::operator<=(float _prix){
   // if(id == P.id) && (label == P.label) && (prix == P.prix))
    if(prix < _prix)
        return true;
    else
        return false;

}

int Produit::nombreTotalProduit(){
    //std::cout << "\n\tNombre total des produits est: " << nombreTotal << ".\n";
    return nombreTotal;
}


Produit::~Produit()
{
}
