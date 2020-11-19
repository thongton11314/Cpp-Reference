#include <iostream>
#include "store_manager.h"

using namespace std;

Customer testCustomer(ifstream);

int main () {

    /*
    // instantiate theater manager class
    StoreManager storeManager;

    // instantiate file stream for setting data
    ifstream customerFile("data4customers.txt"),  // customer file
             movieFile("data4movies.txt"),        // movies file
             commandFile("data4commands.txt");    // command file

    // reads all customers information from text file
    storeManager.buildCustomers(customerFile);

    // reads all movies command from text file
    storeManager.buildMovies(movieFile);

    // process all commands from file
    storeManager.processCommands(commandFile);
    
    return 0;
    */
    ifstream customerFile("data4customers.txt");
    testCustomer(ifstream);
}

Customer testCustomer(ifstream infile) {

    // early exit, and show error message that can not be read
    if (!infile) {
        cout << "Could not read client file" << endl;
        return;
    }
    
    Customer* ptr;
    bool checkData;                       // used for reading good data
    while (!infile.eof()) {
        ptr = new Customer;                 // create new client object
        
        // must have setData implementation of client
        checkData = ptr->setData(infile); // fill the client object
        
        // add valid client
        if (checkData) {
            cout << *ptr << endl;
        }
        
        // ignore invalid client
        else {
            delete ptr;
        }
    }   
}