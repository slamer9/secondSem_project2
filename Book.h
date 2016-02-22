#pragma once
#include <string>
#include "Author.h"

using namespace std;

class Book
{
public:
	Book();
	Book(Author, string, int, double);
	Author getAuthor();
	string getTitle();
	int getNumOfPages();
	double getPrice();

private:
	Author myAuthor;
	string title;
	int numOfPages;
	double Price;

};