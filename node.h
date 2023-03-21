#ifndef NODE_H
#define NODE_H

#include "pirate.h"

// Node is a doubly-linked list, with all of its variables declared as public.
// Don't do that in general, but for this project, we're ok with it!

class Node {
    public:
        Pirate pirate;
        Node * next;
        Node * prev;
        
        // Boilerplate class structure
        // You will need to define the default constructor/deconstructor
        Node();
        Node(const Pirate & p) : pirate(p), next(NULL), prev(NULL) {}
        ~Node();
}; // end class Node

#endif
