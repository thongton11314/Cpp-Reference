#ifndef _COMMANDS_
#define _COMMANDS_
#include <iostream>
#include <fstream>
#include "collectionCustomers.h"
#include "collectionMovies.h"
#include <vector>

using namespace std;

// Class Command
// Description:
//  - This class will perfom abitrary commands, handle error
// Implementation and assumption:
//  - When add new customer, insert in hash table for faster look up
//    - Customers have a 4-digit ID number, 
//      followed by last name, first name, 
//      separated by a space
//  - When add new movie:
//    - Each item is uniquely identified by its complete set of sorting attributes
//    - Comedy movies (‘F’) sorted by Title, then Year it release
//    - Dramas (‘D’) are sorted by Director, then Title
//    - Classics (‘C’) are sorted by Release date, then Major actor
//  - When add new command
//    - The first field is action type (B, R, I, or H)
//    - Action types I:no more fields
//    - Action type H:one more field customer ID. Fields are separated by a space
//    - Action types B and R: customer ID followed 
//      by type of media (currently only ‘D’ for DVD) 
//      then movie type and movie data
class Command {
    public:
        Command();
        ~Command();

        // stock - 1 for each item borrowed
        bool borrowMovie(const Movie *);

        // stock + 1 for each item returned
        bool returnMovie(const Movie *);

        // handle customer error
        void addcustomerError(const Customer *);

        // handle movie error
        void addMovieError(const Movie *);
        
    private:
        // add more data if needed
};

#endif // !_COMMANDS_