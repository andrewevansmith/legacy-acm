// Rock Paper Scissors Example

#include <cstdlib>
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

int rps( char p1, char p2 ) {
    if (p1 == p2) return 0;
    if (p1 == 'R') {
        if (p2 == 'P') return 2;
        else return 1; }
    else if (p1 == 'P') {
        if (p2 == 'R') return 1;
        else return 2; }
    else {
        if (p2 == 'R') return 2;
        else return 1; }
}

int main() {
    ifstream inFile("rps.in");
    string p1round;
    string p2round;
    int p1wins;
    int p2wins;
    while ( p1round[0] != 'E' ) {
        p1wins = 0;
        p2wins = 0;
        getline( inFile, p1round );
        if (p1round[0] == 'E') break;
        getline( inFile, p2round );
        for (int i=0; i < p1round.size(); i++) {
            switch (rps(p1round[i],p2round[i])) {
                case 1:
                    p1wins++;
                    break;
                case 2:
                    p2wins++;
                    break;
            }
        }
        cout << "p1: " << p1wins << endl << "p2: " << p2wins << endl;
    }
    return 0;
}
