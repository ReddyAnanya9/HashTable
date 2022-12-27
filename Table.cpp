// Name: Ananya Kotha
// USC NetID: akotha
// CSCI 455 PA5
// Fall 2022

// Table.cpp  Table class implementation

#include "Table.h"

#include <iostream>
#include <string>
#include <cassert>

// for hash function called in private hashCode method defined below
#include <functional>

using namespace std;


// listFuncs.h has the definition of Node and its methods.  -- when
// you complete it it will also have the function prototypes for your
// list functions.  With this #include, you can use Node type (and
// Node*, and ListType), and call those list functions from inside
// your Table methods, below.

#include "listFuncs.h"


//*************************************************************************

/* 
 * Default constructor for the Table class
 */

Table::Table() {   
   hashTable = new ListType[HASH_SIZE]();         
   noOfEntries = 0;  
   hashSize = HASH_SIZE;
}


/* 
 * constructor for the Table class
 * @param size of hashtable (array of linked lists) - number of buckets
 */

Table::Table(unsigned int hSize) {
   hashTable = new ListType[hSize]();         
   noOfEntries = 0;  
   hashSize = hSize;
}


/* 
 * Default constructor for the Table class
 */

int * Table::lookup(const string &key) {
   ListType node = getNode(hashTable[hashCode(key)],key);
   if(node == NULL){
      return NULL;
   }
   return &(node->value);
}


/* 
 * removes the entry/node associated with given key
 * @param string key
 * @return true if the node is removed, false otherwise
 * PRE: string key cannot be null
 */
bool Table::remove(const string &key) {
   bool flag = removeNode(hashTable[hashCode(key)],key); 
   if(flag){
      noOfEntries--;
   } 
   return flag;
}

/* 
 * inserts the pair of key and value into the linkedlist at the index 'hashCode(key)' of the hashTable. 
 * @param string key
 * @param integer value
 * @return true if the node is inserted, false otherwise
 * PRE: string key cannot be null
 */
bool Table::insert(const string &key, int value) {
   ListType newNode = getNode(hashTable[hashCode(key)],key);
   if(newNode != NULL){
      return false;
   }
   insertFront(hashTable[hashCode(key)],key,value);        
   noOfEntries++;                                         
   return true;
}

/* 
 * gives total number of key,value pairs i.e.nodes in the hash table
 * @return interger value of number of entries
 * PRE: All the linked lists in the hash table are well-formed lists and noOfEntries >= 0
 */
int Table::numEntries() const {
   return noOfEntries;      
}

/*
 * prints the key-value pairs in hash table
 * PRE: All the linked lists in the hash table are well-formed lists
*/
void Table::printAll() const {
   for(unsigned int i = 0; i < hashSize; i++){
      if(!isEmptyList(hashTable[i])){
         printList(hashTable[i]);
      }
   }
}

/* 
 * prints the hash table statistics - longest list at an index/bucket in hash table, number of non empty buckets,
 * the size of hash table, and total number of entries in the hash table - to ostream
*/

void Table::hashStats(ostream &out) const {
   int maxLen = 0;
   int nonEmptyBuckets = 0;
   for(unsigned int i=0; i < hashSize; i++){
      if(!isEmptyList(hashTable[i])){
         nonEmptyBuckets++;
         if(getSizeOfList(hashTable[i]) > maxLen){
            maxLen = getSizeOfList(hashTable[i]);
         }
      }      
   }
   out << "number of buckets: " << hashSize << endl;
   out << "number of entries: " << noOfEntries << endl;
   out << "number of non-empty buckets: " << nonEmptyBuckets << endl;
   out << "longest chain: " << maxLen << endl;

}


// hash function for a string
// (we defined it for you)
// returns a value in the range [0, hashSize)
unsigned int Table::hashCode(const string &word) const {

   // Note: calls a std library hash function for string (it uses the good hash
   //   algorithm for strings that we discussed in lecture).
   return hash<string>()(word) % hashSize;

}


// add definitions for your private methods here

