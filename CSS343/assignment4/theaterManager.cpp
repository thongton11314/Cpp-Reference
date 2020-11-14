#include "theaterManager.h"

TheaterManager::TheaterManager() {}

TheaterManager::~TheaterManager() {}

TheaterManager::buildClientsFromFile(ifstream &inFile) {
    // read until the end of file
        // add each client command.addClient(*client)
        // if command.addClient(client) return false
            // add error client, command.addErrorClient(*client)
}

TheaterManager::buildMoviesFromFile(ifstream &inFile) {
    // read until the end of file
        // add each movie command.addMovie(movie)
        // if command.addMovie(movie) return false
            // add error movie, command.addErrorMovie(movie)
}

TheaterManager::processCommandsFromFile(ifstream &inFile) {
    // read until the end of file
        // add each command command.addMovie(movie)
        // if command.addMovie(movie) return false
            // add error movie, command.addErrorMovie(movie)
}

TheaterManager::report() {
    // report error
        // read error from commands
    // report history
        // read history commands.displayHistory()
}