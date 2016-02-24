#include "stdafx.h"
#include "Author.h"

Author::Author(string Authorname, string Authoradress)
{
	name = Authorname;
	adress = Authoradress;
}

string Author::getName()
{
	return name;
}

string Author::getAdress()
{
	return adress;
}
