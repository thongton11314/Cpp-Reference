#ifndef _MEDIA_MOVIE_FACTORY_
#define _MEDIA_MOVIE_FACTORY_
#include "media_movie.h"

class MovieFactory {
public:
    static Movie * createMovie(ifstream & infile);
private:
    static Movie * createMovieComedy(ifstream & infile);
    static Movie * createMovieDrama(ifstream & infile);
    static Movie * createMovieClassic(ifstream & infile);
    // futher movie type add here
};

#endif //!_MEDIA_MOVIE_FACTORY_