#include "gebiet.h"
#include <fstream>
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
		cout << "(" << it->getName() << ", " << it->getID() << ", " << it->getObergebietid() << ")\n";
		if (it->getName().compare(name) == 0)
			return it;
	}
	cout << "Das eingegebene Gebiet '" << name << "' existiert nicht!\n";
	exit(1);
}	

GebietList GebietList::findSubGebiet(vector<Gebiet>::iterator g, GebietList verbgeb, GebietList gl)
{
	for (vector<Gebiet>::iterator it = gl.gebiete.begin(); it != gl.gebiete.end(); it++)
	{
		if (it->getObergebietid() == g->getID()) {
			cout << "AAAAAAAAAAAAAARRRRRRRRRRRRRRRRFFFFFFFFFFFFFF\n";
			verbgeb.insert(*it);
			PrintGebiet(verbgeb);
			verbgeb=findSubGebiet(it, verbgeb, gl);
		}
	}
	return verbgeb;
}

void GebietList::PrintGebiet(GebietList verbgeb)
{
	for (vector<Gebiet>::iterator it = verbgeb.gebiete.begin(); it != verbgeb.gebiete.end(); it++)
		cout << it->getName() << "\n";
}
