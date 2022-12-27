// Name: Ananya Kotha
// USC NetID: akotha
// CSCI 455 PA5
// Fall 2022

/*
 * grades.cpp
 * A program to test the Table class.
 * How to run it:
 *      grades [hashSize]
 * 
 * the optional argument hashSize is the size of hash table to use.
 * if it's not given, the program uses default size (Table::HASH_SIZE)
 *
 */

#include "Table.h"

// cstdlib needed for call to atoi
#include <cstdlib>

using namespace std;

void performCmd(Table *&, bool &);
void cmdSummary(); 
void insertVal(Table *&, string, int);
void updateVal(Table *&, string, int);
void lookupVal(Table *&, string);
void removeVal(Table *&, string);

int main(int argc, char * argv[]) {

   Table * grades;  // Table is dynamically allocated below, so we can call
                     // different constructors depending on input from the user.
   
   // optionally gets the hash table size from the command line
   if (argc > 1) {
      int hashSize = atoi(argv[1]);  // atoi converts c-string to int
      
      if (hashSize < 1) {
         cout << "Command line argument (hashSize) must be a positive number"<< endl;
         return 1;
      }

      grades = new Table(hashSize);

   }
   else {   // no command line args given -- use default table size
      grades = new Table();
   }


   grades->hashStats(cout);

   // add more code here
   // Reminder: use -> when calling Table methods, since grades is type Table*
   bool readInput = true;
   while(readInput){
      cout << "cmd>";
      performCmd(grades, readInput);
   }
   return 0;
}
 

/* Carries out the commands(print, insert, etc.,) as given in the CLI
 * @param a reference to Table *
 * @param boolean 
 * PRE: grades can't be null and each of the linkedlists inside the grades hashtable is well-formed.
*/
void performCmd(Table * &grades, bool &flag){
      string cmd, name;
      int score;
      cin >> cmd;
      if(cmd == "insert"){
         cin >> name >> score;
         insertVal(grades, name, score);
      }
      else if(cmd == "change"){
         cin >> name >> score;
         updateVal(grades,name,score);
      }
      else if(cmd == "lookup"){
         cin >> name;
         lookupVal(grades,name);         
      }
      else if(cmd == "remove"){
         cin >> name;
         removeVal(grades,name);
      }
      else if(cmd == "print"){
         grades->printAll();
      }
      else if(cmd == "size"){
         cout << grades->numEntries() << endl;
      }
      else if(cmd == "stats"){
         grades->hashStats(cout);
      }
      else if(cmd == "help"){
         cmdSummary();
      }
      else if(cmd == "quit"){
         flag = false;
      }
      else{
         cout << "ERROR: invalid command" << endl;
         cmdSummary();
      }
}


/*
 * Prints the manual - acceptable commands
 */
void cmdSummary(){
   cout << "The following are the valid commands of this program:" << endl;
   cout << "1. insert name score: insert this name and score in the grade table." << endl;
   cout << "2. change name newscore: Change the score for name." << endl;
   cout << "3. lookup name: Lookup the name, and print out his or her score." << endl;
   cout << "4. remove name: Remove this student." << endl;
   cout << "5. print: Prints out all names and scores in the table." << endl;
   cout << "6. size: Prints out the number of entries in the table." << endl;
   cout << "7. stats: Prints out statistics about the hash table at this point." << endl;
   cout << "8. help: Prints out a brief command summary." << endl;
   cout << "9. quit: Exits the program." << endl;
}

/* Inserts the name and score into hashTable, if the pair is not present.
 * @param a reference to Table *
 * @param a name string
 * @param an integer score value
 * PRE: grades can't be null and each of the linkedlists inside the grades hashtable is well-formed. 
 *      The string name can't be null.
 */
void insertVal(Table * &grades, string name, int score){
   if(!grades->insert(name,score)){
      cout << "The name is already present." << endl;
   }   
}

/* Updates the name with a new score if it is in the hashtable grades.
 * @param a reference to Table *
 * @param a name string
 * @param an integer score value
 * PRE: grades can't be null and each of the linkedlists inside the grades hashtable is well-formed. 
 *      The string name can't be null.
 */
void updateVal(Table * &grades, string name, int score){
   if(grades->lookup(name) == NULL){
      cout << "The name is not in the table." << endl;
   }
   *(grades->lookup(name)) = score;
}

/* returns the score for a name - if it is in the hashtable 'grades'.
 * @param a reference to Table *
 * @param a name string
 * PRE: grades can't be null and each of the linkedlists inside the grades hashtable is well-formed. 
 *      The string name can't be null.
 */
void lookupVal(Table * &grades, string name){
   if(grades->lookup(name) != NULL){
      cout << *(grades->lookup(name)) << endl;
   }
   else{
      cout << "The name is not in the table." << endl;
   }          
}

/* remove the name and its corresponding score - if name is in the hashtable 'grades'.
 * @param a reference to Table *
 * @param a name string
 * PRE: grades can't be null and each of the linkedlists inside the grades hashtable is well-formed. 
 *      The string name can't be null.
 */
void removeVal(Table * &grades, string name){
   if(!grades->remove(name)){
      cout << "The name wasn't in the grade table." << endl;
   }
}