// add comments here
#ifndef _MEDIA_COLLECTION_
#define _MEDIA_COLLECTION_
#include <iostream>
#include "media.h"
#include "bst.h"

// add comments here
class MediaCollection {
    friend ostream& operator<<(ostream&, const MediaCollection&);
public:
    MediaCollection();
    ~MediaCollection();
    bool insertMedia(Media * movie);
    bool retrieveMedia(const Media & target, Media *& retriever);
    const Media * getAMedia(const Media & target);
private:
    BSTree<Media*> collection;
};

#endif //!_MEDIA_COLLECTION_