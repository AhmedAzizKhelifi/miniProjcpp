int max(int tab[])
{
       int maxId = tab[0];
        for(unsigned int i = 0; i<10;i++){
            if (tab[i]>maxId){
                maxId = tab[i];
            }

        }
        cout<<maxId<<endl;
        return maxId;
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