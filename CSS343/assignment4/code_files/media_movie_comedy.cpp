#include "media_movie_comedy.h"

Comedy() {

}

Comedy(const Comedy & comedy) {

}

~Comedy() {

}

MovieType Comedy::getMovieType() const {
    return MovieType::Comedy;
}

bool Comedy::operator<(const Comedy & other) const {

}

bool Comedy::operator<=(const Comedy & other) const {
    
}

bool Comedy::operator>(const Comedy & other) const {
    
}

bool Comedy::operator>=(const Comedy & other) const {

}

bool Comedy::operator==(const Comedy & other) const {

}

bool Comedy::operator!=(const Comedy & other) const {

}

ostream& Comedy::operator<<(ostream & out, const Comedy & movie) {
    out << movie.out << ", type: Comedy";
}