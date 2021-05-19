#include<string>
#include<iostream>
#include<vector>
#include<fstream>
#include"time.h"
/* #include"personnelle.h" */
using namespace std;
 
void historique_client(client c)
{
    
    string ch,ch1,ch2;
    ifstream f;
    f.open("historique_facture.txt");
    while(!f.eof())
    {
        f>>ch>>ch1>>ch2;
        if (c.getId()==ch)
        {
            
            cout<<ch<<"\t"<<ch1<<"\t"<<ch2<<"\n";
        }
    }

}
void historique_gerant()
{
    time_t t;
    struct tm tm=*localtime(&t);
    string ch,ch1,ch2;
    int i;
    string today=to_string(tm.tm_mday);
    string month=to_string(tm.tm_mon);
    ifstream f;
    cout<<"1- today\t2- last month\t3- last year\n";
    do{
     cin>>i;
    }while(i<1 && i>3);
    f.open("saves/factures.txt");
    while(!f.eof())
    {
        f>>ch>>ch1>>ch2;
        switch (i)
        {
        case 1:
        if(ch2==today){cout<<ch<<"\t"<<ch1<<"\t"<<ch2<<"\n";}break;
        case 2:if(ch2==month){cout<<ch<<"\t"<<ch1<<"\t"<<ch2<<"\n";}break;
        default:cout<<ch<<"\t"<<ch1<<"\t"<<ch2<<"\n";
            break;
        }
    }
}