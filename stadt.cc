#include "gebiet.h"
#include "stadt.h"
#include <fstream>
#include <exception>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>

struct StadtOrder
{
	bool operator() (const Stadt* a, const Stadt* b) const
	{
		return *a < *b;
	}
};

StadtList::StadtList() {

}

StadtList::StadtList(char* fileName)
{
	ifstream s(fileName);
	try { for (;;) staedte.push_back(s); }
	catch (EOFException) {}
}

vector<Stadt>::iterator StadtList::end() {
	return staedte.end();
}

vector<Stadt>::iterator StadtList::begin() {
	return staedte.begin();
}

bool StadtList::empty() {
	return staedte.size() == 0;
}

void StadtList::insert(Stadt& s) {
	staedte.push_back(s);
}

vector<Stadt>::iterator StadtList::findStadt(string name)
{
	for (vector<Stadt>::iterator it = staedte.begin(); it != staedte.end(); it++)
	{
		cout << "(" << it->getName() << ", " << it->getID() << ", " << it->getGebietId() << ")\n";
		if (it->getName().compare(name) == 0)
			return it;
	}
	cout << "Die eingegebene Stadt '" << name << "' existiert nicht!\n";
	exit(1);
}

StadtList StadtList::findVerbStadt(StadtList verbstadt, GebietList verbgeb, StadtList sl)
{
	for (vector<Gebiet>::iterator gebiet = verbgeb.gebiete.begin(); gebiet != verbgeb.gebiete.end(); gebiet++)
	{
		for (vector<Stadt>::iterator stadt = sl.staedte.begin(); stadt != sl.staedte.end(); stadt++)
		{
			if (stadt->getGebietId() == gebiet->getID()) {
				verbstadt.insert(*stadt);
			}
		}
	}
	return verbstadt;
}

void StadtList::PrintStadt(StadtList sl)
{
	for (vector<Stadt>::iterator it = sl.staedte.begin(); it != sl.staedte.end(); it++)
		cout << it->getName() << "\n";
}
