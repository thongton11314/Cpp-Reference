// add comments here
// parents class of movie class. This is pure virtual function
#ifndef _MEDIA_
#define _MEDIA_
#include <iostream>
#include <string>

using namespace std;

// for specific media's type
enum MediaType
{
    // current type
    DVDType

    // for future type go here
    // ...
};

// for specific movie's type
enum MovieType {

    // current type
    ComedyType,     // enum = 0
    DramaType,      // enum = 1
    ClassicalType   // enum = 2
    
    // for future type go here
    // ...
};

class Media 
{
    // display client information
    friend ostream& operator<<(ostream &, const Media &);

public :

    // deconstructor, for late binding
	virtual ~Media();

    // setter
    virtual void setStock(int stock);
	
    // getter
    virtual int getStock() const;

    // function
    virtual void addStock(int add);
    virtual void reduceStock(int reduce);
    
    // pure virtual function
    virtual MediaType getMediaType() const = 0;

protected:
    int stock;
    virtual ostream& out(ostream &, const Media &);
};

//#include "media_movie.h"
//#include "media_movie_classic.h"
//#include "media_movie_comedy.h"
//#include "media_movie_drama.h"

#endif //!_MEDIA_