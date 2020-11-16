// add comments here
#ifndef _MEDIA_COLLECTION_
#define _MEDIA_COLLECTION_
#include "media.h"
#include "bst.h"

// add comments here
class MediaMovieCollection {
    friend ostream& operator<<(ostream&, const MediaMovieCollection&);
public:
    MediaMovieCollection();
    ~MediaMovieCollection();
    bool insertMovie(Movie *movie);
    bool retrieveCustomer(const Movie & target, Movie* retriever);
private:
    BST<Media> collection;
};

#endfid //!_MEDIA_COLLECTION_