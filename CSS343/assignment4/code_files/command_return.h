// add comments here

#ifndef _COMMAND_RETURN_
#define _COMMAND_RETURN_
#include "command.h"

// add comments here
class Return : public Command {

    // print out full command
    friend ostream& operator<<(ostream&, const Return&);

public:
    Return();
    ~Return();

    // setter
    // initialize data
    bool setData(ifstream inFile);

    // getter
    const MediaType getMediaType() const;
    const MovieType getMovieType() const;

    // function
    void process(MediaCollection&, CustomerCollection&);
    bool procesReturn(Media*, Customer*); // part of process function

private:
    MediaType mediaType;
    MovieType movieType;
    virtual ostream& out(ostream &) const;
};

#endif //!_COMMAND_RETURN_