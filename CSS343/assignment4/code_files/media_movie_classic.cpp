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

bool Classic::setData(ifstream & infile) {

    // set up stock
    infile.ignore();
    infile >> this->stock;

    // set up director
    infile.ignore();
    getline(infile >> ws, this->director, ',');

    // set up title
    infile.ignore();
    getline(infile >> ws, this->title, ',');

    // set major actor
    string majorActorFirstName;
    infile >> majorActorFirstName;
    string majorActorLastName;
    infile >> majorActorLastName;
    this->majorActor = majorActorFirstName + " " + majorActorLastName;

    // set month
    infile.ignore();
    infile >> this->month;

    // set year
    infile.ignore();
    infile >> this->year;

    // end of line
    infile.ignore();
    string eol;
    getline(infile, eol);

    return true;
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

char Classic::getMovieType() const {
    return 'C';
}

void Classic::print(ostream & stream) const {
    cout << this->getMovieType() << ", " 
    << this->stock << ", "
    << this->director << ", "
    << this->title << ", "
    << this->majorActor << ", "
    << this->month << ", "
    << this->year << ". ";
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
    movie.print(out);
    return out;
}