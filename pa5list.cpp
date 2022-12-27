// Name: Ananya Kotha
// USC NetID: akotha
// CS 455 PA5
// Fall 2022

// pa5list.cpp
// a program to test the linked list code necessary for a hash table chain

// You are not required to submit this program for pa5.

// We gave you this starter file for it so you don't have to figure
// out the #include stuff.  The code that's being tested will be in
// listFuncs.cpp, which uses the header file listFuncs.h

// The pa5 Makefile includes a rule that compiles these two modules
// into one executable.

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

#include "listFuncs.h"

int main() {

   ListType stud = NULL;
   
   cout << "Is the students list empty [exp: true] : " << isEmptyList(stud) << endl;
   cout << "Inserting students" << endl;
   insertFront(stud, "A", 30);
   insertFront(stud, "B", 29);
   insertFront(stud, "C", 28);
   insertFront(stud, "D", 30);
   insertFront(stud, "E", 30);
   
   cout << "The list is; "<< endl;
   printList(stud); //prints a the linked list CBADE
   
   //insertBefore(stud, "F", 31, "A");
   //insertAfter(stud, "G", 45, "D");
   //insertBefore(stud, "H", 31, "U");
   
   
   cout << "The list is; "<< endl;
   printList(stud); //prints a the linked list CBFADGE
   
   
   bool del;
   cout << "Deleting head" << endl;
   del = removeFront(stud);
   cout << "Deleted? " << del << endl;
   cout << "The new list is; "<< endl;
   printList(stud); //prints a the linked list BFADGE
   
   
   cout << "The list is; "<< endl;
   printList(stud); //prints a the linked list BFDG
   cout << "The number of students are [exp : ]: " << getSizeOfList(stud) << endl;
   cout << "Is the students list empty [exp: false] : " << isEmptyList(stud) << endl;
  
   return 0;
}
