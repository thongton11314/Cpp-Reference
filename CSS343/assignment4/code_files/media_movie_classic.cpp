#include "media_movie_classic.h"

Classic::Classic() {
    this->stock = DEFAULT_STOCK;
    this->title = DEFAULT_TITLE;
    this->director = DEFAULT_PERSON;
    this->majorActor = DEFAULT_PERSON;
    this->month =  DEFAULT_NUM;
    this->year = DEFAULT_NUM;
}

Classic::Classic(const Classic & other) {
    this->stock = other.stock;
    this->title = other.title;
    this->director = other.director;
    this->majorActor = other.majorActor;
    this->month = other.month;
    this->year = other.year;
}

Classic::~Classic() {}

void Classic::setMajorActor(string name) {
    this->majorActor = name;
}

void Classic::setMonth(int month) {
    this->month = month;
}

int Classic::getMonth() const {
    return this->month;
}

string Classic::getMajorActor() const {
    return this->majorActor;
}

MovieType Classic::getMovieType() const {
    return MovieType::ClassicalType;
}

bool Classic::operator<(const Classic & other) const {
    if (this->getDirector().compare(other.getDirector()) != 0)
		return this->getDirector().compare(other.getDirector()) < 0;
	
	if (this->getTitle().compare(other.getTitle()) != 0)
		return this->getTitle().compare(other.getTitle()) < 0;	

	return this->getYear() < other.getYear();
}

// need to fix
bool Classic::operator<=(const Classic & other) const {
    if (this->getDirector().compare(other.getDirector()) > 0)
        return false;

	if (this->getTitle().compare(other.getTitle()) > 0)
        return false;
        
	return this->getYear() <= other.getYear();
}

bool Classic::operator>(const Classic & other) const {
    if (this->getDirector().compare(other.getDirector()) != 0)
		return this->getDirector().compare(other.getDirector()) > 0;
	
	if (this->getTitle().compare(other.getTitle()) != 0)
		return this->getTitle().compare(other.getTitle()) > 0;	

	return this->getYear() > other.getYear();
}

bool Classic::operator>=(const Classic & other) const {
    if (this->getDirector().compare(other.getDirector()) < 0)
        return false;

	if (this->getTitle().compare(other.getTitle()) < 0)
        return false;

	return this->getYear() >= other.getYear();
}

bool Classic::operator==(const Classic & other) const {
    if ((this->getDirector().compare(other.getDirector()) == 0)
        && (this->getTitle().compare(other.getTitle()) == 0)
        && (this->getYear() == other.getYear()))
        return true;
    return false;
}

bool Classic::operator!=(const Classic & other) const {
    return !(*this == other);
}

ostream & operator<<(ostream & out, const Classic & movie) {
    out << "Stock: " << movie.stock << ", "
        << "Director: " << movie.director << ", "
        << "Title: " << movie.title << ", "
        << "Major actor: " << movie.majorActor << ", "
        << "Month: " << movie.month << ", "
        << "Year: " << movie.year << ". ";
    return out;
}