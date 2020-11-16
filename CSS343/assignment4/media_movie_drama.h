// add comments
// class movie type drama

#ifndef _DRAMA_
#define _DRAMA_
#include "media_movie.h"

class Drama : public Movie {
    virtual friend ostream& operator<<(std::ostream &, const Drama &);
public:

    // constructor
    Drama();

    // copy constructor
    Drama(const Comedy &drama);

    // deconstructor
    virtual ~Drama();

    // getter
    virtual MovieType getMovieType() const;

    // comparison operators
    virtual bool operator<(const Drama&) const;
    virtual bool operator<=(const Drama&) const;
    virtual bool operator>(const Drama&) const;
    virtual bool operator>=(const Drama&) const;
    virtual bool operator==(const Drama&) const;
    virtual bool operator!=(const Drama&) const;
};
#endif //!_DRAMA_