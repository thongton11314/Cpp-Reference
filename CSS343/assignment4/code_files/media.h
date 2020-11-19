// add comments here
// parents class of movie class. This is pure virtual function
#ifndef _MEDIA_
#define _MEDIA_
#include <iostream>
#include <string>

using namespace std;

const int DEFAULT_STOCK = 0;
const string DEFAULT_TITLE = "DEFAULT";
const string DEFAULT_PERSON = "DEFAULT";
const int DEFAULT_NUM = 0;

// for specific media's type
enum MediaType
{
    // current type
    DVDMovieType

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
    // display media information
    friend ostream& operator<<(ostream &, const Media &);

public :

    // deconstructor, for late binding
	virtual ~Media();

    // setter
    virtual void setStock(unsigned int amount);
	
    // getter
    virtual int getStock() const;

    // function
    virtual void addStock(unsigned int amount);
    virtual bool reduceStock(int amount);
    
    // pure virtual function
    virtual MediaType getMediaType() const = 0;

protected:
    int stock;
};

#endif //!_MEDIA_