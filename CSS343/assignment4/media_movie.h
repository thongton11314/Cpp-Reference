// add comments here
// parents class of comedy, drama, classical class. This is pure virtual function
// this class function will hold commonds function for inherited class which are classic, comedy, drama

#ifndef _MOVIE_
#define _MOVIE_
#include "media.h"

enum MovieType {

    // current type
    ComedyType,     // enum = 0
    DramaType,      // enum = 1
    ClassicalType   // enum = 2
    
    // for future type go here
    // ...
};

// add comments here
class Movie : public Media {
    
public:

    // destructor, for late biding
    virtual ~Movie();
    
    // setter
    virtual void setDirector(const string & director);
    virtual void setTitle(const string & title);
    virtual void setYear(int year);

    // getter
    virtual const std::string & getDirector() const;
    virtual const std::string & getTitle() const; 
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
