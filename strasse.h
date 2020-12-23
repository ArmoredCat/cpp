#ifndef STRASSE_H
#define STRASSE_H

#include "gebiet.h"
#include "stadt.h"
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
		s >> vonStadtId >> nachStadtId >> entfernung;
		if (!s)  throw EOFException();  // abort constructor!
		verboten = true;
		besuchtVonStadt = false;
		besuchtNachStadt = false;
	}

	void print(ostream& o = cout) const
	{
		o << " (" << vonStadtId << ", " << nachStadtId << ", " << entfernung << ")\n";
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

	bool verboten;
	bool besuchtVonStadt;
	bool besuchtNachStadt;

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
	void findErlStrasse(StadtList sl, StrasseList &strl);
	int FindeRoute(StrasseList strl, StadtList sl, vector<Stadt>::iterator startstadt, vector<Stadt>::iterator zielstadt);

	vector<Strasse> strassen;

private:

};

#endif

