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
    std::cout << "\t\tPrix(DT): ";
    in >> P.prix;
    return in;
} 

float Produit::operator+(Produit& P){
    return (this->prix + P.prix);
}
float Produit::operator-(Produit& P){
    return (this->prix - P.prix);
}

int Produit::nombreTotalProduit(){
    std::cout << "\n\tNombre total des produits est: " << nombreTotal << ".\n";
    return nombreTotal;
}


Produit::~Produit()
{
}
