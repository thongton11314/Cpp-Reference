//-----------------------------------------------------------------------------
// Sort student data (by their grade).
// Display a list of students using a insertion sort to standard output.
// Data includes last name, first name, and grade.  For example:
//
// 65 duck donald
// 60 frog freddie
// 71 ghost casper
// 85 mouse abby
// 73 mouse mickey
// 95 mouse minnie
//
// Assumptions, implementation details:
//    -- Format of data is correct.
//    -- All names are no more in length than MAXLENGTH.
//    -- Grade are correctly sized as integers.
//    -- Data beyond MAXSIZE number of names is not stored in the list.

#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

const int MAXSIZE = 100;        // maximum number of students
const int MAXLENGTH = 30;       // maximum number of characters
const int HIGHESTGRADE = 100;   // higest grade
const int LOWESTGRADE = 0;      // lowest grade
const int GRADESCALE = 11;      // amount of grade scale

// struct of student type
struct StudentType {
	int grade;
	char last[MAXLENGTH];
	char first[MAXLENGTH];
};

// function prototype

// read data for students
bool readData(ifstream&, StudentType [], int&);

// sort into ascending order by grade
void sortInput(StudentType [], StudentType, const int);

// print list of student after sorting
void printList(const StudentType [], const int);

// calculate the grade average
int calAvg(const StudentType [], const int);

// print out a histogram
void displayHistogram(const StudentType students[], const int size);

//-----------------------------------------------------------------------------

int main() {
	StudentType students[MAXSIZE]; // all the students
	int size = 0;                  // total number of students

	// create file object and open the data file
	char nameFile[MAXLENGTH] = "data1.txt";
	ifstream infile(nameFile);
	if (!infile) {
		cout << nameFile << " could not be opened." << endl;
		return 1;
	}

	// get student data from a file, fill array then sort and print
	bool success = readData(infile, students, size);

	// if file is not empty then print data
	if (success) {

		// print the list of student after sort
		printList(students, size);
		cout << endl;

		// print the histogram of grades
		cout << "Histogram of grades :" << endl;
		displayHistogram(students, size);

		// print the average of student
		cout << endl;
		cout << "Average grade: " << calAvg(students, size) << endl;
	}

	// if file is empty then give a message
	else {
		cout << nameFile << " is empty" << endl;
	}

	// close file
	infile.close();
	return 0;
}

//-----------------------------------------------------------------------------
// read the data from a file (the first parameter) for one class of students
// and place into array (second parameter); the third parameter, size, is the
// number of items in the array, always less than the maximum size, MAXSIZE
bool readData(ifstream& infile, StudentType students[], int& size) {
	StudentType temp;     // temporary location for last name
	bool isEmpty = false; // this to check file empty
	
	// reading file
	while (size < MAXSIZE && !isEmpty) {

		// check empty file and break of loop
		infile >> temp.last;
		if (infile.eof()) {
			isEmpty = true;
		}
		
		// if file is not empty keep reading data
		else {

			// read each line from file
			infile >> temp.first >> temp.grade;

			// make sure that grade interval [0, 100]
			if (temp.grade >= LOWESTGRADE && temp.grade <= HIGHESTGRADE) {

				// sort element
				sortInput(students, temp, size);

				// increase size by one to add more student
				size++;
			}
		}
	}
	return size > 0 ? true : false;
}

//-----------------------------------------------------------------------------
// sortInput
// Sort array (first parameter) into ascending order by grade number; second
// parameter is number of elements considered in the array.
// Algorithm insert element into the ascending order
void sortInput(StudentType students[], StudentType temp, const int size) {
	int cur = size;         // get current index
	int rightSpot = false;  // check if element greater
	while (cur > 0 && rightSpot == false) {

		// student's last name is higher oder in alphabet
		if (strncmp(temp.last, students[cur - 1].last, MAXLENGTH) < 0) {
			students[cur] = students[cur - 1];
			cur--; // still looking for less than element
		}

		// student's last name is same
		else if (strncmp(temp.last, students[cur - 1].last, MAXLENGTH) == 0) {

			// sort by first name while having same last name
			if (strncmp(temp.first, students[cur - 1].first, MAXLENGTH) < 0) {
				students[cur] = students[cur - 1];
				cur--; // still looking for less than element
			}
			else {
				rightSpot = true;
			}
		}

		// student'st last name is lower order in alphabet
		else {
			rightSpot = true; // get of of loop if last name is greater
		}
	}

	// assign element from file to students array
	students[cur] = temp;
}

//-----------------------------------------------------------------------------
// printList
// print the list of students in given array for size number of items
void printList(const StudentType students[], const int size) {
	for (int i = 0; i < size; i++) {
		cout << students[i].grade << " "
			<< students[i].last << " "
			<< students[i].first << endl;
	}
}

//-----------------------------------------------------------------------------
// calAvg
// calculate average grade from list of students
int calAvg(const StudentType students[], const int size) {
	double avg = 0;
	for (int i = 0; i < size; i++) {
		avg += students[i].grade;
	}
	return (int)(avg / size);
}

//-----------------------------------------------------------------------------
// histogram
// print the frequency of student grades between 0-100
void displayHistogram(const StudentType students[], const int size) {

	// the frequency of how many time grade occur
	int frequency[GRADESCALE] = {};

	// the amount scale of grade
	char gradeScale[GRADESCALE][MAXLENGTH] =
	{ " 0-->    9:", "10-->   19:", "20-->   29:",
	"30-->   39:", "40-->   49:", "50-->   59:",
	"60-->   69:", "70-->   79:", "80-->   89:",
	"90-->   99:", "100--> 100:" };

	// assign each grade into right interval
	for (int i = 0; i < size; i++) {
		frequency[students[i].grade / 10]++;
	}				

	// print out the scale of grade and it frequency
	for (int i = 0; i < GRADESCALE; i++) {
		cout << gradeScale[i];
		for (int j = 0; j < frequency[i]; j++) {
			cout << '*';
		}
		cout << endl;
	}
}