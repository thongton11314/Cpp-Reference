// add comments
// class movie type drama

#ifndef _DRAMA_
#define _DRAMA_
#include "media_movie.h"

class Drama : public Movie {

    friend ostream& operator<<(ostream &, const Drama &);
    
public:

    // constructor
    Drama();

    // copy constructor
    Drama(const Drama &drama);

    // set data
    bool setData(ifstream & infile);

    // deconstructor
    virtual ~Drama();

    // getter
    virtual char getMovieType() const;
    void print(ostream & out) const;

    // comparison operators
    virtual bool operator<(const Drama&) const;
    virtual bool operator<=(const Drama&) const;
    virtual bool operator>(const Drama&) const;
    virtual bool operator>=(const Drama&) const;
    virtual bool operator==(const Drama&) const;
    virtual bool operator!=(const Drama&) const;
};
#endif //!_DRAMA_