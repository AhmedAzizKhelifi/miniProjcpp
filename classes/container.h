template<class T>
class Container{
    private:
        std::vector<T> tab;
    public:
        void ajouter(T);
        void supprimer(std::string);
        int taille(){return tab.size();}
        T operator[](int);
        template<class U>
        friend std::ostream& operator<< (std::ostream&, Container<U>&);
};

template <class T>
T Container<T>::operator[](int i){
    return tab[i];
}

template<class T>
void Container<T>::ajouter(T element){
    tab.push_back(element);
}

template<class T>
void Container<T>::supprimer(std::string id){
    for(unsigned int i = 0; i<taille();i++){
        T produit = tab[i];
        if (produit==id){
            std::cout << "index : "<< i << std::endl;
            tab.erase(tab.begin() + i);
        }
    }
}

template <class U>
std::ostream& operator<< (std::ostream& o, Container<U>&t){
        o << "[";
    for (int i = 0; i<t.tab.size(); i++){
        if (i==t.tab.size()-1){
            o << t.tab[i];
        } else{
        o << t.tab[i] << ", ";    
        }      
    }
     o<< "]" <<std::endl;
    return o;
}

