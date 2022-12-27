// Name: Ananya Kotha
// USC NetID: akotha
// CSCI 455 PA5
// Fall 2022


//*************************************************************************
// Node class definition 
// and declarations for functions on ListType

// Note: we don't need Node in Table.h
// because it's used by the Table class; not by any Table client code.

// Note2: it's good practice to *not* put "using" statement in *header* files.  Thus
// here, things from std libary appear as, for example, std::string

#ifndef LIST_FUNCS_H
#define LIST_FUNCS_H

#include <string>
  

struct Node {
   std::string key;
   int value;

   Node *next;

   Node(const std::string &theKey, int theValue);

   Node(const std::string &theKey, int theValue, Node *n);
};


typedef Node * ListType;

//*************************************************************************
//add function headers (aka, function prototypes) for your functions
//that operate on a list here (i.e., each includes a parameter of type
//ListType or ListType&).  No function definitions go in this file.

/**
 * Print the given list
 * @param list - a linkedList
 */
void printList(ListType list);

/**
 * Get size of a given linkedList
 * @param list - linkedList
 * @return length of linkedList
 */
int getSizeOfList(ListType list);

/**
 * Check whether given linkedList is empty
 * @param list - linkedList
 * @return true if empty, false otherwise
 */
bool isEmptyList(ListType list);

/**
 * Get node of a given target key
 * @param list - linkedList, string target
 * @return  Node* pointing to the target node.
 */
ListType getNode(ListType list, std::string target);

/**
 * Insert new node in the first position of a given linkedList
 * @param a passed-by-reference linkedList, a string key, value of the inserting node
 */ 
void insertFront(ListType & list, std::string key, int value);

/**
 * Insert new node in the end of a given linkedList
 * @param a passed-by-reference linkedList, a string key, value of the inserting node
 */ 
void insertEnd(ListType & list, std::string key, int value);


/**
 * Delete node in the first position of a given linkedList
 * @param a passed-by-reference linkedList
 * @return true if removed, false otherwise
 */ 
bool removeFront(ListType & list);

/**
 * Delete node in the last position of a given linkedList
 * @param a passed-by-reference linkedList
 * @return true if removed, false otherwise
 */ 
bool removeLast(ListType & list);

/**
 * Delete node at specific index
 * @param a passed-by-reference linkedList, string target
 * @return true if removed, false otherwise
 */ 
bool removeNode(ListType & list, std::string target);

/**
 * Change the value in the linkedList by given target string
 * @param a passed-by-reference linkedList, a string target, the new value
 */
void changeValOfNode(ListType & list, std::string target, int value);


// keep the following line at the end of the file
#endif
