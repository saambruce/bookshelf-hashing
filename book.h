//Bruce, Samantha                                                                                                                                                                                           
//book.h                                                                                                                                                                                                    
//November 16, 2020                                                                                                                                                                                         

//Description: Header file where all functions are variables                                                                                                                                                
//are declared before being implemented                                                                                                                                                                     

//Assumption: N/A                                                                                                                                                                                           

//Source: N/A                                                                                                                                                                                               

#include<iostream>
using namespace std;

#ifndef BOOK_H
#define BOOK_H

class Book{
private:
  string title, authors;
  float rating;
  long ISBN;
  int pages;

public:
  Book();
  Book(string, string, float, long, int);
  void setBook(string, string, float, long, int);
  string getTitle();
  string getAuthors();
  float getRating();
  long getISBN();
  int getPages();
  //  ~Book();                                                                                                                                                                                              
};

#endif
