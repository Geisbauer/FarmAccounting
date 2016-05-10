// Stall.cpp

#include "Stall.h"

Stall::Stall()
{
};

Stall::~Stall()
{
};


int sichernAufPlatte(vector<Tier*>&meineTiere, string dateiname)
{
	try
	{
		ofstream file(dateiname);
		streambuf *coutbuf = cout.rdbuf();
		cout.rdbuf(file.rdbuf());

		for_each(meineTiere.begin(), meineTiere.end(), &Tier::Print);

		cout.rdbuf(coutbuf);
		file << endl;
		file.close();
		return 0;
	}
	catch (...)
	{
		return -1;
	}
};

int einlesenVonPlatte(vector<Tier*>&meineTiere, string dateiname)
{
	string s;
	stringstream strStream;
	ifstream file(dateiname);
	strStream << file.rdbuf();
	s = strStream.str();
	cout << s << endl;
	file.close();
	return 0;
};

