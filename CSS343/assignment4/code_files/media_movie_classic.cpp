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

Classic::~Classic() {

}

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

// need to be done
bool Classic::operator<(const Classic & other) const {
    return false;
}

// need to be done
bool Classic::operator<=(const Classic & other) const {
    return false;
}

// need to be done
bool Classic::operator>(const Classic & other) const {
    return false;
}

// need to be done
bool Classic::operator>=(const Classic & other) const {
    return false;
}

// need to be done
bool Classic::operator==(const Classic & other) const {
    return false;
}

bool Classic::operator!=(const Classic & other) const {
    return !(*this == other);
}

ostream & operator<<(ostream & out, const Classic & movie) {
    out << "Stock: " << movie.getStock() << ", "
        << "Director: " << movie.getDirector() << ", "
        << "Title: " << movie.getTitle() << ", "
        << "Major actor: " << movie.getMajorActor() << ", "
        << "Month: " << movie.getMonth() << ", "
        << "Year: " << movie.getYear() << ". ";
    return out;
}