#include "media_factory.h"

Media * MediaFactory::createMedia(ifstream & infile) {
    // create movie so far
    return createDVDMovie(infile);
    
    // further type add here
}

Media * MediaFactory::createDVDMovie(ifstream & infile) {
    return MovieFactory::createMovie(infile);
}