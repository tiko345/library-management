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
	Book(int id, string title, string author, int year);
	bool getIsAvailable() const;
	int getId() const;
	string getTitle() const;
	string getAuthor() const;
	int getYear() const;
	void display() const;
	void borrowBookById();
	void returnBook();
};


#endif
