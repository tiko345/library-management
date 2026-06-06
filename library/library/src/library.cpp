#include<iostream>
#include<vector>
#include "../include/library.h"

using namespace std;

void Library::addBook(Book book) {
	books.push_back(book);
}
void Library::displayBooks() const {
	for (auto book: books) {
		book.display();
	}
}

int Library::searchById(int id) {
	for (int i = 0; i < books.size(); i++) {
		if (books[i].getId() == id) {
			return i;
		}
	} return -1;
}

int Library::searchByTitle(string title) {
	for (int i = 0; i < books.size(); i++) {
		if (books[i].getTitle() == title) {
			return i;
		}
	} return -1;
}

int Library::searchByAuthor(string author) {
	for (int i = 0; i < books.size(); i++) {
		if (books[i].getAuthor() == author) {
			return i;
		}
	} return -1;
}

void Library::removeBookById(int id) {
		int index = searchById(id);
		if (index!=-1) {
			books.erase(books.begin() + index);
			cout << "Book removed successfully." << endl;
			return;
		}
    cout << "Book not found." << endl;
}

void Library::removeBookByTitle(string title) {
	int index = searchByTitle(title);
	if (index != -1) {
		books.erase(books.begin() + index);
		cout << "Book removed successfully." << endl;
		return;
	}
	cout << "Book not found." << endl;
}

void Library::borrowBook(int id) {
	if (searchById(id) != -1) {

		books[id]
	}
}