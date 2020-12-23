#ifndef STADT_H
#define STADT_H

#include "gebiet.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>
#include <iomanip>

using namespace std;

class Stadt
{
public:
	Stadt(istream& s)
	{
		s >> id >> name >> einwohner >> gebietId >> meereshoehe;
		if (!s)  throw EOFException();  // abort constructor!
		replace_if(name.begin(), name.end(), bind2nd(equal_to<char>(), '_'), ' ');
		verboten = false;
	}

	int getID() const { return id; }
	string getName() const { return name; }
	int getGebietId() const { return gebietId; }

	bool verboten;

private:
	unsigned id;
	string name;
	unsigned einwohner, gebietId, meereshoehe;
};

class StadtList
{
public:
	StadtList(char* fileName);
	StadtList();

	vector<Stadt>::iterator findStadt(string name);
	vector<Stadt>::iterator findStadt(int id);
	vector<Stadt>::iterator end();
	vector<Stadt>::iterator begin();
	bool empty();
	void insert(Stadt& s);
	void findVerbStadt(GebietList gl, StadtList &sl);

	vector<Stadt> staedte;

private:

};

#endif