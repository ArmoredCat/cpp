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

	Stadt(unsigned pId) { id = pId; }  // for comparisons

	void print(ostream& o = cout) const
	{
		o << name << " (" << einwohner << ", " << gebietId << ", " << meereshoehe << ")\n";
	}

	bool operator< (const Stadt& s) const { return id < s.id; }

	bool printOrder(const Stadt* s) const
	{
		if (einwohner < s->einwohner) return true;
		if (einwohner > s->einwohner) return false;
		if (gebietId < s->gebietId) return true;
		if (gebietId > s->gebietId) return false;
		if (meereshoehe < s->meereshoehe) return true;
		if (meereshoehe > s->meereshoehe) return false;
		if (name < s->name) return true;
		if (name > s->name) return false;
		return false;
	}

	int getID() const { return id; }
	string getName() const { return name; }
	int getEinwohner() const { return einwohner; }
	int getGebietId() const { return gebietId; }
	int getMeereshoehe() const { return meereshoehe; }

	bool verboten;

private:
	unsigned id;
	string name;
	unsigned einwohner, gebietId, meereshoehe;
};

inline ostream& operator<< (ostream& o, const Stadt& s)
{
	s.print(o);  return o;
}


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
	void PrintStadt(StadtList sl);
	void findVerbStadt(GebietList gl, StadtList &sl);
	vector<Stadt> staedte;

private:

};

#endif

