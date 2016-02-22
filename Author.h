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

private:
	string name;
	string adress;
};