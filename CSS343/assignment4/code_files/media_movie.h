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
    virtual void setDirector(string director);
    virtual void setTitle(string title);
    virtual void setYear(int year);

    // getter
    virtual string getDirector() const;
    virtual string getTitle() const; 
    virtual int getYear() const;   
    
    // pure virtual function
    virtual MovieType getMovieType() const = 0;
    virtual MediaType getMediaType() const;

protected:
    string director;
    string title;
    int year;
};

#endif // !_MOVIE_
