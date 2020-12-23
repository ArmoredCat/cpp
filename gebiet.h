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
	verboten = false;
  }

  int getID() const { return id; }
  string getName() const { return name; }
  int getObergebietid() const { return obergebietid; }

  bool verboten;

private:
  unsigned id;
  string name;
  unsigned obergebietid;
  string typ;
};

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
	void findSubGebiet(vector<Gebiet>::iterator g, GebietList &gl);
	
	vector<Gebiet> gebiete;

private:

};

#endif