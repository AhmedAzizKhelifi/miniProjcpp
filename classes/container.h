template<class T>
class Container{
    private:
        std::vector<T> tab;
    public:
        void ajouter(T);
        void supprimer(std::string);
        void supprimerParIndice(int);
        void modifier(std::string);
        int find(T);
        int biggerId();
        bool idintExist(std::string);
        bool idstrExist(std::string);
        T getByintId(std::string);
        T getBystrId(std::string);
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
int Container<T>::find(T element){
    for (unsigned int i =0;i<taille();i++){
        if (element==tab[i])
            return i;
    }
    return -1;
}

template<class T>
bool Container<T>::idintExist(std::string id){
    for(unsigned int i = 0; i<taille();i++){
        T produit = tab[i];
        if (std::to_string(produit.getId())==id){
            return true;
        }
    }
    return false;
}

template<class T>
bool Container<T>::idstrExist(std::string id){
    for(unsigned int i = 0; i<taille();i++){
        T produit = tab[i];
        if (produit.getId()==id){
            return true;
        }
    }
    return false;
}

template<class T>
T Container<T>::getByintId(std::string id){
    for(unsigned int i = 0; i<taille();i++){
        T element = tab[i];
        if (std::to_string(element.getId())==id){
            return element;
        }
    }

    return T();
}

template<class T>
T Container<T>::getBystrId(std::string id){
    for(unsigned int i = 0; i<taille();i++){
        T element = tab[i];
        if (element.getId()==id){
            return element;
        }
    }

    return T();
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

template<class T>
void Container<T>::supprimerParIndice(int index){
    tab.erase(tab.begin() + index);
}



template<class T>
void Container<T>::modifier(std::string id){
    std::cout << "modif:::::\n\n";
    for(unsigned int i = 0; i<taille();i++){
        T produit = tab[i];
        if (produit==id){
            std::cout << "index : "<< i << std::endl;
            produit.modifier();
            tab[i] = produit;
        }
    }
}

template<class T>
int Container<T>::biggerId(){
    if (taille()>0){
        int maxId = tab[0].getId();
        for(unsigned int i = 0; i<taille();i++){
            T produit = tab[i];
            if (produit.getId()>maxId){
                maxId = produit.getId();
            }

        }
        return maxId;
    }else{
        return 0;
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

