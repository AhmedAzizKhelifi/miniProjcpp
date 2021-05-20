void saveProductToFile(Container<Produit>& produits){
    Produit p;  
    std::cin >> p;
    produits.ajouter(p);
    Fichier f("produits");
    f.appendProduit(p);
    std::cout << "\nProduit ajoute avec success.\n\n>>> ";
    system("PAUSE");
}

void saveFacture(Container<Facture>& factures,Container<Produit> produits){
    Facture fact;  
    fact.saisir_fact(produits);
    factures.ajouter(fact);
    Fichier f("facture");
    f.appendFacture(fact);
    std::cout << "\nFacture ajoutee avec success.\n\n>>> ";
}

void saveFacture(Container<Facture>& factures,Container<Produit> produits, std::string idP,bool carteF){
    Facture fact;  
    fact.saisir_fact(produits,idP,carteF);
    factures.ajouter(fact);
    Fichier f("facture");
    f.appendFacture(fact);
    std::cout << "\nFacture ajoutee avec success.\n\n>>> ";
}
