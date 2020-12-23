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
    gl.findSubGebiet(gl.findGebiet(argv[6]), gl);
    StadtList sl(argv[1]);
    for (vector<Gebiet>::iterator gebiet = gl.gebiete.begin(); gebiet != gl.gebiete.end(); gebiet++)
    {
        if (gebiet->verboten == false)
            continue;
        if (sl.findStadt(argv[4])->getGebietId() == gebiet->getID() || sl.findStadt(argv[5])->getGebietId() == gebiet->getID())
        {
            sl.findStadt(argv[5]);
            cout << "Es gibt keine erlaubte Route von " << argv[4] << " nach " << argv[5] << ".\n";
            return(0);
        }
    }
    sl.findVerbStadt(gl, sl);
    StrasseList strl(argv[3]);
    strl.findErlStrasse(sl, strl);
    if (strl.FindeRoute(strl, sl, sl.findStadt(argv[5]), sl.findStadt(argv[4])) == 0)
        cout << "Es gibt keine erlaubte Route von " << argv[4] << " nach " << argv[5] << ".\n";
    return(0);
}

