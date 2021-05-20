#include "saveToFiles.cpp"

int choixEmployerParametre(std::string path = "Parametres"){
    int r;
    bool validation = true;
    std::cin.exceptions(std::istream::failbit);
    do {
        try {
            //system("cls");
            header(path);
            std::cout << "1. Parametre du compte\n2. Ajouter un employer\n3. Supprimer un employer\n4. Definir les date de promotions\n5. Defenir la promotion sur la carte fidelite\n\n0. Retour\n\n";
            std::cout << ">>>";
            std::cin >> r;
            system("cls");
            validation = r>=0 && r<=5; // menu tests
        }   
        catch (const std::exception& e) {
            validation = false;
            //cout << "PLEASE INSERT A VALID OPTION." << endl;
            std::cin.clear();
            std::string tmp;
            std::getline(std::cin, tmp);
        }
       
    } while (validation == false);

    return r;
}


int choixEmployer(std::string path = "Acceuil"){
    int r;
    bool validation = true;
    std::cin.exceptions(std::istream::failbit);
    do {
        try {
            //system("cls");
            header(path);
            std::cout << "1. Produits\n2. Commandes\n3. Personnel\n4. Statistique\n5. Parametres\n\n0. Deconnecter\n\n";
            std::cout << ">>>";
            std::cin >> r;
            system("cls");
            validation = r>=0 && r<=5; // menu tests
        }   
        catch (const std::exception& e) {
            validation = false;
            //cout << "PLEASE INSERT A VALID OPTION." << endl;
            std::cin.clear();
            std::string tmp;
            std::getline(std::cin, tmp);
        }
       
    } while (validation == false);

    return r;
}

int choixGerantStatistique(std::string path = "Statistique"){
    int r;
    bool validation = true;
    std::cin.exceptions(std::istream::failbit);
    // tkharej histograme taa kol mois
    do {
        try {
            //system("cls");
            header(path);
            std::cout << "1. Histogramme de revenue mensuel des factures par annee\n2. Somme des ventes\n3. Statistiques des clients\n\n0. Retour\n\n";
            std::cout << ">>>";
            std::cin >> r;
            system("cls");
            validation = r>=0 && r<=3; // menu tests
        }   
        catch (const std::exception& e) {
            validation = false;
            //cout << "PLEASE INSERT A VALID OPTION." << endl;
            std::cin.clear();
            std::string tmp;
            std::getline(std::cin, tmp);
        }
       
    } while (validation == false);

    return r;
}

int choixEmployerProduits(){
    int r;
    bool validation = true;
    std::cin.exceptions(std::istream::failbit);
    do {
        try {
            system("cls");
            header("Produits");
            std::cout << "1. Afficher\n2. Ajouter\n3. Modifier\n4. Supprimer\n\n0. Retour\n\n";
            std::cout << ">>>";
            std::cin >> r;
            system("cls");
            validation = (r>=0 && r<5); // menu tests
        }
        catch (const std::exception& e) {
            validation = false;
            //cout << "PLEASE INSERT A VALID OPTION." << endl;
            std::cin.clear();
            std::string tmp;
            std::getline(std::cin, tmp);
        }
       
    } while (validation == false);

    return r;
}

int choixEmployerCommandes(){
    int r;
    bool validation = true;
    std::cin.exceptions(std::istream::failbit);
    do {
        try {
            system("cls");
            header("Commandes");
            std::cout << "1. Archive des factures\n2. Nouvelle commande\n3. Supprimer commande\n\n0. Retour\n\n";
            std::cout << ">>>";
            std::cin >> r;
            system("cls");
            validation = (r>=0 && r<=3); // menu tests
        }
        catch (const std::exception& e) {
            validation = false;
            //cout << "PLEASE INSERT A VALID OPTION." << endl;
            std::cin.clear();
            std::string tmp;
            std::getline(std::cin, tmp);
        }
       
    } while (validation == false);

    return r;
}

void menuEmployerParametres(){
    int r = choixEmployerParametre();
    //"1. \n2. \n3. \n4. \n5. \n\n0. Retour\n\n";

    switch (r)
    {
    case 0:
        break;
    case 1:
        {
            header("Parametres\\Parametre du compte");
            pause();
        }
    break;
    case 2:
        {
            header("Parametres\\Ajouter un employer");
            pause();
        }
    break;
    case 3:
        {
            header("Parametres\\Supprimer un employer");
            pause();
        }
    break;
    case 4:
        {
            header("Parametres\\Definir les date de promotions");
            pause();
        }
    break;
    case 5:
        {
            header("Parametres\\Defenir la promotion sur la carte fidelite");
            pause();
        }
    break;
    default:
        break;
    }
}


void menuEmployerProduits(Container<Produit>& produits){
    int r = choixEmployerProduits();
    switch (r)
    {
    case 0:
        break;
    case 1:
        {
            header("Produits\\Afficher");
            std::cout << "\nNombre total des produits est: " << produits.taille() << ".\n";
            produits = LoadProduit();
            for (unsigned int i =0;i <produits.taille();i++){
                Produit p = produits[i];
                std::cout << p;
            }
            std::cout << ">>> ";
            system("PAUSE");           
        }
    break;
    case 2:
        {
            //oui non
            r = ouiNon("ajouter un nouveau produit","Produits\\Ajouter");
            if (r==1){
                header("Produits\\Ajouter");
                saveProductToFile(produits);
                break;
            }
            
            // do until confirmer
            header("Produits\\Ajouter");
            std::cout << ">>> ";
            system("PAUSE");
        }
    break;
    case 3:
        {
            r  = ouiNon("modifier un produit","Produits\\Modifier");
            if (r == 1){
                header("Produits\\Modifier");
                std::string id;
                std::cout << "Saisir l'id du produit a modifier.\n\n>>> ";
                std::cin >> id;
                if(produits.idintExist(id)){
                    header("Produits\\Modifier");
                    Produit p = produits.getByintId(id);
                    std::cout << p;
                    r  = ouiNon("modifier produit ID:  "+ id + " ","Produits\\Modifier",0);

                    if (r == 1){
                        do
                        {    
                            produits.modifier(id);
                            r = ouiNon("continuer a modifier le produit ID:  "+ id + " ","Produits\\Modifier",0);
                            Produit p = produits.getByintId(id);
                            std::cout << p;
                        } while (r==1);
                        
                        
                        
                        Fichier f("produits");
                        f.reset();
                        for (unsigned int i =0;i <produits.taille();i++){
                            Produit p = produits[i];
                            f.appendProduit(p);
                        }
                        std::cout << "Produit modifier avec succes.\n\n>>> ";
                        //header("Produits\\Ajouter");
                        system("PAUSE");
                    }
                    else {
                        std::cout << "\n\n>>> ";
                        system("PAUSE");
                        break;
                    }

                }else{
                    std::cout << "Id n'existe pas.\n\n>>> ";
                    system("PAUSE");
                    
                }

            }
        }
        break;  
    case 4:
        {
/*             header("suppr");
            system("PAUSE");    */  
            r  = ouiNon("supprimer un produit","Produits\\Supprimer");
            if (r == 1){
                header("Produits\\Supprimer");
                std::string id;
                std::cout << "Saisir l'id du produit a supprimer.\n\n>>> ";
                std::cin >> id;
                if(produits.idintExist(id)){

                    r  = ouiNon("supprimer produit ID:  "+ id + " ","Produits\\Supprimer");
                    Produit p = produits.getByintId(id);
                    std::cout << p;
                    
                    if (r == 1){
                    produits.supprimer(id);
                    Fichier f("produits");
                    f.reset();
                    for (unsigned int i =0;i <produits.taille();i++){
                        Produit p = produits[i];
                        f.appendProduit(p);
                    }
                    header("Produits\\Ajouter");
                    std::cout << "Produit supprimer avec succes.\n\n>>> ";
                    system("PAUSE");
                    }
                    else {
                        break;
                    }

                }else{
                    std::cout << "Id n'existe pas.\n\n>>> ";
                    system("PAUSE");
                    
                }

            }
        }
        break;
    default:
        break;
    }    
}

void menuEmployerCommande(Container<Produit> produits,Container<Facture>& factures){
    int r = choixEmployerCommandes();
    switch (r)
    {
    case 0:
        break;
    case 1:
        header("Commandes\\Archive des factures");
        std::cout << "Nombre de commandes total: " <<  factures.taille() <<  std::endl;
        for (unsigned int i = 0; i < factures.taille(); i++){
            Facture fact;
            fact = factures[i];
            std::cout << fact << "\n\n"; 
        }
        std::cout << ">>> ";
        system("PAUSE");
        break;
    case 2:
        header("Commandes\\Nouvelle Commande");
        saveFacture(factures,produits);
        std::cout << ">>> ";
        system("PAUSE");
        break;
    case 3:
        {
/*             header("suppr");
            system("PAUSE");    */  
            r  = ouiNon("supprimer une commande","Commandes\\Supprimer");
            if (r == 1){
                header("Commande\\Supprimer");
                std::string id;
                std::cout << "Saisir l'id du commande a supprimer.\n\n>>> ";
                std::cin >> id;
                Facture fact = factures.getBystrId(id);
                if (factures.idstrExist(id))
                {
                    header("Commandes\\Supprimer");
                    std::cout << fact;
                    r  = ouiNon("supprimer commande ID:  "+ id + " ","Commandes\\Supprimer",0);
                    Facture fact = factures.getBystrId(id);
                    std::cout << fact;
                    if (r == 1){
                        factures.supprimer(id);
                        Fichier f("facture");
                        f.reset();
                        for (unsigned int i =0;i <factures.taille();i++){
                            Facture fact = factures[i];
                            f.appendFacture(fact);
                            header("Commandes\\Ajouter");
                            std::cout << "Commande supprimer avec succes.\n\n>>> ";
                            system("PAUSE");
                        }
                    }else  break;

                }else{
                        std::cout << "Id n'existe pas.\n\n>>> ";
                        system("PAUSE");
                        break;
                }
            }
        }
        break;
    default:
        break;
    }
}


void menuGerantStatistique(Container<Facture> factures,Container<employer> employes,Container<client> clients){
    int r = choixGerantStatistique();
    switch (r)
    {
    case 0:
        /* code */
        break;
    case 1:
        {
            //histo
            //header("Statistique\\Histogramme de revenue mensuel des factures par annee");
            int annee = readInt("Statistique\\Histogramme de revenue mensuel des factures par annee","Saisir l'annee: ");
            statHistograme(factures,annee);
            std::cout << ">>> ";
            pause();
        }
        break;
    case 2:
        {
            header("Statistique\\Somme des ventes");
            statSommeVente(factures,employes);
            std::cout << ">>> "; 
            pause();
        }
    break;
    case 3:
        {
            header("Statistique\\Statistique des clients");
            statClients(clients);
            std::cout << ">>> "; 
            pause();
        }
    break;
    default:
        break;
    }
}