#include <iostream>
#include <string>
using namespace std;

// define the book structure
struct Book {
	string title;
	string author;
	int ISBN;
};

// define the order structure
struct Order {
	int ISBN;
	int quantity;
};

// declare constants and variables
const int maxBooks = 100;
Book bookStore[maxBooks];
int numBooks = 0;

// Order Data
const int maxOrder = 10;
Order orderList[maxOrder];
int orderCount = 0;

// method to login
bool login() {
	string username, password;
	cout << "Login to Genius Bookstore" << endl;
	cout << "Enter username: " << endl;
	cin >> username;
	cout << "Enter password: " << endl;
	cin >> password;

	if (username == "admin" && password == "1234") {
		cout << "Login successful." << endl;
		return true;
	}

	else {
		cout << "Unauthorized Login. Try again." << endl;
		return false;
	}

}
// method to display all books in the bookstore
void viewBook() {
	if (numBooks == 0) {
		cout << "No books in the bookstore to view." << endl;
		return;
	}

	cout << "Books in the bookstore" << endl;
	for (int i = 0; i < numBooks; i++) {
		cout << "Title: " << bookStore[i].title << endl;
		cout << "Author: " << bookStore[i].author << endl;
		cout << "ISBN: " << bookStore[i].ISBN << endl;
		cout << "-------------------------" << endl;
	}

}
// method to add a new book to the bookstore
void addBook() {
	if (numBooks < maxBooks) {
		Book newBook;
		cout << "Enter book title: ";
		cin >> newBook.title;
		cout << "Enter book author: ";
		cin >> newBook.author;
		cout << "Enter book ISBN: ";
		cin >> newBook.ISBN;

		// check if ISBN already exists
		for (int i = 0; i < numBooks; i++) {
			if (bookStore[i].ISBN == newBook.ISBN) {
				cout << "Book with this ISBN already exists." << endl;
				return;
			}
		}

		bookStore[numBooks] = newBook;
		numBooks++;
		cout << "Book added successfully!" << endl;
	}

	else {
		cout << "Bookstore is full. Cannot add more books." << endl;
	}
}
// method to update books
void updateBook() {
	if (numBooks == 0) {
		cout << "No books in the bookstore to update." << endl;
		return;
	}

	int searchISBN;
	cout << "Enter ISBN to update: " << endl;
	cin >> searchISBN;

	for (int i = 0; i < numBooks; i++) {
		if (bookStore[i].ISBN == searchISBN) {
			cout << "Book found." << endl;

			string newTitle;
			cout << "Enter new book title: " << endl;
			cin >> newTitle;

			if (newTitle.empty()) {
				cout << "New book title found empty." << endl;
			}

			else {
				bookStore[i].title = newTitle;
			}

			string newAuthor;
			cout << "Enter new book author: " << endl;
			cin >> newAuthor;

			if (newAuthor.empty()) {
				cout << "New book author found empty." << endl;
			}

			else {
				bookStore[i].author = newAuthor;
			}
			cout << "Book updated successfully!" << endl;
			return;
		}
	}
	cout << "Book with ISBN: " << searchISBN << " not found." << endl;
}
// method to delete book
void deleteBook() {
	if (numBooks == 0) {
		cout << "No books in the bookstore to delete." << endl;
		return;
	}

	int searchISBN;
	cout << "Enter ISBN to delete: " << endl;
	cin >> searchISBN;

	bool found = false;
	for (int i = 0; i < numBooks; i++) {
		if (bookStore[i].ISBN == searchISBN) {
			//Shift all array to left
			for (int j = i; j < numBooks - 1; j++) {
				bookStore[j] = bookStore[j + 1];
			}
			numBooks--; // Reduce book count
			cout << "Book deleted successfully!" << endl;
			found = true;
			return;
		}
	}
	if (!found) {
		cout << "Book with ISBN: " << searchISBN << " not found." << endl;
	}
}
//method to search for a book by title
void searchBook() {
	if (numBooks == 0) {
		cout << "No books in the bookstore to search." << endl;
		return;
	}

	string searchTitle;
	cout << "Enter title to search: ";
	cin >> searchTitle;

	bool found = false;
	for (int i = 0; i < numBooks; i++) {
		string bookTitle = bookStore[i].title;

		if (bookTitle == searchTitle) {
			cout << "Book found: " << endl;
			cout << "Title: " << bookStore[i].title << endl;
			cout << "Author: " << bookStore[i].author << endl;
			cout << "ISBN: " << bookStore[i].ISBN << endl;
			cout << "Book found successfully!" << endl;
			found = true;
			break;
		}
	}
	if (!found) {
		cout << "Book with Title: " << searchTitle << " not found." << endl;
	}
}
// method to place order
void placeOrder() {
	if (numBooks == 0) {
		cout << "No books in the bookstore to place order." << endl;
		return;
	}

	int orderISBN;
	int orderQuantity;
	cout << "Enter ISBN to place order: " << endl;
	cin >> orderISBN;

	bool found = false;
	for (int i = 0; i < numBooks; i++) {
		if (bookStore[i].ISBN == orderISBN) {
			found = true;

			cout << "Enter quantity to order: " << endl;
			cin >> orderQuantity;

			if (orderQuantity <= 0) {
				cout << "Invalid quantity. Enter a positive number." << endl;
				return;
			}

			if (orderCount >= maxOrder) {
				cout << "Order is full. Cannot place more orders." << endl;
				return;
			}

			orderList[orderCount].ISBN = orderISBN;
			orderList[orderCount].quantity = orderQuantity;
			orderCount++;

			cout << "Order placed successfully!" << endl;
			cout << "Book: " << bookStore[i].title << " by " << bookStore[i].author << endl;
			cout << "Quantity: " << orderQuantity << endl;
			return;
		}
	}
	if (!found) {
		cout << "Book with ISBN: " << orderISBN << " not found." << endl;
	}
}
// method to view order 
void viewOrder() {
	if (orderCount == 0) {
		cout << "No orders in the order list to view." << endl;
		return;
	}

	cout << "Order List" << endl;
	for (int i = 0; i < orderCount; i++) {
		for (int j = 0; j < numBooks; j++) {
			if (bookStore[j].ISBN == orderList[i].ISBN) {
				cout << orderList[i].quantity << " x " << bookStore[j].title << " by " << bookStore[j].author << endl;
			}
		}
	}
}
// method to logout
bool logout() {
	cout << "Logged out successfully!" << endl;
	return false;
}
// main function
int main() {
	while (!login()) {
		// cout << "Try again." << endl;
	}

	bool loggedIn = true;
	int choice;

	do {
		cout << "\n---- Genius Bookstore System ----\n";
		cout << "\n";
		cout << "1. View Book" << endl;
		cout << "2. Add Book" << endl;
		cout << "3. Update Book" << endl;
		cout << "4. Delete Book" << endl;
		cout << "5. Search Book" << endl;
		cout << "6. Place order" << endl;
		cout << "7. View Order" << endl;
		cout << "8. Logout" << endl;
		cout << "9. Exit" << endl;
		cout << "\n";
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			viewBook();
			break;
		case 2:
			addBook();
			break;
		case 3:
			updateBook();
			break;
		case 4:
			deleteBook();
			break;
		case 5:
			searchBook();
			break;
		case 6:
			placeOrder();
			break;
		case 7:
			viewOrder();
			break;
		case 8:
			loggedIn = logout(); // this will return false
			while (!login()) {
				// cout << "Try again." << endl;
			}
			loggedIn = true; // re-login success
			break;
		case 9:
			cout << "Exiting system..." << endl;
			return 0;
		default:
			cout << "Invalid choice. Try again.\n";
		}

	} while (choice != 9);

	return 0;
}