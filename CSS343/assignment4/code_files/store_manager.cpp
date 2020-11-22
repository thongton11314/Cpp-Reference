#include "store_manager.h"

StoreManager::StoreManager() {}

StoreManager::~StoreManager() {}

void StoreManager::buildCustomers(ifstream & infile) {
    // read until the end of file
        // create a customer object, set object data customer->setData(infile)
        // add each customer CollectionCustomers.insert(customer)
        // if CollectionCustomers.insert(customer) return false
            // handling error here

    // early exit, and show error message that can not be read
    if (!infile) {
        cout << "Could not read customer file" << endl;
        return;
    }
    
    Customer* ptr;
    bool checkData;                         // used for reading good data
    while (!infile.eof()) {
        ptr = new Customer();                 // create new client object
        
        // must have setData implementation of client
        checkData = ptr->setData(infile); // fill the client object
        
        // add valid client
        if (checkData) {
            cout << *ptr << endl;
            delete ptr;
        }
        
        // ignore invalid client
        else {
            delete ptr;
        }
    }
}

void StoreManager::buildMovies(ifstream & infile) {
    // read until the end of file
        // create a movie object by MediaFactory::createDVDMovie(infile)
        // add each movie CollectionMovies.insert(movie)
        // if CollectionMovies.insert(movie)
            // handling error here

    
    if (!infile) {
        cout << "Could not read Movies file" << endl;
        return;
    }
    
    Media* ptr;
    while (!infile.eof()) {
        ptr = MediaFactory::createDVDMovie(infile); // create new client object
        if(ptr != nullptr) {
            cout << *dynamic_cast<Movie*>(ptr) << endl;
            delete ptr;
        }
    }
    // if not null, add to collection
    
   //Media* ptr = MediaFactory::createDVDMovie(infile);
}

void StoreManager::processCommands(ifstream &infile) {
    // read until the end of commands file
    // not need to store commands lines
        // create a command object by CommandFactory::createCommand(infile)
        // process commannd
            // command.processCommand(collectionMedias, collectionCustomers)
}