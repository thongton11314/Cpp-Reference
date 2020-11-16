// add comments here
// parents class of movie class. This is pure virtual function
#ifndef _MEDIA_
#define _MEDIA_
#include <iostream>
#include <string>
using namespace std;

enum MediaType
{
    // current type
    DVDType // enum = 0

    // for future type go here
    // ...
};

class Media 
{
    // display client information
    virtual friend ostream& operator<<(ostream &, const Media&) = 0;

public :

    // deconstructor, for late binding
	virtual ~Media();

    // setter
    virtual void setStock(int stock);
	
    // getter
    virtual int getStock() const;

    // function
    virtual void increaseStock(int add);
    virtual void decreaseStock();
    
    // pure virtual function
    virtual MediaType getMediaType() const = 0;

protected:
    int stock;
};
#endif //!_MEDIA_