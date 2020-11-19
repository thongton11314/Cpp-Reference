#include "media_movie_drama.h"

Drama::Drama() {
    this->stock = DEFAULT_STOCK;
    this->title = DEFAULT_TITLE;
    this->director = DEFAULT_PERSON;
    this->year = DEFAULT_NUM;
}

Drama::Drama(const Drama & other) {
    this->stock = other.stock;
    this->title = other.title;
    this->director = other.director;
    this->year = other.year;
}

Drama::~Drama() {

}

MovieType Drama::getMovieType() const {
    return MovieType::DramaType;
}

// need to be done
bool Drama::operator<(const Drama & other) const {
    return false;
}

// need to be done
bool Drama::operator<=(const Drama & other) const {
    return false;
}

// need to be done
bool Drama::operator>(const Drama & other) const {
    return false;
}

// need to be done
bool Drama::operator>=(const Drama & other) const {
    return false;
}

// need to be done
bool Drama::operator==(const Drama & other) const {
    return false;
}

bool Drama::operator!=(const Drama & other) const {
    return !(*this == other);
}

ostream & operator<<(ostream & out, const Drama & movie) {
    out << "Stock: " << movie.getStock() << ", "
        << "Director: " << movie.getDirector() << ", "
        << "Title: " << movie.getTitle() << ", "
        << "Year released: " << movie.getYear() << ". ";
    return out;
}