#ifndef SETTING_H
#define SETTING_H

using namespace std;
class Setting{
    public:
    static string nom;
    static string prenom;
    static string email;
    static string id;
    static string tel;
    static bool carteF;
    static float remiseSurCarteF;
    static bool estGerant;
    
    
    static void resetSettings(){
        nom="_";
        prenom="_";
        email="_";
        id="_";
        tel="_";
        carteF=false;
        estGerant=false;
        remiseSurCarteF=5.0;  
    };

    void setNom(string _nom){nom = _nom;}
    void setPrenom(string _prenom){prenom = _prenom;}
    void setEmail(string _email){email = _email;}
    void setId(string _id){id = _id;}
    void setTel(int _tel){tel = std::to_string(_tel);}
    void setCarteF(bool c){carteF = c;}
    void setEstGerant(bool c){estGerant  = c;}
};  
string Setting::nom="_";
string Setting::prenom="_";
string Setting::email="_";
string Setting::id="_";
string Setting::tel="_";
bool Setting::carteF=false;
bool Setting::estGerant=false;
float Setting::remiseSurCarteF=5.0;


#endif