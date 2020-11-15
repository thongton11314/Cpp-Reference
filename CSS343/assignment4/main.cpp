#include <iostream>
#include "theaterManager.h"

using namespace std;

int main () {

    // instantiate theater manager class
    TheaterManager theaterManager;

    // instantiate file stream for setting data
    ifstream customerFile("data4customers.txt"),  // customer file
             movieFile("data4movies.txt"),      // movies file
             commandFile("data4commands.txt");  // command file

    // reads all customers information from text file
    theaterManager.buildCustomersFromFile(customerFile);

    // reads all movies command from text file
    theaterManager.buildMoviesFromFile(movieFile);

    // process all commands from file
    theaterManager.processCommandsFromFile(commandFile);
    
    // display customer history, commands, or error message
    theaterManager.report();

    return 0;
}