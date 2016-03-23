#include "stdafx.h"
#include "Book.h"
#include <iostream>
#include <fstream>
#include <ostream>

using namespace std;

Book::Book(Author bookAuthor, string bookName, int bookPages, double bookCost)
{
	myAuthor = bookAuthor;
	title = bookName;
	numOfPages = bookPages;
	price = bookCost;
}

Author Book::getAuthor()
{
	return myAuthor;
}

string Book::getTitle()
{
	return title;
}

int Book::getNumOfPages()
{
	return numOfPages;
}

double Book::getPrice()
{
	return price;
}

void Book::writeData(ofstream& myOfStream)
{
	if (myOfStream.fail())
	{
		cout << "There was an error in creating the file" << endl;
	}
	else
	{
		myOfStream << myAuthor.getName() << endl << myAuthor.getAdress() << endl <<
			title << endl << numOfPages << endl << price << endl << endl;
	}
}

