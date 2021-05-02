#include <iostream>
#include <vector>
#include"classes/decoration.cpp"
//#include "classes/produit.h"

using namespace std;
int main(){
    vector<int> v;
    v.push_back(9);
    v.push_back(9);
    v.push_back(9);
     for(size_t i = 0; i < v.size(); ++i) {
        cout << v[i];
     }
    while (true)
    {
        
        menuPrincipale(v);

             for(size_t i = 0; i < v.size(); ++i) {
        cout << v[i];
     }
        break;
    }
    
}