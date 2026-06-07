#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include "../include/library.h"
#include "../include/book.h"

using namespace std;

void Library::addBook(Book book) {
	books.push_back(book);
}

void Library::displayBooks() const {
	for (const auto& book : books) {
		book.display();
		cout << endl << endl;
	}
}
//return type pointer in case the book is not found it can return nullptr

Book* Library::searchById(int id) {
	for (int i = 0; i < books.size(); i++) {
		if (books[i].getId() == id) {
			return &books[i];
		}
	} return nullptr;
}

Book* Library::searchByTitle(string title) {
	for (int i = 0; i < books.size(); i++) {
		if (books[i].getTitle() == title) {
			return &books[i];
		}
	} return nullptr;
}

vector<Book*> Library::searchByAuthor(string author) {
	vector<Book*> matches;

	for (int i = 0; i < books.size(); i++) {
		if (books[i].getAuthor() == author) {
			matches.push_back(&books[i]);
		}
	}
	return matches;
}

void Library::removeBookById(int id) {
	Book* book = searchById(id);
	if (book!=nullptr) {
		int index = book - &books[0];
		books.erase(books.begin() + index);
		cout << "Book removed successfully." << endl;
		return;
	}
	cout << "Book not found." << endl;
}

void Library::removeBookByTitle(string title) {
	Book* book = searchByTitle(title);
	if (book != nullptr) {
		int index = book - &books[0];
		books.erase(books.begin() + index);
		cout << "Book removed successfully." << endl;
		return;
	}
	cout << "Book not found." << endl;
}

void Library::borrowBook(int id) {
	Book* book = searchById(id);
	if (book != nullptr) {
		if (book->getIsAvailable()) {
			book->borrowBook();
		}
		else {
			cout << "Book already borrowed." << endl;
		}
	}
	else {
		cout << "Book not found." << endl;
	}
}

void Library::returnBook(int id) {
	Book* book = searchById(id);
	if (book != nullptr) {
		if (!book->getIsAvailable()) {
			book->returnBook();
		}
		else {
			cout << "Book already returned." << endl;
		}
	}
	else {
		cout << "Book not found." << endl;
	}
}

void Library::saveToFile(string filename) const {
	ofstream file(filename);

	if (!file.is_open()) {
		cout << "Error opening file for saving." << endl;
		return;
	}

	for (const auto& book : books) {
		file << book.getId() << "\n"
			<< book.getTitle() << "\n"
			<< book.getAuthor() << "\n"
			<< book.getYear() << "\n"
			<< book.getIsAvailable() << "\n\n";
	}
	file.close();
	cout << "Data saved successfully." << endl;
}

void Library::loadFromFile(string filename) {
	ifstream file(filename);

	if (!file.is_open()) {
		cout << "No existing file found." << endl;
		return;
	}

	string idStr, title, author, yearStr, availStr;

	while (getline(file, idStr)) {
		if (idStr.empty()) continue;

		getline(file, title);
		getline(file, author);
		getline(file, yearStr);
		getline(file, availStr);

		if (yearStr.empty() || availStr.empty()) continue;

		int id = stoi(idStr);

		bool exists = false;
		for (const auto& b : books) {
			if (b.getId() == id) {
				exists = true;
				break;
			}
		}

		if (!exists) {
			books.push_back(Book(
				id,
				title,
				author,
				stoi(yearStr),
				stoi(availStr)
			));
		}
	}

	file.close();
}