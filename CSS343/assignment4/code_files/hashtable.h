// hashtable must be implement by developer. For the collision, can use library data stucture.

#ifndef _HASTABLE_
#define _HASTABLE_
#include <string>

using namespace std;

const int TABLE_SIZE = 97; // better with prime number

// add comment here
template <typename Key, typename Val>
class Hashtable {
public:
    Hashtable();
    Hashtable(const Hashtable & other);
    ~Hashtable();
    bool insertKeyValue(const Key & key, Val * val);
    bool retrieveValue(const Key & key, Val *& retriever) const;
    const Val * getValue(const Key & key);
    bool removeValue(const Key & key);

private:

    struct HashNode {
        Key key;
        Val * value;
        HashNode* next;
    };

    HashNode * table[TABLE_SIZE];
    int numberToHashValue(const Key & keyHash);     // number to hash value
    int stringToHashValue(const string & keyHash);  // string to hash value
    void makeEmpty();                               // make the table empty
    // add more code here, use hash table
};

// implementation is bellow

template <typename Key, typename Val>
Hashtable<Key, Val>::Hashtable() {
    
}

template <typename Key, typename Val>
Hashtable<Key, Val>::Hashtable(const Hashtable & other) {
    
}

template <typename Key, typename Val>
Hashtable<Key, Val>::~Hashtable() {
    makeEmpty();
}

template <typename Key, typename Val>
bool Hashtable<Key, Val>::insertKeyValue(const Key & key, Val * val) {
    return false;
}

template <typename Key, typename Val>
bool Hashtable<Key, Val>::retrieveValue(const Key & key, Val *& retriever) const {
    return false;
}

template <typename Key, typename Val>
const Val * Hashtable<Key, Val>::getValue(const Key & key) {
    return nullptr;
}

template <typename Key, typename Val>
bool Hashtable<Key, Val>::removeValue(const Key & key) {
    return false;
}

template <typename Key, typename Val>
int Hashtable<Key, Val>::numberToHashValue(const Key & keyHash) {
    return NULL;
}

template <typename Key, typename Val>
int Hashtable<Key, Val>::stringToHashValue(const string & keyHash) {
    return NULL;
}

template <typename Key, typename Val>
void Hashtable<Key, Val>::makeEmpty() {}

#endif //!_HASTABLE_