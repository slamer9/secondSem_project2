#include "stdafx.h"
#include "driver.h"
#include "ReadException.h" 
/// Copyright 2015, Utah Valley University
///Author: Roger deBry
/// Date last modified: October 2015
/// Driver code, Programming Project #2
/// ========================================

#define MAX_SIZE 100
const string fileName = "bookData.txt";

int main()
{
	int option = 0;
	const int CREATE = 1;
	const int READ = 2;
	bool validInput = false;
	string garbageString;

	/// Display Menu 
	cout << "\nCS 1410 Project 3";
	cout << "\nSelect one of the following two options: ";
	cout << "\n   1 - create a test file";
	cout << "\n   2 - read the test file and display the results";
	cout << "\n>> ";

	while (validInput == false)
	{
		/// run the selected option
		if (cin >> option)
		{
			if (option == CREATE)
			{
				createTestFile();
				cout << "\nTest file has been created.";
				validInput = true;
			}
			else if (option == READ)
			{
				readTestFile();
				validInput = true;
			}
			else
			{
				cout << "\nInvalid option. Enter a [1] or a [2]." << endl;
			}
		}
		else
		{
			cout << "\nInvalid input. Enter a [1] or a [2]" << endl;
			cin.clear();
			cin >> garbageString;
		}
	}

	system("PAUSE");
	return 0;
}

void displayBooks(/*const*/ vector<Book>& books)
{
	cout << endl << endl;
	// set up cout to display currency
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	for (unsigned int X = 0; X < books.size(); X++)
	{
		string bookName = books[X].getTitle();
		Author bookAuthor = books[X].getAuthor();
		int bookPages = books[X].getNumOfPages();
		double bookCost = books[X].getPrice();

		cout << bookName << endl << bookAuthor.getName() << endl << bookAuthor.getAdress()
			<< endl << bookPages << endl << bookCost << endl << endl;
	}
}

void createTestFile()
{
	/// create a vector for storing the account objects
	vector<Book> myBooks;

	/// create three Author objects
	Author p1("J.K.Rowling", "Edinburgh, Scotland");
	Author p2("Suzanne Collins", "Connecticut, USA");
	Author p3("J.R.R. Tolkien", "Bournmouth, England");

	/// Create three Book objects
	Book b1(p1, "Harry Potter and the Sorcerer's Stone", 256, 24.95);
	Book b2(p2, "Mockingjay", 400, 12.99);
	Book b3(p3, "The Hobbit", 322, 14.29);

	/// add the books to the vector
	myBooks.push_back(b1);
	myBooks.push_back(b2);
	myBooks.push_back(b3);

	/// write the books to a file
	/// the file will be in the same folder as the executable file
	/// assume that the file opens
	ofstream outputFile;
	outputFile.open(fileName);

	for (unsigned i = 0; i < myBooks.size(); ++i)
	{
		myBooks[i].writeData(outputFile);
	}
}

void readTestFile()
{
	char bufferArray[MAX_SIZE];
	ifstream toScreen;
	vector<Book> bookVector;
	try 
	{
		openFile(toScreen, fileName);
		while (true)
		{
			string bookName;
			string authorName;
			string authorAdress;
			int bookPages;
			double bookCost;

			if (!toScreen.getline(bufferArray, MAX_SIZE))
				if (toScreen.eof())
					throw ReadException(END_OF_FILE);
				else
				throw ReadException(READ_ERROR);

			authorName.append(bufferArray);

			if (!toScreen.getline(bufferArray, MAX_SIZE))
				throw ReadException(READ_ERROR);

			authorAdress.append(bufferArray);

			if (!toScreen.getline(bufferArray, MAX_SIZE))
				throw ReadException(READ_ERROR);

			bookName.append(bufferArray);

			if (!toScreen.getline(bufferArray, MAX_SIZE))
				throw ReadException(READ_ERROR);

			if (!(bookPages = atoi(bufferArray)))
				throw ReadException(READ_ERROR);

			if (!toScreen.getline(bufferArray, MAX_SIZE))
				throw ReadException(READ_ERROR);

			bookCost = atof(bufferArray);

			if (!toScreen.getline(bufferArray, MAX_SIZE))	//Get rid of empty lines at end of each book
				throw ReadException(READ_ERROR);			//
			if (bufferArray[0] != NULL)						//
				throw ReadException(READ_ERROR);			//


			Author newAuthor = Author(authorName, authorAdress);
			Book newBook = Book(newAuthor, bookName, bookPages, bookCost);
			bookVector.push_back(newBook);
		}
	}
	catch (ReadException e)
	{
		e.readError();
		displayBooks(bookVector);
	}
}

void openFile(ifstream& in, const string& _name)
{
	in.open(_name);
	if (in.fail())
		throw ReadException(COULD_NOT_OPEN_FILE);
}