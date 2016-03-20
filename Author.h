#pragma once
#include <string>

using namespace std;

class Author
{
public:
	Author();
	Author(string, string);
	string getName();
	string getAdress();
	void readData(ifstream&);
	void writeData(ofstream&);


private:
	string name;
	string adress;
};