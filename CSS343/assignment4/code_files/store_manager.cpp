#include "store_manager.h"

StoreManager::StoreManager() {}

StoreManager::~StoreManager() {}

void StoreManager::buildCustomers(ifstream &infile) {
    // read until the end of file
        // create a customer object, set object data customer->setData(infile)
        // add each customer CollectionCustomers.insert(customer)
        // if CollectionCustomers.insert(customer) return false
            // handling error here
    // close file
}

void StoreManager::buildMovies(ifstream &infile) {
    // read until the end of file
        // create a movie object by MediaFactory::createDVDMovie(infile)
        // add each movie CollectionMovies.insert(movie)
        // if CollectionMovies.insert(movie)
            // handling error here
    // close file
}

void StoreManager::processCommands(ifstream &infile) {
    // read until the end of commands file
    // not need to store commands lines
        // create a command object by CommandFactory::createCommand(infile)
        // process commannd
            // command.processCommand(collectionMedias, collectionCustomers)
    // close file
}