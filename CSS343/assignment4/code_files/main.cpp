#include <iostream>
#include "store_manager.h"

using namespace std;

int main () {

    // instantiate theater manager class
    StoreManager storeManager;

    // instantiate file stream for setting data
    ifstream customerFile("data4customers.txt"),  // customer file
             movieFile("data4movies.txt"),      // movies file
             commandFile("data4commands.txt");  // command file

    // reads all customers information from text file
    StoreManager.buildCustomers(customerFile);

    // reads all movies command from text file
    StoreManager.buildMovies(movieFile);

    // process all commands from file
    StoreManager.processCommands(commandFile);
    
    return 0;
}