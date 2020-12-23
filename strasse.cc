#include "strasse.h"
#include "gebiet.h"
#include "stadt.h"
#include <fstream>
#include <exception>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>

struct StrasseOrder
{
	bool operator() (const Strasse* a, const Strasse* b) const
	{
		return *a < *b;
	}
};

StrasseList::StrasseList() {

}

StrasseList::StrasseList(char* fileName)
{
	ifstream s(fileName);
	try { for (;;) strassen.push_back(s); }
	catch (EOFException) {}
}

vector<Strasse>::iterator StrasseList::end() {
	return strassen.end();
}

vector<Strasse>::iterator StrasseList::begin() {
	return strassen.begin();
}

bool StrasseList::empty() {
	return strassen.size() == 0;
}

void StrasseList::insert(Strasse& g) {
	strassen.push_back(g);
}

StrasseList StrasseList::findErlStrasse(StrasseList erlstrasse, StadtList verbstadt, StrasseList strl)
{
	for (vector<strl>::iterator strasse = strl.strassen.begin(); strasse != strl.strassen.end(); strasse++)
	{
		for (vector<Stadt>::iterator stadt = sl.staedte.begin(); stadt != sl.staedte.end(); stadt++)
		{
			if (stadt->getID() != strasse->getVonStadtId() && stadt->getID() != strasse->getNachStadtId()) {
				erlstrasse.insert(*strasse);
			}
		}
	}
	return erlstrasse;
}

void StrasseList::PrintStrasse(StrasseList sl)
{
	for (vector<Strasse>::iterator it = sl.strassen.begin(); it != sl.strassen.end(); it++)
		cout << it->getVonStadtId << ", " << it->getNachStadtId << "\n";
}
