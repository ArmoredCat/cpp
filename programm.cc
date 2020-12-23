#include "gebiet.h"
#include "stadt.h"
#include "strasse.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    if (argc < 6)
    {
        cerr << "usage: programm <gebietfile> gebiet\n";
        exit(1);
    }
    GebietList gl(argv[2]);
    GebietList verbgeb;
    verbgeb.insert(*gl.findGebiet(argv[6]));
    verbgeb = gl.findSubGebiet(gl.findGebiet(argv[6]), verbgeb, gl);
    StadtList sl(argv[1]);
    StadtList verbstadt;
    verbstadt = verbstadt.findVerbStadt(verbstadt, verbgeb, sl);
    StrasseList strl(argv[3]);
    StrasseList erlstrasse;
    erlstrasse = erlstrasse.findErlStrasse(erlstrasse, verbstadt, strl);
    erlstrasse.PrintStrasse(erlstrasse);
    if (FindeRoute(erlStrasse, sl, sl.findStadt(argv[5]), sl.findStadt(argv[4])) == 0)
        cout << "Es gibt keine erlaubte Route von " << argv[4] << " nach " << argv[5]) << ".\n";
}

