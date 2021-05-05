template<class T>
class Container{
    private:
        std::vector<T> tab;
    public:
        void ajouter(T);
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

