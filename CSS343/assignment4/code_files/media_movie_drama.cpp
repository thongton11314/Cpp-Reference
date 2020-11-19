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

Drama::~Drama() {}

MovieType Drama::getMovieType() const {
    return MovieType::DramaType;
}

bool Drama::operator<(const Drama & other) const {
    if (this->getDirector().compare(other.getDirector()) != 0)
		return this->getDirector().compare(other.getDirector()) < 0;
	
	if (this->getTitle().compare(other.getTitle()) != 0)
		return this->getTitle().compare(other.getTitle()) < 0;	

	return this->getYear() < other.getYear();
}

// need to be fix
bool Drama::operator<=(const Drama & other) const {
    if (this->getDirector().compare(other.getDirector()) > 0)
        return false;

	if (this->getTitle().compare(other.getTitle()) > 0)
        return false;
        
	return this->getYear() <= other.getYear();
}

bool Drama::operator>(const Drama & other) const {
    if (this->getDirector().compare(other.getDirector()) != 0)
		return this->getDirector().compare(other.getDirector()) > 0;
	
	if (this->getTitle().compare(other.getTitle()) != 0)
		return this->getTitle().compare(other.getTitle()) > 0;	

	return this->getYear() > other.getYear();
}

bool Drama::operator>=(const Drama & other) const {
    if (this->getDirector().compare(other.getDirector()) < 0)
        return false;

	if (this->getTitle().compare(other.getTitle()) < 0)
        return false;

	return this->getYear() >= other.getYear();
}

bool Drama::operator==(const Drama & other) const { 
    if ((this->getDirector().compare(other.getDirector()) == 0)
        && (this->getTitle().compare(other.getTitle()) == 0)
        && (this->getYear() == other.getYear()))
        return true;
    return false;
}

bool Drama::operator!=(const Drama & other) const {
    return !(*this == other);
}

ostream & operator<<(ostream & out, const Drama & movie) {
    out << "Stock: " << movie.stock << ", "
        << "Director: " << movie.director << ", "
        << "Title: " << movie.title << ", "
        << "Year released: " << movie.year << ". ";
    return out;
}