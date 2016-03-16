#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int READ_ERROR = 1;
const int END_OF_FILE = 2;
const int COULD_NOT_OPEN_FILE = 3;

class ReadException
{
private:
	int errorCode;

public:
	ReadException(int e)
	{
		errorCode = e;
	}

	void readError()
	{
		if (errorCode == 1)
		{
			cout << "Could not read the file." << endl;
		}else
			if (errorCode == 2)
			{
				cout << "End of file reached." << endl;
			} else
				if (errorCode == 3)
			{
				cout << "Could not open file, check to see if it exists, and path is accurate." << endl;
			}
				else
				{
					cout << "Unknown error." << endl;
				}
	}

};