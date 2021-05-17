Container<client> client::LoadClients(){
    Fichier f("clients");
    Container<std::string> c ;
    c=f.fillContainer();

    Container<client> clients;
    for (unsigned int i = 0; i < c.taille(); i++ ){
        clients.ajouter(client(c[i],1));
    }
    return clients;
}