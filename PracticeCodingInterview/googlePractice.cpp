/*
You are given an array A representing heights of students.
All the students are asked to stand in rows.
The students arrive by one, sequentially (as their heights appear in A). 
For the i-th student, if there is a row in which all the students are taller than A[i], the student will stand in one of such rows. 
If there is no such row, the student will create a new row. 
Your task is to find the minimum number of rows created.

Write a function that, given a non-empty array A containing N integers, denoting the heights of the students, returns the minimum number of rows created.

For example, given A = [5, 4, 3, 6, 1], the function should return 2.
Students will arrive in sequential order from A[0] to A[N−1]. 
So, the first student will have height = 5, the second student will have height = 4, and so on.

For the first student, there is no row, so the student will create a new row.
Row1 = [5]

For the second student, all the students in Row1 have height greater than 4. So, the student will stand in Row1.
Row1 = [5, 4]

Similarly, for the third student, all the students in Row1 have height greater than 3. So, the student will stand in Row1.
Row1 = [5, 4, 3]

For the fourth student, there is no row in which all the students have height greater than 6. So, the student will create a new row.
Row1 = [5, 4, 3]
Row2 = [6]

For the fifth student, all the students in Row1 and Row2 have height greater than 1. So, the student can stand in either of the two rows.
Row1 = [5, 4, 3, 1]
Row2 = [6]

Since two rows are created, the function should return 2.

Assume that:
N is an integer within the range [1..1,000]
each element of array A is an integer within the range [1..10,000]
In your solution, focus on correctness. The performance of your solution will not be the focus of the assessment
*/

#include <iostream>
#include <regex>
#include <string>
#include <vector>

using namespace std;

// wrong
int solution (vector<int> A) {
    // your solution goes here.

    // psedocode

    // create a vector of vector to trace how many array was created
    vector<vector<int>> mainVector;

    for (int i = 0; i < A.size(); i++) {

        // first case
        if (i == 0) {
            vector<int> newVector1;
            newVector1.push_back(A.at(i));
            mainVector.push_back(newVector1);
        }

        else {                       
            for (int j = 0; j < mainVector.size(); j++) {

                // element less than all other element
                if (A.at(i) < mainVector.at(j).at(mainVector.at(j).size() - 1))
                    mainVector.at(j).push_back(A.at(i));

                // element is greater than element
                else {
                    vector<int> newVector2;
                    newVector2.push_back(A.at(i));
                    mainVector.push_back(newVector2);
                }
            }
        }
    }
    
    for (int i = 0; i < mainVector.size(); i++) {
        for (int j = 0; j < mainVector.at(i).size(); j++) {
            cout << mainVector.at(i).at(j) << endl;
        }
    }
    return mainVector.size();
}

vector<int> toIntVector(string str) {
    vector<int> out;
    string i;
    istringstream tokenStream(str);
    while (std::getline(tokenStream, i, ','))
        out.push_back(atoi(i.c_str()));
    return out;
}

int main() {
    // read in from stdin, solve the problem, and write answer to stdout
    string AS;
    cin >> AS;
    vector<int> A = toIntVector(AS);
    cout << solution(A);
}