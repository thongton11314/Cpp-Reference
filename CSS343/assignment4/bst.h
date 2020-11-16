#ifndef _COLLECTION_MOVIES_
#define _COLLECTION_MOVIES_
#include "media.h"

// add comment here
template<typename T >
class BST {
    public:
        CollectionMovies();
        ~CollectionMovies();
        bool insert(T *);
        bool retrieve(const T&, T*&) const;
        void display() const;
        void makeEmpty();
        bool isEmpty() const;
    private:
    // add more code here
};

#endif // !COLLECTION_MOVIES