#ifndef _CUSTOMER_
#define _CUSTOMER_
#include <iostream>
#include <string>
#include <vector>
#include "bst.h"
#include "media.h"
#include "history.h"
using namespace std;

const int MINID = 1;                    // smallest id
const int MAXID = 9999;                 // highest id

// add comments
class Customer {

    // display client information
    friend ostream& operator<<(ostream &, const Customer&);

    public:
        Customer();
        Customer(const Customer &customer);
        ~Customer();

        // setter
        bool setData(ifstream&);            // fill object with data from file
        
        // getter
        int getId() const;                  // get customer ID
        std::string getLastName() const;    // get customer last name
        std::string getFirstName() const;   // get customer first name
        const void getHistory() const;

        // function
        void borrowMedia(Media * media);
        void returnMedia(const Media * targetMedia);

    private:
    int customerID;                    // client ID
    string firstName;                  // client first name
    string lastName;                   // client last name
    //vector<> history;           // hold customer history commands
    BST<Media*> currentMediaBorrow;    // hold all current media is being borrow
};
#endif // !_CUSTOMER_
