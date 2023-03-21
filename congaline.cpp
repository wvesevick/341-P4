/*
print(int) ----
insertAtTail(Pirate) ----
search(int) ----
insertAtHead(Pirate) ----
deleteAtNode(Node *)
*/



#include "congaline.h"
#include "node.h"
#include "pirate.h"
int CongaLine::piratesMade = 0;

CongaLine::CongaLine(){
  head = nullptr;
  tail = nullptr;
  doubleEdgedSword = nullptr;
  bar = 0;
  //ifstream pirateFile ("portal.txt");
  ifstream commandFile ("commands.txt");
  Pirate thisPirate = Pirate();
  for(int x = 0; x < 20; x++){
    pirateFile >> thisPirate.name >> thisPirate.height;
    insertAtTail(thisPirate);
  }
  Node * swordStart = search(9);
  doubleEdgedSword = swordStart;
}

CongaLine::~CongaLine(){
  Node * currentDelete = head;
  while (currentDelete != nullptr) {
    Node * nextDelete = currentDelete -> next;
    delete currentDelete;
    currentDelete = nextDelete;
  }
}

int CongaLine::getBar(){
    return bar;
}

void CongaLine::setBar(int newHeight){
    bar = newHeight;
}

void CongaLine::lowerBar(){
    if(bar > 0) {
        bar -= 1;
    } else {
        bar = 10;
    }
}

Node * CongaLine::atSword(){
    return doubleEdgedSword;
}

int CongaLine::length(){
    int length = 0;
    Node * iterator = head ;

    while (iterator != nullptr){
        length ++;
        iterator = iterator -> next;
    }
    return length;
}
// prints the nodes in the CongaLine from head to tail (default). 
//If reverse = 1 is provided, print the list from tail to head
void CongaLine::print(int reverse){
    if (reverse == 0){
        Node *printNode = head;
        cout << "Head to Tail Order: " << endl;
        int pirates = 0;
        while(printNode != nullptr){
            cout << printNode->pirate.name << " -> ";
            pirates ++;
            if(pirates == 10){
                cout << endl;
                pirates = 0;
            }
            printNode = printNode -> next;
        }
    } else {
        Node *printNode = tail;
        cout << "Tail to Head Order: " << endl;
        int pirates = 0;
        while(printNode != nullptr){
            cout << printNode->pirate.name << " <- ";
            pirates ++;
            if(pirates == 10){
                cout << endl;
                pirates = 0;
            }
            printNode = printNode -> prev;
        }
    }
}

bool CongaLine::insertAtTail(Pirate newPirate){
  ifstream pirateFile ("portal.txt");
  for(int x = 0; x <= piratesMade; x++){
    pirateFile >> newPirate.name >> newPirate.height;
  }
  piratesMade ++;
  Node * newNode = new Node(); // creates the blank node to add
  //pirateFile >> newPirate.name >> newPirate.height;
  newNode -> pirate = newPirate; // sets the new node pirate to whatever passed in

  if (head == nullptr){
    head = newNode;
    tail = newNode;
  } else {
    tail -> next = newNode;
    newNode -> prev = tail;
    tail = newNode;
  }
  return true;
}

bool CongaLine::insertAtHead(Pirate newPirate){
  ifstream pirateFile ("portal.txt");
  for(int x = 0; x <= piratesMade; x++){
    pirateFile >> newPirate.name >> newPirate.height;
  }
  piratesMade ++;
  Node * newNode = new Node(); // creates the blank node to add
  //pirateFile >> newPirate.name >> newPirate.height;
  newNode -> pirate = newPirate; // sets the new node pirate to whatever passed in
  
  if (head == nullptr){
    head = newNode;
    tail = newNode;
  } else {
    head -> prev = newNode;
    newNode -> next = head;
    head = newNode;
  }
  return true;
}

bool CongaLine::deleteAtNode(Node * toDelete){
	if (head == nullptr) {
		return false;
	} else {
		if (toDelete == head){ // this works I think
        Node * tempPtr = head->next;
        delete head;
        head = tempPtr;
        insertAtTail(thisPirate);
        return true;
	} else if (toDelete == tail) { // this works I think
        Node * tempPtr = tail -> prev;
        delete tail;
        tail = tempPtr;
        insertAtTail(thisPirate);
        return true;
	} else {
        Node * nextPtr = toDelete -> next;
        Node * pastPtr = toDelete -> prev;
        pastPtr -> next = nextPtr;
        nextPtr -> prev = pastPtr;
        delete toDelete;
        insertAtTail(thisPirate);
	    }
	}
	return true;
}

Node * CongaLine::search(int toFind){
  if(head == nullptr){
    // checking for empty list
    return nullptr;
  } else {
    Node * currentNode = head;
    for(int x = 0; x < toFind; x++){
      currentNode = currentNode -> next;
    }
    //cout << "Found Pirate: " << currentNode -> pirate.name << endl;
    return currentNode;
  }
}

//hammer, tacticalNuke, lshift, rshift
void CongaLine::hammer(int hammer){
  Node * toDelete = search(hammer);
  deleteAtNode(toDelete);
}

void CongaLine::tacticalNuke(){
  for(int x = 0; x < 20; x++){
    hammer(0);
  }
  Node * swordStart = search(9);
  doubleEdgedSword = swordStart;

}

void CongaLine::lshift(int shift){
  int bar = getBar();
  int shifted = 0;
  while(doubleEdgedSword != nullptr && shifted < shift){
    if(doubleEdgedSword -> pirate.height < bar){
      Node * toCheck = doubleEdgedSword;
      doubleEdgedSword = doubleEdgedSword -> prev;
      deleteAtNode(toCheck);
      shifted++;
    } else {
      doubleEdgedSword = doubleEdgedSword -> prev;
      shifted ++;
    }
  }
}

void CongaLine::rshift(int shift){
  int barHeight = getBar();
  int shifted = 0;
  while(doubleEdgedSword != nullptr && shifted < shift){
    if (doubleEdgedSword -> pirate.height < bar) {
      Node * toCheck = doubleEdgedSword;
      doubleEdgedSword = doubleEdgedSword -> next;
      deleteAtNode(toCheck);
      shifted ++;
    } else {
      doubleEdgedSword = doubleEdgedSword -> next;
      shifted ++;
    }
  }
}
