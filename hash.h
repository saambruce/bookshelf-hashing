//Bruce, Samantha                                                                                                                                                                                           
//hash.h                                                                                                                                                                                                    
//November 16, 2020                                                                                                                                                                                         

//Desctiption: Header file where functions and variables                                                                                                                                                    
//are declared and will be used in the hash.cpp file                                                                                                                                                        

//Assumption: N/A                                                                                                                                                                                           

//Source: N/A                                                                                                                                                                                               

#include<iostream>
#include "book.h"
using namespace std;

#ifndef HASH_H
#define HASH_H

class HashTable{
private:
  struct BookNode{
  long key;
  Book value;
  BookNode *next;
};
  BookNode **arr;
  float currentSize;

public:
  HashTable();
  ~HashTable();
  int hashFunc(long);
  string replace(string, char, char);
  void addToBookshelf(long, Book);
  bool readBook(long);
  void bookInfo(long);
  void displayAll();
  void recommend(long);
};

#endif
