 Fichier f("test");
    Container<std::string> c ; // hedha container eli fih les lignes mtaa el fichier text, kol ligne f element
    Container <Produit> produits; // hedha el container eli bech nhotou fih el Produit, eli bech naqrawhom mel fichier
    //cout << f;
    c=f.fillContainer(); // lena 3abina c b les lignes mtaa el fichiers
    for (unsigned int i = 0; i< c.taille(); i++){
       // cout<< c[i]<<endl;
        produits.ajouter(Produit(c[i])); // lena 7awalna kol ligne men string l Produit w zidneh lel container produit 
    }

    cout << produits; // Affichage mtaa container produit.
