#pragma once
#include <iostream>
#include <string>
#include <vector>

#define READ_ERROR 1
#define END_OF_FILE 2
#define COULD_NOT_OPEN_FILE 3

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
		if (errorCode == READ_ERROR)
		{
			std::cout << "Could not read the file." << std::endl;
		}
		else
		if (errorCode == COULD_NOT_OPEN_FILE)
		{
			std::cout << "Could not open file, check to see if it exists, and path is accurate." << std::endl;
		}

	}
};