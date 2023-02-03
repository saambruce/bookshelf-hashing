//Bruce, Samantha                                                                                                                                                                                           
//driver.cpp                                                                                                                                                                                                   
//November 16, 2020                                                                                                                                                                                         

//Description: Program that reads information from csv file and                                                                                                                                             
//inserts into a bookshelf. User can manipulate bookshelf                                                                                                                                                   
//by reading/deleting books, printing bookshelf, and                                                                                                                                                        
//finding information about a certain book                                                                                                                                                                  

//Assumption: assumes that all types are entered correctly                                                                                                                                                  

//Sources: N/A                                                                                                                                                                                              

#include<iostream>
#include<fstream>
#include<sstream>
#include"book.h"
#include"hash.h"
using namespace std;

string filename = "books-sample.csv";

int main(){
  string input;
  ifstream nameFile(filename);
  string title;
  string authors;
  string tempRating;
  float rating;
  string tempISBN;
  long ISBN;
  int pages;
  string tempPages;

  Book b;
  HashTable bookshelf;

  cout<<"Hello! Processing the "<<filename<<" file."<<endl;

  if(nameFile.is_open())
    {
      getline(nameFile, input);

      while(getline(nameFile, input)){
         stringstream ss(input);
          getline(ss, title, ',');
          getline(ss, authors, ',');
          getline(ss, tempRating, ',');
          getline(ss, tempISBN, ',');
          getline(ss, tempPages, ',');

          rating = stof(tempRating.c_str());
          ISBN = stol(tempISBN.c_str());
          pages = stoi(tempPages.c_str());

          b.setBook(title, authors, rating, ISBN, pages);

          bookshelf.addToBookshelf(ISBN, b);
        }

      nameFile.close();

      int choice;
      cout<<"What will you like to do?"<<endl;
      cout<<"1. Browse for Books"<<endl;
      cout<<"2. Read a Book"<<endl;
      cout<<"3. View More Info About a Book"<<endl;
      cout<<"4. Get a Recommnedation"<<endl;
      cout<<"5. Quit"<<endl;
      cout<<"Choice: ";
      cin>>choice;

      while(choice != 5){
        if(choice == 1){
          bookshelf.displayAll();
          cout<<endl;

          cout<<"1. Browse for Books"<<endl;
          cout<<"2. Read a Book"<<endl;
          cout<<"3. View More Info About a Book"<<endl;
          cout<<"4. Get a Recommnedation"<<endl;
          cout<<"5. Quit"<<endl;
          cout<<"Choice: ";
          cin>>choice;

        } else if (choice == 2){
          long findBook;
          cout<<"Enter the ISBN of the book you want to read: ";
          cin>>findBook;
          bool read = bookshelf.readBook(findBook);
          if (read == false)
            cout<<"Sorry, don't have that book!"<<endl;

          cout<<"1. Browse for Books"<<endl;
          cout<<"2. Read a Book"<<endl;
          cout<<"3. View More Info About a Book"<<endl;
          cout<<"4. Get a Recommnedation"<<endl;
          cout<<"5. Quit"<<endl;
          cout<<"Choice: ";
          cin>>choice;

        } else if (choice == 3){
          long fBook;
          cout<<"Enter the ISBN of the book: ";
          cin>>fBook;
          bookshelf.bookInfo(fBook);

          cout<<"1. Browse for Books"<<endl;
          cout<<"2. Read a Book"<<endl;
          cout<<"3. View More Info About a Book"<<endl;
          cout<<"4. Get a Recommnedation"<<endl;
          cout<<"5. Quit"<<endl;
          cout<<"Choice: ";
          cin>>choice;
        } else if (choice == 4){
          long recBook;
          cout<<"Enter the ISBN of the book you enjoyed: ";
          cin>>recBook;
          bookshelf.recommend(recBook);

          cout<<"1. Browse for Books"<<endl;
          cout<<"2. Read a Book"<<endl;
          cout<<"3. View More Info About a Book"<<endl;
          cout<<"4. Get a Recommnedation"<<endl;
          cout<<"5. Quit"<<endl;          
          cout<<"Choice: ";
          cin>>choice;
        }
      }
    }
}
