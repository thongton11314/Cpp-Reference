// add comments here
#ifndef _MEDIA_COLLECTION_
#define _MEDIA_COLLECTION_
#include <iostream>
#include "hashtable.h"
#include "media.h"

// add comments here
class MediaMovieCollection {
    friend ostream& operator<<(ostream&, const MediaMovieCollection&);
public:
    MediaMovieCollection();
    ~MediaMovieCollection();
    bool insertMovie(Media *movie);
    bool retrieveCustomer(const Media & target, Media* retriever);
private:
    Hashtable<int, Media> movieCollection;
};

#endif //!_MEDIA_COLLECTION_