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

bool Drama::setData(ifstream & infile) {

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

char Drama::getMovieType() const {
    return 'D';
}

void Drama::print(ostream & stream) const {
    cout << this->getMovieType() << ", "
    << this->stock << ", "
    << this->director << ", "
    << this->title << ", "
    << this->year << ". ";
}

ostream & operator<<(ostream & out, const Drama & movie) {
    movie.print(out);
    return out;
}