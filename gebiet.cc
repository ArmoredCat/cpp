#include "gebiet.h"
#include <exception>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>

struct GebietOrder
{
	bool operator() (const Gebiet* a, const Gebiet* b) const
	{
		return *a < *b;
	}
};

GebietList::GebietList() {

}

GebietList::GebietList(char* fileName)
{
	ifstream s(fileName);
	try { for (;;) gebiete.push_back(s); }
	catch (EOFException) {}
}

vector<Gebiet>::iterator GebietList::end() {
	return gebiete.end();
}

vector<Gebiet>::iterator GebietList::begin() {
	return gebiete.begin();
}

bool GebietList::empty() {
	return gebiete.size() == 0;
}

void GebietList::insert(Gebiet& g) {
	gebiete.push_back(g);
}

vector<Gebiet>::iterator GebietList::findGebiet(string name)
{
	for (vector<Gebiet>::iterator it = gebiete.begin(); it != gebiete.end(); it++)
	{
		if (it->getName().compare(name) == 0)
			return it;
	}
	cout << "Das eingegebene Gebiet '" << name << "' existiert nicht!\n";
	exit(1);
}

void GebietList::findSubGebiet(vector<Gebiet>::iterator g, GebietList &gl)
{
	(*g).verboten=true;
	for (vector<Gebiet>::iterator it = gl.gebiete.begin(); it != gl.gebiete.end(); it++)
	{
		if (it->getObergebietid() == g->getID()) {
			findSubGebiet(it, gl);
		}
	}
}