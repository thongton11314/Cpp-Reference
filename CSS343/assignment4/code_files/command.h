#ifndef _COMMANDS_
#define _COMMANDS_
#include "customers_collection.h"
#include "media_collection.h"

// for specific command's type
enum CommandType{
    Borrow,
    Return,
    History,
    Inventory
};

// add comments here
class Command {

    // print out fulll command
    friend ostream& operator<<(ostream&, const Command&);

    public:

        // constructor
        Command();

        // copy constructor
        Command(const Command &);

        // deconstructor
        virtual ~Command();

        // setter
        void setCommandType(char);
        virtual bool setData(ifstream inFile);

        // getter
        int getCustomerId() const;
        CommandType getCommandType() const;

        // function
        // process
        virtual void process(MediaCollection&, CustomerCollection&);

    protected:
        CommandType type;
        string fullCommand;
        int customerID;

        virtual ostream& out(ostream &) const;
        // add more data if needed
};

#endif // !_COMMANDS_