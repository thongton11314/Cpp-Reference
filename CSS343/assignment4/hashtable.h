#ifndef _HASTABLE_
#define _HASTABLE_
#include "hashnode.h"
#include <string>

using namespace std;

const int SIZE_TABLE = 100;

// add comment here
template <typename Key, typename Val>
class Hashtable {

public:
    Hastable();
    ~Hastable();
    bool insertKeyValue(const int & key, T * val);
    bool retrieveValue(const int & key, T *& retriever) const;
    bool removeValue(const int & key);

private:
    HashNode<Key, Val> * table;                     // table
    int numberToHashValue(const Key & keyHash);     // number to hash value
    int stringToHasValue(const string & keyHash);   // string to hash value
    void makeEmpty();                               // make the table empty
    // add more code here, use hash table
};

// add implementation here

#endif //!_HASTABLE_