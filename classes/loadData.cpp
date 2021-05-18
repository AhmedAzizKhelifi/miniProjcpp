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