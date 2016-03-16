#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ReadException
{
private:
	int errorCode;

public:
	ReadException(int e)
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