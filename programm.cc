#include "gebiet.h"
#include <iostream>

using namespace std;

int main (int argc, char *argv[])
{
  if (argc < 3)
  { cerr << "usage: programm <gebietfile> gebiet\n";
    exit (1);
  }
  GebietList gl (argv[1]);
  GebietList verbgeb;
  verbgeb.insert(*gl.findGebiet(argv[2])); 
  verbgeb = gl.findSubGebiet(gl.findGebiet(argv[2]), verbgeb, gl);
  cout << "\n";
  verbgeb.PrintGebiet(verbgeb);
}

