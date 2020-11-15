#ifndef _COLLECTION_customers_
#define _COLLECTION_customers_
#include "customer.h"

// add comment here
class CollectionCustomers {
    public:
        CollectionCustomers();
        ~CollectionCustomers();
        bool insert(Customer * newCustomer);
        bool retrieve(const Customer & target, Customer *& retriever) const;
        void display() const;
        void makeEmpty();
        bool isEmpty() const;
    private:
    // add more code here, use hash table
};

#endif // !COLLECTION_MOVIES