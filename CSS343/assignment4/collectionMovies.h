#ifndef _COLLECTION_MOVIES_
#define _COLLECTION_MOVIES_
#include "movie.h"

// add comment here
class CollectionMovies {
    public:
        CollectionMovies();
        ~CollectionMovies();
        bool insert(Movie *);
        bool retrieve(const Movie&, Movie*&) const;
        void display() const;
        void makeEmpty();
        bool isEmpty() const;
    private:
    // add more code here
};

#endif // !COLLECTION_MOVIES