// Name: Ananya Kotha
// USC NetID: akotha
// CSCI 455 PA5
// Fall 2022


#include <iostream>

#include <cassert>

#include "listFuncs.h"

using namespace std;

Node::Node(const string &theKey, int theValue) {
   key = theKey;
   value = theValue;
   next = NULL;
}

Node::Node(const string &theKey, int theValue, Node *n) {
   key = theKey;
   value = theValue;
   next = n;
}




//*************************************************************************
// put the function definitions for your list functions below

/**
 * Print the given list
 * @param list - a linkedList
 * PRE: The list is a well formed list. 
 */
void printList(ListType list){
   ListType temp = list;
   while(temp != NULL){
      cout << temp->key << " " << temp->value << endl;
      temp = temp->next;
   }
}

/**
 * Get size of a given linkedList
 * @param list - linkedList
 * @return length of linkedList
 * PRE: The list is a well formed list.
 */
int getSizeOfList(ListType list){
   int len = 0;
   ListType temp = list;
   while(temp != NULL){
      len++;
      temp = temp->next;
   }
   return len;
}

/**
 * Check whether given linkedList is empty
 * @param list - linkedList
 * @return true if empty, false otherwise
 * PRE: The list is a well formed list.
 */
bool isEmptyList(ListType list){
   if(list == NULL){
      return true;
   }
   return false;
}

/**
 * Get node of a given target key
 * @param list - linkedList, string target
 * @return  Node* pointing to the target node.
 * PRE: The list is a well formed list and the string target cannot be null.
 */
ListType getNode(ListType list, string target){
   ListType temp = list;
   while(temp != NULL){
      if(temp->key == target){
         return temp;
      }
      temp = temp->next;
   }
   return NULL;   
}


/**
 * Insert new node in the first position of a given linkedList
 * @param a passed-by-reference linkedList, a string key, value of the inserting node
 * PRE: The list is a well formed list,and string key cannot be null.
 */ 
void insertFront(ListType & list, string key, int value){
   ListType newNode = new Node(key,value);
   newNode->next = list;
   list = newNode;
}

/**
 * Insert new node in the end of a given linkedList
 * @param a passed-by-reference linkedList, a string key, value of the inserting node
 * PRE: The list is a well formed list,and string key cannot be null.
 */ 
void insertEnd(ListType & list, string key, int value){
   if(isEmptyList(list)){
      list = new Node(key,value);
      return;
   }
   ListType temp = list;
   while(temp->next != NULL){
      temp = temp->next;
   }
   ListType newNode = new Node(key,value);
   temp->next = newNode;
}

/**
 * Delete node in the first position of a given linkedList
 * @param a passed-by-reference linkedList
 * @return true if removed, false otherwise
 * PRE: The list is a well formed list.
 */
bool removeFront(ListType & list){   
   if(list == NULL){
      return false;
   }
   ListType temp = list;
   list = list->next;
   delete temp;
   return true;
}

/**
 * Delete node in the last position of a given linkedList
 * @param a passed-by-reference linkedList
 * @return true if removed, false otherwise
 * PRE: The list is a well formed list.
 */
bool removeLast(ListType & list){
   if(list == NULL){
      return false; 
   }
   if(list->next == NULL){
      delete list;
      list = NULL;
      return true;
   }
   ListType temp = list;
   while(temp->next->next != NULL){
      temp = temp->next;
   }
   ListType removingNode = temp->next;
   delete removingNode;
   temp->next = NULL;
   return true;   
}
 
/**
 * Delete node of a specific key i.e. string target 
 * @param a passed-by-reference linkedList, string target
 * @return true if removed, false otherwise
 * PRE: The list is a well formed list.
 */ 
bool removeNode(ListType & list, string target){
   if(list == NULL || getNode(list,target) == NULL){
      return false;
   }

   ListType temp = list;
   ListType prev = NULL;
   if(list->key == target){
      return removeFront(list);
   }
   while (temp != NULL && temp->key != target){
        prev = temp;
        temp = temp->next;
   }
   prev->next = temp->next; 
   delete temp;
   
   return true;
}

/**
 * Change the value in the linked list at given target string by its new value 
 * @param a passed-by-reference linkedList, a string target, the new value
 * PRE: The list is a well-formed list and target can't be null.
 */
void changeValOfNode(ListType & list, string target, int value){
   
   ListType node = getNode(list,target);
   if(node == NULL){
      return;
   }
   node->value = value;
}