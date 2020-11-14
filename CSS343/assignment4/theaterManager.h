#ifndef _THEATER_MANAGER_
#define _THEATER_MANAGER_
#include <fstream>
#include <iostream>
#include "commands.h"

using namespace std;

class TheaterManager {
    public:
        TheaterManager();   // constructor
        ~TheaterManager();  // destructor 

        // reads all clients information from text file
        void buildClientsFromFile(ifstream &inFile);

        // reads all movies command from text file
        void buildMoviesFromFile(ifstream &inFile);

        // process all commands from file
        void processCommandsFromFile(ifstream &inFile);

        // display client history, commands, or error message
        void report();
    private:
        Command commands;
};

#endif // !THEATER_MANAGER