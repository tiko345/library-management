#include<iostream>
#include<string>
#include<vector>
#include "../include/book.h"
#include "../include/library.h"

using namespace std;

void showMenu() {
	cout << endl;
	cout << "---------Library Menu----------" << endl;
	cout << "1.Add book" << endl;
	cout << "2. Display All books" << endl;
	cout << "3. Borrow book" << endl;
	cout << "4. Return book" << endl;
	cout << "5. Remove book by id" << endl;
	cout << "6. Remove book by Title" << endl;
	cout << "7. Search by id" << endl;
	cout << "8. Search by title" << endl;
	cout << "9. Search by Author" << endl;
	cout << "10. save to file" << endl;
	cout << "11. load from file" << endl;
	cout << "0. exit" << endl;
	cout << "Enter your choice" << endl << endl << endl;
}

int main() {
	Library library;

	//reads previous data
	library.loadFromFile("library.txt");

	int choice;
	int id, year;
	string title, author,filename;

	do {
		showMenu();
		cin >> choice;
		cin.ignore();

		switch (choice) {
			case 0:
			{
				library.saveToFile("library.txt");
				cout << "Data saved. Goodbye!" << endl;
				break;
			}
			case 1:
			{
				cout << "Enter id: " << endl;
				cin >> id;
				cin.ignore();
				cout << "Enter book Title: " << endl;
				getline(cin, title);
				cout << "Enter book Author: " << endl;
				getline(cin, author);
				cout << "Enter book publish year: " << endl;
				cin >> year;
				cin.ignore();

				library.addBook(Book(id, title, author, year));
				cout << "Book added successfully" << endl;
				break;
			}
			case 2:
			{
				library.displayBooks();
				break;
			}
			case 3:
			{
				cout << "Enter book id you want to borrow: " << endl;
				cin >> id;
				library.borrowBook(id);
				break;
			}
			case 4:
			{
				cout << "Enter book id you want to return: " << endl;
				cin >> id;
				library.returnBook(id);
				break;
			}
			case 5:
			{
				cout << "Enter book id you want to remove: " << endl;
				cin >> id;
				library.removeBookById(id);
				break;
			}
			case 6:
			{
				cout << "Enter book title you want to remove: " << endl;
				getline(cin, title);
				library.removeBookByTitle(title);
				break;
			}
			case 7:
			{
				cout << "Enter book id you're looking for: " << endl;
				cin >> id;
				Book* foundBook = library.searchById(id);
				if (foundBook!=nullptr) {
					foundBook->display();
				}
				else {
					cout << "book not found" << endl;
				}
				break;
			}
			case 8:
			{
				cout << "Enter book title you're looking for: " << endl;
				getline(cin, title);
				Book* foundBook = library.searchByTitle(title);
				if (foundBook!=nullptr) {
					foundBook->display();
				}
				else {
					cout << "book not found" << endl;
				}
				break;
			}
			case 9:
			{
				cout << "Enter the book author you're looking for: " << endl;
				getline(cin, author);
				vector<Book*> foundBooks= library.searchByAuthor(author);
				if (!foundBooks.empty()) {
					for (const auto& book : foundBooks) {
						book->display();
					}
				}
				else {
					cout << "book not found" << endl;
				}
				break;
			}
			case 10:
			{
				cout << "Enter file name to save library info: " << endl;
				cin >> filename;
				library.saveToFile(filename);
				break;
			}
			case 11:
			{
				cout << "Enter file name you want to read from: " << endl;
				cin >> filename;
				library.loadFromFile(filename);
				break;
			}
		}
	} while (choice != 0);


	return 0;
}