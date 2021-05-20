Container<client> LoadClients(){
    Fichier f("clients");
    Container<std::string> c ;
    c=f.fillContainer();

    Container<client> clients;
    for (unsigned int i = 0; i < c.taille(); i++ ){
        clients.ajouter(client(c[i],1));
    }
    return clients;
}

Container<Produit> LoadProduit(){
    Fichier f("produits");
    Container<std::string> c ;
    c=f.fillContainer();

    Container<Produit> produits;
    for (unsigned int i = 0; i < c.taille(); i++ ){
        produits.ajouter(Produit(c[i]));
      
    }
    Produit p;
    p.setNombreTotal(produits.biggerId());
    return produits;
}

Container<employer> LoadEmployer(){
    Fichier f("employer");
    Container<std::string> c ;
    c=f.fillContainer();

    Container<employer> employes;
    for (unsigned int i = 0; i < c.taille(); i++ ){
        employes.ajouter(employer(c[i],4));
    }
    return employes;
}

//Container<Facture>
Container<Facture> LoadFacture(){
    std::fstream file;
    file.open("saves\\facture.txt",std::ios::in|std::ios::app);
    Container<std::string> c1 ;
    Container<std::string> c2 ;

    Container<Facture> factures;
    char ch[101];
    file.seekg(0);
    while(true){
        file.getline(ch,100,'\n'); //id produits
        if(!isdigit(ch[0]) )break;
        c2.ajouter(ch);
        file.getline(ch,100,'\n'); // facture details
        c1.ajouter(ch);
        if(file.eof()) break;
    }
    file.close();
    for (unsigned int i = 0; i < c1.taille(); i++){
        Facture fact(c1[i],c2[i]);
        factures.ajouter(fact);
    }
    return factures;
}