#include "store_manager.h"

StoreManager::StoreManager() {}

StoreManager::~StoreManager() {}

void StoreManager::buildCustomers(ifstream &inFile) {
    // read until the end of file
        // add each customer CollectionCustomers.insert(customer)
        // if CollectionCustomers.insert(customer) return false
            // handling error here
}

void StoreManager::buildMovies(ifstream &inFile) {
    // read until the end of file
        // add each movie CollectionMovies.insert(movie)
        // if CollectionMovies.insert(movie)
            // handling error here
}

void StoreManager::processCommands(ifstream &inFile) {
    // read until the end of commands file, read line by line,
    // not need to store commands lines
        // create a new command: command = new Command;
        // set command data : command->setData(inFile)
        // command.processCommand(collectionMedias, collectionCustomers);
}