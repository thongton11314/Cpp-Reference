#ifndef _HASTABLE_
#define _HASTABLE_
#include <string>
#include "hashnode.h"

using namespace std;

// add comment here
template <typename Key, typename Val>
class Hashtable {
public:
    Hashtable();
    ~Hashtable();
    bool insertKeyValue(const int & key, Val * val);
    bool retrieveValue(const int & key, Val *& retriever) const;
    bool removeValue(const int & key);

private:
    HashNode<Key, Val> **table;                     // table
    int size;                                       // table size
    int numberToHashValue(const Key & keyHash);     // number to hash value
    int stringToHasValue(const string & keyHash);   // string to hash value
    void makeEmpty();                               // make the table empty
    // add more code here, use hash table
};

// implementation go down here here

#endif //!_HASTABLE_