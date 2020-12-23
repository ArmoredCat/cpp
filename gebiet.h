#ifndef GEBIET_H
#define GEBIET_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>
#include <iomanip>

using namespace std;

class EOFException {};

class Gebiet
{
public:
  Gebiet (istream &s)
  { s >> id >> name >> obergebietid >> typ;
    if (!s)  throw EOFException ();  // abort constructor!
    replace_if (name.begin (), name.end (), bind2nd (equal_to<char> (), '_'), ' ');
    replace_if (typ.begin (), typ.end (), bind2nd (equal_to<char> (), '_'), ' ');
  }

  Gebiet (unsigned pId) { id = pId; }  // for comparisons

  void print (ostream &o = cout) const
  { o << name << " (" << obergebietid << ", " << typ << ")\n"; }

  bool operator< (const Gebiet &g) const  { return id < g.id; }

  bool printOrder (const Gebiet *g) const
  { if (obergebietid < g->obergebietid) return true;
    if (obergebietid > g->obergebietid) return false;
    if (typ < g->typ) return true;
    if (typ > g->typ) return false;
    if (name < g->name) return true;
    if (name > g->name) return false;
    return false;
  }

  int getID() const { return id; }
  string getName() const { return name; }
  int getObergebietid() const { return obergebietid; }
  string getTyp() const { return typ; }

private:
  unsigned id;
  string name;
  unsigned obergebietid;
  string typ;
};

inline ostream &operator<< (ostream &o, const Gebiet &g)
{ g.print (o);  return o; }


class GebietList
{
public:
	GebietList(char* fileName);
	GebietList();

	vector<Gebiet>::iterator findGebiet(string name);
	vector<Gebiet>::iterator end();
	vector<Gebiet>::iterator begin();
	bool empty();
	void insert(Gebiet& p);
	GebietList findSubGebiet(vector<Gebiet>::iterator g, GebietList verbgeb, GebietList gl);
	void PrintGebiet(GebietList verbgeb);
	
	vector<Gebiet> gebiete;

private:

};

#endif

