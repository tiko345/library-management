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
	Book* searchById(int id);
	Book* searchByTitle(string title);
	vector<Book*> searchByAuthor(string author);//one author can have many books
	void borrowBook(int id);
	void returnBook(int id);
	void saveToFile(string filename) const;
	void loadFromFile(string filename);
};


#endif