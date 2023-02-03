//Bruce, Samantha                                                                                                                                                                                           
//hash.cpp                                                                                                                                                                                                  
//November 16, 2020                                                                                                                                                                                         

//Description: Method implementation file where all                                                                                                                                                         
//function declared in the hash.h file                                                                                                                                                                      

//Assumption: N/A                                                                                                                                                                                           
//Source: N/A                                                                                                                                                                                               

#include <iostream>
#include "book.h"
#include "hash.h"
using namespace std;

const int hashSize = 17;

//Constructor of HashTable class                                                                                                                                                                            
//Post: creates empty array                                                                                                                                                                                 
HashTable::HashTable()
{
  arr = new BookNode*[hashSize];
  for(int i = 0; i < hashSize; i++)
    arr[i] = nullptr;
  currentSize = 0.0;
}

//addToBookshelf function                                                                                                                                                                                   
//Pre: Takes in valid key and Book variables and valid hashFunc                                                                                                                                             
//Post: inserts Book to linked list within array                                                                                                                                                            
void HashTable::addToBookshelf(long k, Book v)
{
  int hashV = hashFunc(k);

  BookNode *temp = nullptr;
  BookNode *newNode = nullptr;
  newNode = new BookNode;

  if(arr[hashV] == nullptr){
    newNode->key = k;
    newNode->value = v;
    newNode->next = nullptr;
    arr[hashV] = newNode;
    currentSize++;

    float load;
    load = currentSize/hashSize;
    cout<<"Load Factor: "<<load<<endl;
  } else {
    temp = arr[hashV];
    BookNode *prev = nullptr;

    while (temp){
      if (temp->key == k){
        cout<<"Sorry! "<<temp->value.getTitle()<<" is already in the list"<<endl;
        return;
      } else {
        prev = temp;
        temp = temp->next;
      }
    }

    BookNode *nPtr = new BookNode;
    nPtr->key = k;
    nPtr->value = v;
    nPtr->next = nullptr;
    prev->next = nPtr;
    currentSize++;

    float factor;
    factor = currentSize/hashSize;
    cout<<"Load Factor: "<<factor<<endl;
  }
}

//hashFun                                                                                                                                                                                                   
//Pre: Takes in valid long variable                                                                                                                                                                         
//Post: returns integer used for position in array                                                                                                                                                          
int HashTable::hashFunc(long k){
  return k % hashSize;
}

//readBook function determines whether book is in shelf                                                                                                                                                     
//Pre: Takes in valid long variable and valid hash function                                                                                                                                                 
//Post: returns true or false depending on status of book                                                                                                                                                   
bool HashTable::readBook(long key){
  int hashV = hashFunc(key);
  BookNode *nPtr = arr[hashV];

  while(nPtr){
    if(nPtr->value.getISBN() == key){
      cout<<"You have read "<<nPtr->value.getTitle()<<"."<<endl;
      cout<<"Removing from bookshelf!"<<endl;
      delete nPtr;
      return true;
    } else {
      nPtr = nPtr->next;
    }
  }
  return false;
}

//bookInfo function hat displays all info of given key                                                                                                                                                      
//Pre: Takes in valid long variable                                                                                                                                                                         
//Post: displays all variables of Book                                                                                                                                                                      
void HashTable::bookInfo(long key){
  int hashV = hashFunc(key);
  BookNode *nPtr = arr[hashV];

  while(nPtr){
    if(nPtr->key == key){
      string tempAuth = replace(nPtr->value.getAuthors(), '-', ',');
      cout<<"Title: "<<nPtr->value.getTitle()<<endl;
      cout<<"Authors: "<<tempAuth<<endl;
      cout<<"ISBN: "<<nPtr->value.getISBN()<<endl;
      cout<<"Pages: "<<nPtr->value.getPages()<<endl;
      cout<<"Rating: "<<nPtr->value.getRating()<<endl;
      return;
    } else {
      nPtr = nPtr->next;
    }
  }
}

//displayAll function that displays title and isbn variable of all books                                                                                                                                    
//Pre: valid array                                                                                                                                                                                          
//Post: Title and ISBN displayed; displays string and long                                                                                                                                                  
void HashTable::displayAll()
{
  for(int i = 0; i < hashSize; i++){
    BookNode *n = arr[i];
    while(n){
      cout<<"Title: "<<n->value.getTitle()<<endl;
      cout<<"ISBN: "<<n->value.getISBN()<<endl;
      n = n->next;
      cout<<endl;
    }
  }
}

//Pre: takes in valid string and char variables                                                                                                                                                             
//Post: returns a string                                                                                                                                                                                    
string HashTable::replace(string s, char c1, char c2)
{
  int l = s.length();
  for (int i = 0; i < l; i++){
    if(s[i] == c1)
      s[i] =c2;
    else if (s[i]== c2)
      s[i] = c1;
  }
  return s;
}

//recommend function displays the book with the same author as given key                                                                                                                                    
//Pre: takes in valid long variable                                                                                                                                                                         
//Post: displays all variables of Book                                                                                                                                                                      
void HashTable::recommend(long key)
{
  int hashV = hashFunc(key);
  BookNode *nPtr = arr[hashV];
  string findA;

  while (nPtr){
    if (nPtr->value.getISBN() != key){
      nPtr = nPtr->next;
    } else {
      findA = nPtr->value.getAuthors();
      break;
    }
  }

  for(int i = 0; i < hashSize; i++){
    BookNode *temp = arr[i];
    while(temp){
      if(temp->value.getAuthors() == findA && temp->value.getISBN() != key){
        string tempAut = replace(findA, '-', ',');

        cout<<"Other book(s) by "<<tempAut<<" are "<<endl;
        cout<<"Title: "<<temp->value.getTitle()<<endl;
        cout<<"ISBN: "<<temp->value.getISBN()<<endl;
      }
      temp = temp->next;
      }
  }
}

//Destructor                                                                                                                                                                                                
HashTable::~HashTable()
{
  for (int i = 0; i < hashSize; i++){
    BookNode *newNode = arr[i];
    while(newNode != nullptr){
      BookNode *prevNode = newNode;
      newNode = newNode->next;
      delete prevNode;
    }
  }
  delete[] arr;
}
