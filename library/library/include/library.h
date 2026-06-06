#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#include <iostream>
#include<vector>
using namespace std;

class Library {
	vector<Book>books;

public:
	void addBook(Book book);
	void displayBooks() const;
	void removeBookById(int id);
	void removeBookByTitle(string title);
	int searchById(int id);
	int searchByTitle(string title);
	int searchByAuthor(string author);
	void borrowBook(int id);
	void returnBook(int id);
	void saveToFile(string filename) const;
	void loadFromFile(string filename);
};


#endif