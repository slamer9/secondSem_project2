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
	virtual void readData(ifstream&);
	virtual void writeData(ofstream&);

private:
	Author myAuthor;
	string title;
	int numOfPages;
	double price;
};

class AudioBook : public Book
{
private:
	int timeLength;
public:
	AudioBook();
};

class DigitalBook : public Book
{
private:
	string format;
};