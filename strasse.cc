#include "strasse.h"
#include "gebiet.h"
#include "stadt.h"

#include <fstream>
#include <exception>
#include <string>
#include <iomanip>
#include <vector>

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

void StrasseList::findErlStrasse(StadtList sl, StrasseList &strl)
{
	bool erlaubt;

	for (vector<Strasse>::iterator strasse = strl.strassen.begin(); strasse != strl.strassen.end(); strasse++)
	{
		erlaubt = true;
		for (vector<Stadt>::iterator stadt = sl.staedte.begin(); stadt != sl.staedte.end(); stadt++)
		{
			if (stadt->getID() == strasse->getVonStadtId() || stadt->getID() == strasse->getNachStadtId()) {
				if (stadt->verboten == true)
				{
					erlaubt = false;
					break;
				}
			}
		}
		if (erlaubt == true)
			(*strasse).verboten = false;
	}
}

int StrasseList::FindeRoute(StrasseList strl, StadtList sl, vector<Stadt>::iterator startstadt, vector<Stadt>::iterator zielstadt)
{
    if (startstadt->getID() == zielstadt->getID())
    {
        cout << startstadt->getName() << "\n";
        return 1;
    }
	for (vector<Strasse>::iterator strasse = strl.strassen.begin(); strasse != strl.strassen.end(); strasse++)
	{
		if (strasse->verboten == true)
			continue;
		else if (strasse->besuchtVonStadt == true || strasse->besuchtNachStadt == true)
            continue;
        else if (startstadt->getID() == strasse->getVonStadtId())
        {
			(*strasse).besuchtVonStadt=true;
            if (FindeRoute(strl, sl, sl.findStadt(strasse->getNachStadtId()), zielstadt) == 1)
            {
                cout << startstadt->getName() << "\n";
                return 1;
            }
        }
        else if (startstadt->getID() == strasse->getNachStadtId())
        {
			(*strasse).besuchtNachStadt=true;
			if (FindeRoute(strl, sl, sl.findStadt(strasse->getVonStadtId()), zielstadt) == 1)
			{
				cout << startstadt->getName() << "\n";
				return 1;
            }
        }
    }
    return 0;
}