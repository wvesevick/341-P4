#ifndef CONGALINE_H
#define CONGALINE_H

#include <iostream>
#include <fstream>
using namespace std;

#include "pirate.h"
#include "node.h"

// CongaLine will always be of length 20 prior to the execution of core functions
// Semantically, we think of CongaLine as horizontal line, where the head is on the left, and the tail is on the right

class CongaLine {
    private:
        Node * head;
        Node * tail;
        Node * doubleEdgedSword;
        int bar;
        ifstream pirateFile;			// fixed ifstream object that refers to the file "portal.txt"
        ifstream commandFile;			// fixed ifstream object that refers to the file "commands.txt"
        static int piratesMade;
        // Private helper functions
        int length();					// returns the length of the current list. It should be 20 after every core function call
        bool insertAtHead(Pirate);		// insert the new node at the head of the list. Returns true if insertion was successful.
        bool insertAtTail(Pirate);		// insert the new node at the tail of the list. Returns true if insertion was successful.
        Node * search(int);             // takes an integer value i and returns a pointer to the ith element of the list
        bool deleteAtNode(Node *);      // removes the Node indicated by the input. Returns true if delete actually removed an element, false otherwise.
        
    public:
        // Default Constructor/Destructor
        // You should set up the ifstreams in the constructor and remove them in the destructor
        CongaLine(); 
        ~CongaLine();

        Pirate thisPirate;
        
        // get/set style functions
        int getBar();					// returns the curret value of bar
        void setBar(int);               // sets the height of the double-edged sword to the input parameter
        void lowerBar();                // decrements the value of bar by 1. If it's negative, set the bar to 10
		Node * atSword();				// returns a Node * that indicates the Node pointed to by the double-edged sword
        
        // Public core functionality
        void hammer(int);               // takes an integer value from [1, 20] and deletes the node at that list location, then inserts a new pirate at the tail
		void print(int reverse = 0);		// prints the nodes in the CongaLine from head to tail (default). If reverse = 1 is provided, print the list from tail to head
        // For both lshift and rshift, if you are too close to the edge of the array to execute the full shift, do as much as you can and then terminate normally
        void lshift(int);               // moves the double-edged sword to the left and pirates must limbo underneath, inserts replacement pirates at the tail
        void rshift(int);               // moves the double-edged sword to the right and pirates must limbo underneath, inserts replacement pirates at the head
        
        // Reset functions
        void tacticalNuke();            // executes hammer(0) 20 times
}; // end class CongaLine

#endif
