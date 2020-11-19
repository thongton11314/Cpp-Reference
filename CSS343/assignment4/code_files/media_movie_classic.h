// add comments
// class movie type classis

#ifndef _CLASSIC_
#define _CLASSIC_
#include "media_movie.h"

class Classic : public Movie {

    friend ostream& operator<<(ostream &, const Classic &);
    
public:

    // constructor
    Classic();

    // copy constructor
    Classic(const Classic &classic);

    // deconstructor
    virtual ~Classic();

    // setter
    void setMonth(int month);
    virtual void setMajorActor(string name);

    // getter
    int getMonth() const;
    virtual string getMajorActor() const;
    virtual MovieType getMovieType() const;

    // comparison operators 
    virtual bool operator<(const Classic&) const;
    virtual bool operator<=(const Classic&) const;
    virtual bool operator>(const Classic&) const;
    virtual bool operator>=(const Classic&) const;
    virtual bool operator==(const Classic&) const;
    virtual bool operator!=(const Classic&) const;

private:
    string majorActor; 
    int month;
};
#endif //!_CLASSIC_