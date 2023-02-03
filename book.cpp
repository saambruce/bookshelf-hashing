//Bruce, Samantha
//book.cpp
//November 16, 2020

//Description: This file is the method-implementation where all functions
//are declared 

//Assumption: N/A

#include<iostream>
#include"book.h"
using namespace std;

//Constructor: sets all values to 0 or empty
Book::Book(){
  title = "";
  authors = "";
  rating = 0.0;
  ISBN = 0;
  pages = 0;
}

//Parameterized Constructor
//Pre: Takes in valid string, float, long, and int variables
//Post: sets variables with valid data types
Book::Book(string Title, string Authors, float Rating, long isbn, int Pages)
{
  title = Title;
  authors = Authors;
  rating = Rating;
  ISBN = isbn;
  pages = Pages;
}

//Setter Function
//Pre: Takes in valid string, float, long, and int variables
//Post: sets the variables to the variables in parameters
void Book::setBook(string title, string authors, float rating, long ISBN, int pages)
{
  this->title = title;
  this->authors = authors;
  this->rating = rating;
  this->ISBN = ISBN;
  this->pages = pages;
}

//Getter Function
//Post: returns string
string Book::getTitle(){
  return title;
}

//Getter Function
//Post: returns string
string Book::getAuthors(){
  return authors;
}

//Getter Function
//Post: returns float variables 
float Book::getRating(){
  return rating;
}

//GEtter Function
//Post: returns long variables
long Book::getISBN(){
  return ISBN;
}

//Getter Function
//Post: returns integer variables
int Book::getPages(){
  return pages;
}

