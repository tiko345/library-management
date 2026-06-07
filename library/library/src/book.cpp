#include<iostream>
#include "../include/book.h"

using namespace std;

Book::Book(int id, string title, string author, int year, bool isAvailable) {
	this->id = id;
	this->title = title;
	this->author = author;
	this->year = year;
	this->isAvailable = isAvailable;
}

bool Book::getIsAvailable() const {
	return isAvailable;
}

int Book::getId() const {
	return id;
}

string Book::getTitle() const {
	return title;
}

string Book::getAuthor() const {
	return author;
}

int Book::getYear() const {
	return year;
}

void Book::display() const {
	cout << "ID: " << id << endl;
	cout << "Title: " << title << endl;
	cout << "Author: " << author << endl;
	cout << "Publish Year: " << year << endl;
	cout << "Availability: " << (isAvailable ? "Available" : "Not Available") << endl;
}

void Book::borrowBook() {
	if (isAvailable) {
		isAvailable = false;
		cout << "You have borrowed the book: " << title << endl;
	}
	else {
		cout << "Sorry, the book is not available for borrowing." << endl;
	}
}

void Book::returnBook() {
	if (!isAvailable) {
				isAvailable = true;
		cout << "You have returned the book: " << title << endl;
	}
	else {
		cout << "This book was not borrowed." << endl;
	}
}

