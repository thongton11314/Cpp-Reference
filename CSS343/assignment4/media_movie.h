// add comments here
// parents class of comedy, drama, classical class. This is pure virtual function
// this class function will hold commonds function for inherited class which are classic, comedy, drama

#ifndef _MOVIE_
#define _MOVIE_
#include "media.h"

// add comments here
class Movie : public Media {

    friend ostream& operator<<(ostream &, const Movie &);
    
public:

    // destructor, for late biding
    virtual ~Movie();
    
    // setter
    virtual void setDirector(const string & director);
    virtual void setTitle(const string & title);
    virtual void setYear(int year);

    // getter
    virtual const string & getDirector() const;
    virtual const string & getTitle() const; 
    virtual int getYear() const;   
    
    // pure virtual function
    virtual MovieType getMovieType() const = 0;
    virtual MediaType getMediaType() const;

protected:
    string director;
    string title;
    int year;

    // overload ostream
    virtual ostream& outout(ostream &) const = 0;
};

#endif // !_MOVIE_
