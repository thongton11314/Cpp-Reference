#ifndef _CUSTOMER_
#define _CUSTOMER_
#include <iostream>
#include <string>
#include <vector>
#include "media.h"

using namespace std;

class Commands;

const int MINID = 1;                    // smallest id
const int MAXID = 9999;                 // highest id

// add comments
class Customer {

    // display customer information
    friend ostream& operator<<(ostream &, const Customer&);

    public:

        // constructor
        Customer();

        // copy constructor
        Customer(const Customer &customer);

        // deconstructor
        ~Customer();

        // setter
        bool setData(ifstream&);        // fill object with data from file
        
        // getter
        int getId() const;              // get customer ID
        string getLastName() const;     // get customer last name
        string getFirstName() const;    // get customer first name
        vector<Commands *> getHistory();// get custoer history

        // function
        bool borrowMedia(Media * media);
        bool returnMedia(Media * media);

    private:
    int customerID;                     // customer ID
    string firstName;                   // customer first name
    string lastName;                    // customer last name
    vector<Commands *> history;         // customer history commands
	vector<Media *> borrowed;           // customer media borrow currently
};
#endif // !_CUSTOMER_
