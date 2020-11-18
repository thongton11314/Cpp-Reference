#ifndef _HASTABLE_
#define _HASTABLE_
#include <string>

using namespace std;

const int TABLE_SIZE = 69;

// add comment here
template <typename Key, typename Val>
class Hashtable {
public:
    Hashtable();
    ~Hashtable();
    bool insertKeyValue(const Key & key, Val * val);
    bool retrieveValue(const Key & key, Val *& retriever) const;
    const Val * getValue(const Key & key) const;
    bool removeValue(const Key & key);

private:

    struct HashNode {
        Key key;
        Val * value;
        HashNode* next;
    }

    HashNode *table;                                // table
    int size;                                       // table size
    int numberToHashValue(const Key & keyHash);     // number to hash value
    int stringToHashValue(const string & keyHash);  // string to hash value
    void makeEmpty();                               // make the table empty
    // add more code here, use hash table
};

// implementation go down here here

#endif //!_HASTABLE_