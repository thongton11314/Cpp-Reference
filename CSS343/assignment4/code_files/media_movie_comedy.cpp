#include "media_movie_comedy.h"

Comedy::Comedy() {
    this->stock = DEFAULT_STOCK;
    this->title = DEFAULT_TITLE;
    this->director = DEFAULT_PERSON;
    this->year = DEFAULT_NUM;
}

bool Comedy::setData(ifstream & infile) {

    // set up stock
    infile.ignore();
    infile >> this->stock;

    // set up director
    infile.ignore();
    getline(infile >> ws, this->director, ',');

    // set up title
    infile.ignore();
    getline(infile >> ws, this->title, ',');

    // set up year
    infile.ignore();
    string strToYear;
    getline(infile >> ws, strToYear, '\n'); // end of line
    stringstream ss;
    ss << strToYear;
    ss >> this->year;

    return true;
}

Comedy::Comedy(const Comedy & other) {
    this->stock = other.stock;
    this->title = other.title;
    this->director = other.director;
    this->year = other.year;
}

Comedy::~Comedy() {}

char Comedy::getMovieType() const {
    return 'F';
}

void Comedy::print(ostream & stream) const {
    cout << this->getMovieType() << ", "
    << this->stock << ", "
    << this->director << ", "
    <<  this->title << ", "
    << this->year << ". ";
}

bool Comedy::operator<(const Comedy & other) const {
    if (this->getDirector().compare(other.getDirector()) != 0)
		return this->getDirector().compare(other.getDirector()) < 0;
	
	if (this->getTitle().compare(other.getTitle()) != 0)
		return this->getTitle().compare(other.getTitle()) < 0;	

	return this->getYear() < other.getYear();
}

// need to be fix
bool Comedy::operator<=(const Comedy & other) const {
    if (this->getDirector().compare(other.getDirector()) > 0)
        return false;

	if (this->getTitle().compare(other.getTitle()) > 0)
        return false;
        
	return this->getYear() <= other.getYear();
}

bool Comedy::operator>(const Comedy & other) const {
    if (this->getDirector().compare(other.getDirector()) != 0)
		return this->getDirector().compare(other.getDirector()) > 0;
	
	if (this->getTitle().compare(other.getTitle()) != 0)
		return this->getTitle().compare(other.getTitle()) > 0;	

	return this->getYear() > other.getYear();
}

bool Comedy::operator>=(const Comedy & other) const {
    if (this->getDirector().compare(other.getDirector()) < 0)
        return false;

	if (this->getTitle().compare(other.getTitle()) < 0)
        return false;

	return this->getYear() >= other.getYear();
}

bool Comedy::operator==(const Comedy & other) const {
    if ((this->getDirector().compare(other.getDirector()) == 0)
        && (this->getTitle().compare(other.getTitle()) == 0)
        && (this->getYear() == other.getYear()))
        return true;
    return false;
}

bool Comedy::operator!=(const Comedy & other) const {
    return !(*this == other);
}

ostream & operator<<(ostream & out, const Comedy & movie) {
    movie.print(out);
    return out;
}