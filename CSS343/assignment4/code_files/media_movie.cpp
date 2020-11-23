#include "media_movie.h"

Movie::~Movie() {}

void Movie::setDirector(string director) {
    this->director = director;
}

void Movie::setTitle(string title) {
    this->title = title;
}

void Movie::setYear(int year) {
    this->year = year;
}

string Movie::getDirector() const {
    return this->director;
}

string Movie::getTitle() const {
    return this->title;
}

int Movie::getYear() const {
    return this->year;
}

string Movie::getMediaType() const {
    return "DVDMovie";
}

// compare by dirtector name, movie title, then year
bool Movie::operator<(const Media & other) const {
    const Media * ptr = &other;
    if (this->getDirector().compare(dynamic_cast<const Movie*>(ptr)->getDirector()) != 0)
		return this->getDirector().compare(dynamic_cast<const Movie*>(ptr)->getDirector()) < 0;
	
	if (this->getTitle().compare(dynamic_cast<const Movie*>(ptr)->getTitle()) != 0)
		return this->getTitle().compare(dynamic_cast<const Movie*>(ptr)->getTitle()) < 0;	

	return this->getYear() < dynamic_cast<const Movie*>(ptr)->getYear();
}

bool Movie::operator<=(const Media & other) const {
    const Media * ptr = &other;
    if (this->getDirector().compare(dynamic_cast<const Movie*>(ptr)->getDirector()) > 0)
        return false;

	if (this->getTitle().compare(dynamic_cast<const Movie*>(ptr)->getTitle()) > 0)
        return false;
        
	return this->getYear() <= dynamic_cast<const Movie*>(ptr)->getYear();
}

bool Movie::operator>(const Media & other) const {
    const Media * ptr = &other;
    if (this->getDirector().compare(dynamic_cast<const Movie*>(ptr)->getDirector()) != 0)
		return this->getDirector().compare(dynamic_cast<const Movie*>(ptr)->getDirector()) > 0;
	
	if (this->getTitle().compare(dynamic_cast<const Movie*>(ptr)->getTitle()) != 0)
		return this->getTitle().compare(dynamic_cast<const Movie*>(ptr)->getTitle()) > 0;	

	return this->getYear() > dynamic_cast<const Movie*>(ptr)->getYear();
}

bool Movie::operator>=(const Media & other) const {
    const Media * ptr = &other;
    if (this->getDirector().compare(dynamic_cast<const Movie*>(ptr)->getDirector()) < 0)
        return false;

	if (this->getTitle().compare(dynamic_cast<const Movie*>(ptr)->getTitle()) < 0)
        return false;

	return this->getYear() >= dynamic_cast<const Movie*>(ptr)->getYear();
}

bool Movie::operator==(const Media & other) const {
    const Media * ptr = &other;
    if ((this->getDirector().compare(dynamic_cast<const Movie*>(ptr)->getDirector()) == 0)
        && (this->getTitle().compare(dynamic_cast<const Movie*>(ptr)->getTitle()) == 0)
        && (this->getYear() == dynamic_cast<const Movie*>(ptr)->getYear()))
        return true;
    return false;
}

bool Movie::operator!=(const Media & other) const {
    return !(*this == other);
}


// use to use << opertor
ostream& operator<<(ostream & out, const Movie & movie) {
    movie.print(out);
    return out;
}