class Produit
{
private:

    int id; //autoIncremented
    std::string label;
    float prix;
    static int nombreTotal;
public:
    Produit();
    Produit(std::string, float);

    static int nombreTotalProduit(); //jsp static shiha wale lena

    //surchage
    friend std::ostream& operator << (std::ostream&,Produit&);
    friend std::istream& operator >> (std::istream&, Produit&);
    float operator+(Produit&); //somme mtaa el prix
    float operator-(Produit&);
    bool operator==(Produit&);
    bool operator==(int); // == bel id 
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

Produit::Produit(std::string label, float prix){
    nombreTotal++;
    this->id = nombreTotal;
    this->prix = prix;
    this->label = label;
}

std::ostream& operator<< (std::ostream& out,Produit& P){
    out << "\n\tProduit id " << P.id << "\n\t\tLabel: " << P.label << ".\n\t\tPrix(DT): " << P.prix << ".\n"; 
    return out;
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
    std::cout << "\n\tNombre total des produits est: " << nombreTotal << ".\n";
    return nombreTotal;
}


Produit::~Produit()
{
}
