void statDepenseEnSalaireEmployer(Container<employer>e){
  float salaires = 0.0;
  for(int i=0;i<e.taille();i++)
    {
      salaires+=e[i].getSalaire();
    }
    cout<<"La somme des salaires des employes par mois est :"<<salaires;
    cout << "\nNombre total des employes est :" << e.taille();
    if(e.taille()>0){
      cout << "\nCe qui est au moyenne "<< (float)(salaires/e.taille()) << " par employer.";
    }
    }

void statSommeVente(Container<Facture> p,Container<employer> e)
{
    // somme taa vente
    float sum,summonth,sumyear,salaires;
    sum = 0;
    summonth = 0;
    sumyear = 0;
    date today;
    today = today.getToday();
   for(int i=0;i<p.taille();i++)
     {
        if(p[i].getdate()==today)
          sum+=p[i].getprix();
        if(p[i].getdate().get_mois()== today.get_mois() && p[i].getdate().get_annee() == today.get_annee())
          summonth+=p[i].getprix();
        if(p[i].getdate().get_annee()==today.get_annee())
           sumyear+=p[i].getprix();  
      }
    
    cout<<"+ Les sommes des ventes d'aujourd'hui est: "<<sum<< "DT."<<endl; 
    cout<<"+ Les sommes des ventes du mois "<< date::getMonthName(today.get_mois()) <<": "<<summonth<< "DT."<<endl; 
    cout<<"+ Les sommes des ventes de cette annee ("<<today.get_annee()<<") est: " <<sumyear<< "DT."<<endl; 
/*     cout<<"la somme des achats d'aujourd'hui ="<<
    cout<<"la somme des achats du mois ="<<;
    cout<<"la somme des achats d'année ="<<; */
    //cout<<"autres depenses =";



}

void statHistograme(Container<Facture> factures, int annee){
    // tkharej histograme taa kol mois
    int mois = 0;
    float tab1[12] = {0.0};
    int maxHistogramme=0;
    for(unsigned int i =0; i<factures.taille();i++){
        if (factures[i].getdate().get_annee()==annee){
            mois = factures[i].getdate().get_mois();
            tab1[mois-1] += factures[i].getprix();
        }
    }
    float r=max(tab1);
    float a=(r/60.0);

    //printing
    string ch = "Histogramme "+std::to_string(annee);
    printf("\n  ------------%s-------------\n\n",ch.c_str());
    
    for(unsigned int i=0;i<12;i++)
    {
    //cout<<"Numero du mois"; //<<i+1<<endl;
    printf("%3d | %10s | ", i+1,date::getMonthName(i).c_str());
    buildHistogram(tab1[i],a,maxHistogramme);
    }
    cout << "\nIntervalle de ";
    printf("%7d",0);
    for(unsigned int i =0; i<55;i++ )
        cout << "-";
    printf(">>%d\n",maxHistogramme);
    //printf("\nIntervale de%8d------------>>%55d\n",0,maxHistogramme);
}

void statClients(Container<client> clients){
  cout << "Nombre des clients inscri: " << clients.taille() << endl;
  cout << "Nombre des clients fidele: ";
  int nb = 0;
  for(unsigned int i = 0; i<clients.taille(); i++){
    if(clients[i].acarteFidele())
      nb++;
  }
  cout << nb << endl;
}