#ifndef STRASSE_H
#define STRASSE_H

#include "gebiet.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>
#include <iomanip>

using namespace std;

class Strasse
{
public:
	Strasse(istream& s)
	{
		s >> vonstadtId >> nachstadtId >> entfernung;
		if (!s)  throw EOFException();  // abort constructor!
	}

	void print(ostream& o = cout) const
	{
		o << " (" << vonstadtId << ", " << nachStadtId << ", " << entfernung << ")\n";
	}

	bool operator< (const Strasse& str) const { return vonStadtId < str.vonStadtId; }

	bool printOrder(const Strasse* str) const
	{
		if (nachStadtId < str->nachStadtId) return true;
		if (nachStadtId > str->nachStadtId) return false;
		if (entfernung < str->entfernung) return true;
		if (entfernung > str->entfernung) return false;
		return false;
	}

	int getVonStadtId() const { return vonStadtId; }
	int getNachStadtId() const { return nachStadtId; }
	int getEntfernung() const { return entfernung; }

private:
	unsigned vonStadtId, nachStadtId, entfernung;
};

inline ostream& operator<< (ostream& o, const Strasse& str)
{
	str.print(o);  return o;
}


class StrasseList
{
public:
	StrasseList(char* fileName);
	StrasseList();

	vector<Strasse>::iterator end();
	vector<Strasse>::iterator begin();
	bool empty();
	void insert(Strasse& str);
	void PrintStrasse(StrasseList strl);
	StrasseList findErlStrasse(StrasseList verbstrasse, GebietList verbgeb, StrasseList sl);
	vector<Strasse> strassen;

private:

};

#endif
