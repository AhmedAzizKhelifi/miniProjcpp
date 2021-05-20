//int max(float tab[],Container<Facture> factures,int annee = 2021)
float max(float tab[])
{

    float max = tab[0];
        for(unsigned int i = 0; i<12;i++){
            if (tab[i]>max){
                max = tab[i];
            }
        }
        return max;
}
void aff(int b,int a)
{
    int x=b/a;
    for(int i=0;i<x;i++)
        cout<<"*";
    cout<<"\n";
    for(int i=0;i<x;i++)
        cout<<"*";
    cout<<endl<<endl;
}
void main1()
{
        int mois = 0;
    float tab1[12] = {0.0};
    for(unsigned int i =0; i<factures.taille();i++){
        if (factures[i].getdate().get_annee()==2021){
            mois = factures[i].getdate().get_mois();
            tab1[mois-1] += factures[i].getprix();
        }
    }
    float r=max(tab1);
    int a=r/60;
    for(unsigned int i=0;i<12;i++)
    {
    cout<<"mois °"<<i+1;
    aff(tab1[i],a);
    }
}