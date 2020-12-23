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
	int boo;

	for (vector<Strasse>::iterator strasse = strl.strassen.begin(); strasse != strl.strassen.end(); strasse++)
	{
		boo = 1;
		for (vector<Stadt>::iterator stadt = verbstadt.staedte.begin(); stadt != verbstadt.staedte.end(); stadt++)
		{
			if (stadt->getID() == strasse->getVonStadtId() || stadt->getID() == strasse->getNachStadtId()) {
				boo = 0;
				break;
			}
		}
		if(boo==1)
			erlstrasse.insert(*strasse);
	}
	return erlstrasse;
}

int StrasseList::FindeRoute(StrasseList erlStrasse, StadtList sl, vector<Stadt>::iterator startstadt, vector<Gebiet>::iterator zielstadt)
{
    if (startstadt->getID() == zielstadt->getID())
    {
        fprintf(stderr, "%s\n", startstadt->getName());
        return 1;
    }
	for (vector<Strasse>::iterator strasse = erlStrasse.strassen.begin(); strasse != erlStrasse.strassen.end(); strasse++)
	{
        if (strasse->vonStadtId() == 0 || strasse->nachStadtId() == 0)
            continue;
        else if (startstadt->getID() == strasse->getVonStadtId)
        {
            if (FindeRoute(erlStrasse, sl, sl.findStadt(strasse->getNachStadtId), zielstadt) == 1)
            {
                cout << "\n" << startstadt->getName();
                return 1;
            }
        }
        else if (startstadt->getID == strasse->getNachStadtId)
        {
			if (FindeRoute(erlStrasse, sl, sl.findStadt(strasse->getVonStadtId), zielstadt) == 1)
			{
				cout << "\n" << startstadt->getName();
				return 1;
            }
        }
    }
    return 0;
}

void StrasseList::PrintStrasse(StrasseList strl)
{
	for (vector<Strasse>::iterator it = strl.strassen.begin(); it != strl.strassen.end(); it++)
		cout << it->getVonStadtId() << ", " << it->getNachStadtId() << "\n";
}
