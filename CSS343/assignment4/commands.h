#ifndef _COMMANDS_
#define _COMMANDS_
#include <iostream>
#include <fstream>
#include "collectionClients.h"
#include "collectionMovies.h"
#include "errorHandling.h"

class Command {
    public:
        Command();
        ~Command();

        // add client
        bool addClient();

        // add movies
        bool addMovie();

        // stock - 1 for each item borrowed
        bool borrowMovie();

        // stock + 1 for each item returned
        bool returnMovie();

        // outputs the inventory of all the items inthe store
        void inventory();

        // outputs all the transactions of a customer
        void displayHistory();

        // handle error client from command
        void errorClientType();

        // handle error movies from command
        void errorMovieType();
        
    private:
        CollectionClients clients;
        CollectionMovies movies;
        ErrorHandling errors;
};

#endif // !_COMMANDS_