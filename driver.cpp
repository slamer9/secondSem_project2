#include "stdafx.h"
#include "driver.h"
// Copyright 2015, Utah Valley University
//Author: Roger deBry
// Date last modified: October 2015
// Driver code, Programming Project #2
// =======================================

class readException
{
private:
	int errorCode;

public:
	readException(int e)
	{
		errorCode = e;
	}
	
	void endOfFile()
	{
		cout << "You have reached the end of the file." << endl;
	}

	void read_error()
	{
		cout << "Error, could not read file." << endl;
	}

	void cantOpenFile()
	{
		cout << "Error, can't open file (does it exist?)" << endl;
	}
};

int main()
{

	// create a vector for storing the account objects
	vector<Book> myBooks;

	// create three Author objects
	Author p1("J.K.Rowling", "Edinburgh, Scotland");
	Author p2("Suzanne Collins", "Connecticut, USA");
	Author p3("J.R.R. Tolkien", "Bournmouth, England");

	// Create three Book objects
	Book b1(p1, "Harry Potter and the Sorcerer's Stone", 256, 24.95);
	Book b2(p2, "Mockingjay", 400, 12.99);
	Book b3(p3, "The Hobbit", 322, 14.29);

	// add the books to the vector
	myBooks.push_back(b1);
	myBooks.push_back(b2);
	myBooks.push_back(b3);

	// call the displayBooks function to display the books
	displayBooks(myBooks);
	cout << "\n\n";

	system("PAUSE");
	return 0;
}

void displayBooks(/*const*/ vector<Book>& books)
{
	for (int X = 0; X < books.size(); X++)
	{
		string bookName = books[X].getTitle();
		Author bookAuthor = books[X].getAuthor();
		int bookPages = books[X].getNumOfPages();
		double bookCost = books[X].getPrice();

		cout << bookName << endl << bookAuthor.getName() << endl << bookAuthor.getAdress()
			<< endl << bookPages << endl << bookCost << endl << endl;
	}
}
