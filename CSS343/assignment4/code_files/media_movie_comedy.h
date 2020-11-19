// add comments
// class movie type comedy

#ifndef _COMEDY_
#define _COMEDY_
#include "media_movie.h"

class Comedy : public Movie {

    friend ostream& operator<<(ostream &, const Comedy &);

public:

    // constructor
    Comedy();

    // copy constructor
    Comedy(const Comedy & other);

    // deconstructor
    virtual ~Comedy();

    // getter
    virtual MovieType getMovieType() const;

    // comparison operators
    virtual bool operator<(const Comedy&) const;
    virtual bool operator<=(const Comedy&) const;
    virtual bool operator>(const Comedy&) const;
    virtual bool operator>=(const Comedy&) const;
    virtual bool operator==(const Comedy&) const;
    virtual bool operator!=(const Comedy&) const;
};

#endif //!_CLASSIC_