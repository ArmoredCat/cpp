#include "gebiet.h"
#include "stadt.h"
#include <fstream>
#include <exception>
#include <string>
#include <iomanip>
#include <vector>

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
		if (it->getName().compare(name) == 0)
			return it;
	}
	cout << "Die eingegebene Stadt '" << name << "' existiert nicht!\n";
	exit(1);
}

vector<Stadt>::iterator StadtList::findStadt(int id)
{
	for (vector<Stadt>::iterator it = staedte.begin(); it != staedte.end(); it++)
	{
		if (it->getID() == id)
			return it;
	}
	cout << "Die eingegebene Stadt mit ID '" << id << "' existiert nicht!\n";
	exit(1);
}

void StadtList::findVerbStadt(GebietList gl, StadtList &sl)
{
	for (vector<Gebiet>::iterator gebiet = gl.gebiete.begin(); gebiet != gl.gebiete.end(); gebiet++)
	{
		if (gebiet->verboten == false)
			continue;
		for (vector<Stadt>::iterator stadt = sl.staedte.begin(); stadt != sl.staedte.end(); stadt++)
		{
			if (stadt->getGebietId() == gebiet->getID()) {
				(*stadt).verboten=true;
			}
		}
	}
}