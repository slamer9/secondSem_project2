#include "stdafx.h"
#include "Book.h"

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

