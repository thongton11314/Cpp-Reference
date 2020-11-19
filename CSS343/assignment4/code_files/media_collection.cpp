#include "media_collection.h"

MediaCollection::MediaCollection() {}

MediaCollection::~MediaCollection() {}

bool MediaCollection::insertMedia(Media *movie) {
    return false; 
}

bool MediaCollection::retrieveMedia(const Media & target, Media *& retriever) {
    return false;
}

const Media * getAMedia(const Media & target) {
    return nullptr;
}

ostream& operator<<(ostream& out, const MediaCollection& collection) {
    return out;
}