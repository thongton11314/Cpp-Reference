#ifndef _MEDIA_MOVIE_FACTORY_
#define _MEDIA_MOVIE_FACTORY_

#include "media_movie.h"

class MovieFactory {
public:
    static Movie * createMovie(ifstream);
private:
    static Movie * createMovieComedy(ifstream);
    static Movie * createMovieDrama(ifstream);
    static Movie * createMovieClassic(ifstream);
};

#endif //!_MEDIA_MOVIE_FACTORY_