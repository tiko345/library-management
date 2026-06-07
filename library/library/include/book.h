#ifndef BOOK_H
#define BOOK_H

#include <iostream>

using namespace std;

class Book {
	int id;
	string title;
	string author;
	int year;
	bool isAvailable;

public:
	Book(int id, string title, string author, int year, bool isAvailable=true);
	bool getIsAvailable() const;
	int getId() const;
	string getTitle() const;
	string getAuthor() const;
	int getYear() const;
	void display() const;
	void borrowBook();
	void returnBook();
};


#endif
