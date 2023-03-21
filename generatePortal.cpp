#include <fstream>
#include <iostream>
using namespace std;

int main (){
    //Minimum and maximum heights of generated pirates
	int min_height = 1;
	int max_height = 20;

	//how many pirates to generate
	int num_pirates = 200;

	ofstream writer("portal.txt"); //create portal.txt and load it into our ofstream object

	for (int i = 0; i < num_pirates; i++)
	{
		//sets random height between range and writes that pirate to the file
		int random_height = min_height + rand() % max_height;
		writer << "Pirate_" << i << " " << random_height << "\n";
	}

	writer.close();
}
