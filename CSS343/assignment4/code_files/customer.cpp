#include "customer.h"

Customer::Customer() {
    firstName = DEFAULT_NAME;
    lastName = DEFAULT_NAME;
    id = DEFAULT_ID;
}

Customer::Customer(const Customer &other) {
    firstName = other.firstName;
    lastName = other.lastName;
    id = other.id;
}

Customer::~Customer() {
    // delete all media
    // delete history command
}

bool Customer::setData(ifstream& infile) {

    bool valid = true;

    infile >> id;
    if (infile.fail() || id < MINID || id > MAXID) {

        infile.clear()
        char temp;
        while (infile.get(temp) && temp != '\n');
        return false;
    }

    infile >> lastName >> firstName;

    // read until end of statement in file
    if (!valid) {
        infile.clear();
        char temp;
        while (infile.get(temp) && temp != '\n');
        return false;
    }
    return valid;
}
        
int Customer::getId() const {
    return id;
}

string Customer::getLastName() const {
    return lastName;
}

string Customer::getFirstName() const {
    return firstName;
}

const vector<Command*> Customer::getHistories() const {
    return history;
}

void Customer::borrowMedia(Media * media) {
    borrowing.push_back(media);
}

bool Customer::returnMedia(Media * target) {

    // need to update
    /*
    vector<Media*>::iterator iter; // = find(borrowing.begin(), borrowing.end(), target);
    if (iter == borrowing.end())
		return false;
	borrowing.erase(iter);
    return true;
    */
}

void Customer::addHistory(Command * command) {
    history.push_back(command);
}

ostream& operator<<(ostream &out, const Customer& customer) {
    out << customer.id << " " << customer.lastName << " " << customer.firstName;
    return out;
}