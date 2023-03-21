#include "pirate.h"

int Pirate::numDead = 0;
using namespace std;

Pirate::Pirate(){
  name = "";
  height = 0;
  numLimbos = 0;
}

Pirate::~Pirate(){
  numDead ++;
}

void Pirate::initialize(string n, int h){
    name = n;
    height = h;
}
