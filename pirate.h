#ifndef PIRATE_H
#define PIRATE_H

#include <iostream>
#include <string>
using namespace std;

// You need to apply some care when building the .cpp, but the .h should not need to change.
class Pirate {
    public:
        string name;                    // this pirate's name
        unsigned int height;            // height of this pirate
        int numLimbos;                  // number of successful limbos for this pirate
        static int numDead;             // total number of dead pirates across the entire program
        
        // Basic class setup
        Pirate();
        ~Pirate();
        
        // Core functionality
        bool canLimbo(int h) {return height <= h;}
        void print() {cout << name << " " << height << " " << numLimbos << endl;}
        void initialize(string n, int h);
}; // end class Pirate

#endif
