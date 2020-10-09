// file list.h
// ADT List 
// Assignment of CS342

#ifndef _LIST_
#define _LIST_

#include <iostream>
#include <fstream>
using namespace std;

//--------------------------  class List  ------------------------------------
// ADT List: finite, ordered collection of zero or more items.
//           The ordering is determined by operator< of NodeData class.
//          
// Implementation and assumptions:  
//   -- Implemented as a linked list.
//   -- There is no dummy head node, head points to first node.  
//   -- If the list is empty, head is null pointer.
//   -- The insert allocates memory for a Node, ptr to the data is passed in.
//      Allocating memory and setting data is responsibility of the caller.  
//   -- The buildList allocates memory for new Nodes from files.
//   -- The merger will merger two lists; other lists will be empty.
//   -- The receiver will give to the passed in ptr allocation of the target.
//   -- The intersection hold common nodes other lists, but not empty lists.
//   -- The copy  will be used for copy constuctor and operator=.
//   -- The makeEmpty will be used in deconstructor.
//----------------------------------------------------------------------------

template<typename T>
class List {

    // g++ has problems with friend template functions and class templates
    // so put the code for operator<< here, in the class definition
    // output operator for class List, print data, 
    // responsibility for output is left to object stored in the list
    friend ostream& operator<<(ostream& output, const List<T>& thelist) {
        typename List<T>::Node* current = thelist.head;
        while (current != nullptr) {
            output << *current->data;
            current = current->next;
        }
        return output;
    }

public:
    List();                                      // default constructor
    List(const List& otherList);                 // copy constructor
    ~List();                                     // destructor
    void buildList(ifstream& infile);            // build list from file
    bool insert(T* dataptr);                     // insert data
    bool remove(const T &data, T *&ptr);         // remove data
    bool retrieve(const T &data, T *&ptr) const; // retrieve data
    void merge(List<T> &list1, List<T> &list2);  // merge two list

    // get common data from two list
    void intersect(List<T> const &list1, List<T> const &list2);
    bool isEmpty() const;                        // check empty
    void makeEmpty();                            // make empty

    // assign other list to this list
    List<T> & operator= (List<T> const &otherList);

    // check if two list are equal
    bool operator== (List<T> const &otherList) const;

    // check if two list are not equal
    bool operator!= (List<T> const &otherList) const;

private:
    struct Node {              // the node in a linked list
        T* data;               // pointer to actual data, operations in T
        Node* next;            // pointer for next node
    };

    Node* head;                // pointer to first node in list

    // this copy function will be used in copy constructor and operator=
    void copy(const List& otherList);
};
#endif // !_LIST_

//------------------------- construcotor -------------------------------------
// constructor
template<typename T>
List<T>::List() {
    head = nullptr;
}

//--------------------------- copy constructor -------------------------------
// copy other list to this list
template<typename T>
List<T>::List(const List & otherList) {
    if (otherList.head != nullptr)
        copy(otherList);
    else
        head = nullptr;
}

//----------------------------= destructor -----------------------------------
// destructor for this List
// delete each node before end of the function
template<typename T>
List<T>::~List() {

    // delete entire nodes
    makeEmpty();
}

//---------------------------- buildList -------------------------------------
// build list from file
// continually insert new items from a file into the list
template<typename T>
void List<T>::buildList(ifstream & infile) {
    T* ptr;
    bool successfulRead;                             // read good data
    bool success;                                    // successfully insert
    for (;;) {
        ptr = new T;

        // must have setData
        successfulRead = ptr->setData(infile);       // fill the T object
        if (infile.eof()) {
            delete ptr;
            break;
        }

        // insert good data into the list, otherwise ignore it
        if (successfulRead) {
            success = insert(ptr);
        }
        else {
            delete ptr;
        }
        if (!success) break;
    }
}

//---------------------------- insert ----------------------------------------
// insert an item into list; operator< of the NodeData class
// has the responsibility for the sorting criteria;
// Assume parameter is pointing to valid object
template<typename T>
bool List<T>::insert(T * dataptr) {
    Node* ptr = new Node;

    if (ptr == nullptr)
        return false;                            // out of memory, bail

    ptr->data = dataptr;                         // link the node to data

    // if the list is empty or if the node should be inserted before 
    // the first node of the list
    if (isEmpty() || *ptr->data < *head->data) {
        ptr->next = head;
        head = ptr;
    }

    // then check the rest of the list until we find where it belongs 
    else {
        Node* current = head->next;              // to walk list
        Node* previous = head;                   // to walk list, lags behind

        // walk until end of the list or found position to insert
        while (current != nullptr && *current->data < *ptr->data) {
            previous = current;                  // walk to next node
            current = current->next;
        }

        // insert new node, link it in
        ptr->next = current;
        previous->next = ptr;
    }
    return true;
}

//---------------------------- remove ----------------------------------------
// remove data from this list and assign to ptr
// make the target node out of the list then point the ptr to that address
template<typename T>
bool List<T>::remove(const T &target, T *&ptr) {
    ptr = nullptr;    //  it is null pointer in case not found node

    // early exit if this list is empty
    if (head == nullptr)
        return false;

    // use for walking node
    Node* current = head;
    Node* previous = current;
    Node* temp = nullptr;
    bool isIn = false;

    // walking
    while (current != nullptr && isIn == false) {

        // if found deleded node
        if (*current->data == target) {
            
            // check if this list has only one note
            if (current == head) {
                head->next == nullptr ? head = nullptr : head = head->next;
            }
            temp = current;
            current = current->next;
            previous = current;
            ptr = temp->data;
            temp->data = nullptr;
            delete temp;
            isIn = true;
        }

        // keep walkig if not found
        else {
            previous = current;
            current = current->next;
        }
    }
    current = nullptr;
    previous = nullptr;
    return isIn;
}

//----------------------------- retrieve -------------------------------------
// retrieve the data to the ptr
// using the target to find the node in list
// if the node found in list then point the ptr into that target address
template<typename T>
bool List<T>::retrieve(const T & target, T *& ptr) const {
    ptr = nullptr;                // initialize to nullptr
    bool isIn = false;            // check if in list
    Node* current = head;         // use for walking node

    // looking for the needed node
    while (current != nullptr && isIn == false) {

        // if found node
        if (*current->data == target) {
            ptr = current->data;
            isIn = true;
        }

        // keep walking if not found
        else
            current = current->next;
    }
    current = nullptr;
    return isIn;
}

//------------------------------ merge ---------------------------------------
// merge two other list to this list
// responsible to make empty the lists after merge
template<typename T>
void List<T>::merge(List<T>& list1, List<T>& list2) {
    Node* newHead = nullptr;        // used for new head of this list
    Node* current = nullptr;        // the current node of this list
    Node* ptr = nullptr;            // use for get each note from two list

    // early exit if current list is list1 or list2
    if (this->head == list1.head && this->head == list2.head)
        return;

    // walking to the end of node
    while (list1.head != nullptr || list2.head != nullptr) {
        
        // if list1 reach to the end, but list2 not
        if (list1.head == nullptr) {
            ptr = list2.head;
            list2.head = list2.head->next;
        }

        // if list2 reach to the end, but list1 not
        else if (list2.head == nullptr) {
            ptr = list1.head;
            list1.head = list1.head->next;
        }

        // if two other list are not null pointer
        else {

            // compare value if smaller & equal
            if (*list1.head->data < *list2.head->data
                || *list1.head->data == *list2.head->data) {
                ptr = list1.head;
                list1.head = list1.head->next;
            }

            // compare value if greater
            else if (*list1.head->data > *list2.head->data) {
                ptr = list2.head;
                list2.head = list2.head->next;
            }
        }

        // initialize for the first node
        if (newHead == nullptr) {
            current = ptr;
            newHead = current;
            current->next = nullptr;
        }

        // after the first node
        else {

            // move to next node
            current->next = ptr;
            current = current->next;
        }
    }
    current = nullptr;
    ptr = nullptr;
    makeEmpty();
    head = newHead;
}

//---------------------------- intersect ------------------------------------
// get common data from two list
// responsible for keep other lists after intersection
template<typename T>
void List<T>::intersect(List<T> const & list1, List<T> const & list2) {

    // early exit if current is list1 and list2
    if (head == list1.head && head == list2.head)
        return;
    Node* newHead = nullptr;              // used for new head of this list
    Node* current = nullptr;              // the current node of this list
    Node* tempList1 = list1.head;         // use to walk through list1
    Node* tempList2 = list2.head;         // use to walk through list2
    Node* temp = nullptr;                 // use for holding the added note

    // walking to the end of node
    while (tempList1 != nullptr && tempList2 != nullptr) {

        // compare value if smaller
        if (*tempList1->data < *tempList2->data)
            tempList1 = tempList1->next;

        // compare value if greater
        else if (*tempList1->data > *tempList2->data)
            tempList2 = tempList2->next;

        // compare value if equal, main point of intersection
        else {

            // first node in common
            temp = tempList1;
            if (newHead == nullptr) {
                newHead = new Node{ new T(*temp->data), nullptr };
                current = newHead;
            }

            // check duplicate
            if (*current->data != *temp->data) {
                current->next = new Node{ new T(*temp->data), nullptr };
                current = current->next;
            }
            tempList1 = tempList1->next;  // walk to next node in list1
            tempList2 = tempList2->next;  // walk to next node in list2
        }
    }
    current = nullptr;
    tempList1 = nullptr;
    tempList2 = nullptr;
    temp = nullptr;
    makeEmpty();
    head = newHead;
}

//----------------------------- isEmpty -------------------------------------
// check to see if List is empty
template<typename T>
bool List<T>::isEmpty() const {
    return head == nullptr;
}

//---------------------------- makeEmpty ------------------------------------
// clean every data and node of this list
// then make the head point to null pointer
template<typename T>
void List<T>::makeEmpty() {

    // walk until the head is nullptr
    while (head != nullptr) {
        Node* delNode = head;   // hold temporary current node to be deleted
        head = head->next;      // walk to next node
        delete delNode->data;   // delete data of node
        delete delNode;         // delete node
        delNode = nullptr;
    }

    // always assign last node equal null pointer
    head = nullptr;
}

//-----------------------------  =  -----------------------------------------
// Overloaded assignment operator
// make the current list empty then copy each node from other List
template<typename T>
List<T>& List<T>::operator=(List<T> const & otherList) {

    // check if two object is not equal and other list must have value
    if (&otherList != this) {

        // delete current list
        makeEmpty();

        // assign new list
        copy(otherList);
    }
    return *this;
}

//--------------------------------  ==  -------------------------------------
// Determine if two list are equal.
template<typename T>
bool List<T>::operator==(List<T> const & otherList) const {

    // early exit by checking the first node not same
    if ((otherList.head != nullptr && head == nullptr)
        || (otherList.head == nullptr && head != nullptr))
        return false;
    
    // early exit by checking the first node is same
    if (head == otherList.head)
        return true;

    // check each node;
    Node* temp1 = head;             // hold current head
    Node* temp2 = otherList.head;   // hold other list head
    bool flag = true;               // use for checking equal
    while (temp1 != nullptr && flag == true) {
        if ((temp1 != nullptr && temp2 == nullptr)
            || (temp1->next == nullptr && temp2->next != nullptr)
            || (temp1->next != nullptr && temp2->next == nullptr))
            flag = false;
        else {
            if (*temp1->data != *temp2->data)
                flag = false;
            else {
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
        }
    }
    temp1 = nullptr;
    temp2 = nullptr;
    return flag;
}

//--------------------------------  !=  -------------------------------------
// Determine if two list are not equal.
template<typename T>
bool List<T>::operator!=(List<T> const & otherList) const {
    return !(otherList == *this);
}

//-----------------------------   copy  -------------------------------------
// copy other list to this list
// this function are invoked in copy constructor and operator=
template<typename T>
void List<T>::copy(const List & otherList) {
    if (otherList.head != nullptr) {
        Node* temp = otherList.head;  // create a temporary node to walk into other list

        // create a head node for this list by other list head
        head = new Node{ new T(*temp->data), nullptr };
        Node* current = head;         // create a temporary node to walk into this list
        temp = temp->next;            // start walk after the head node

        // copy each node
        while (temp != nullptr)
        {
            // add new node and assign data then make next node null pointer
            current->next = new Node{ new T(*temp->data), nullptr };
            current = current->next;  // assign last node by null pointer
            temp = temp->next;        // walking from other node
        }
    }
}
