#include <fstream>
#include <iostream>
#include <string>
using namespace std;

// git add *.cpp *.h *.txt makefile
// git commit -m "insert stuff here"
// git push origin master

#include "congaline.h"
#include "node.h"
#include "pirate.h"

int main () {

    ifstream pirateFile ("portal.txt");
    CongaLine * conga = new CongaLine();
    cout <<"Starting List" << endl;
    conga -> print();
    cout << endl;

    // Command File Stuff
    string command = "";
    int length = 0;
    ifstream commandFile ("commands.txt");
    if (commandFile.is_open()){
        while(!commandFile.eof()){
        commandFile >> command >> length;
        if (command == "tacticalnuke"){
            conga -> tacticalNuke();
            cout << "After Tact Nuke" << endl;
            conga -> print();
            cout << endl;
        } else if (command == "setbar") {
            conga -> setBar(length);
        } else if (command == "lshift" ){
            conga -> lshift(length);
            cout << "After lShift" << endl;
            conga -> print();
            cout << endl;
        } else if (command == "rshift"){
            conga -> rshift(length);
            cout << "After rShift" << endl;
            conga -> print();
            cout << endl;
        } else if (command == "lowerbar") {
            conga -> lowerBar();
        } else if (command == "hammer") {
            conga -> hammer(length);
            cout << "After Hammer" << endl;
            conga -> print();
            cout << endl;
        } else {
            cout << "Command Not Found" << endl;
        }
    }
    }
    cout << "After Command File" << endl;
    conga -> print();


    delete conga;
    
    return 0;
}
