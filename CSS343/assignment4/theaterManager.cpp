#include "theaterManager.h"

TheaterManager::TheaterManager() {}

TheaterManager::~TheaterManager() {}

void TheaterManager::buildCustomersFromFile(ifstream &inFile) {

    // read until the end of file
        // add each customer CollectionCustomers.insert(customer)
        // if CollectionCustomers.insert(customer) return false
            // handling error here, add error customer in error collection

void TheaterManager::buildMoviesFromFile(ifstream &inFile) {
    // read until the end of file
        // add each movie CollectionMovies.insert(movie)
        // if CollectionMovies.insert(movie)
            // handling error here, add error movie in error collection
}

void TheaterManager::processCommandsFromFile(ifstream &inFile) {

    // read until the end of file
        // if B borrow movie: commands.borrowMovie(collectionMovie, movie)
            // if return false, handle here
        // if R return movie: commands.returnMovie(CollectionMovie, movie)
            // if return false, handle here
        // if I inventory: commands.getInventory()
        // if H history (display specific customer)
}

void TheaterManager::report() const {

    // display error
    // get customer's error
    // get movie's error

    // display inventory
    // get all movies
    
    // print all of the movies
}