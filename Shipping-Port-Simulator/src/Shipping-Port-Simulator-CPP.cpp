//============================================================================
// Name        : Shipping-Port-Simulator-CPP.cpp
// Author      : MatthewJaworski
// Version     : 1.0
// Copyright   : Steal this program. I would be flattered.
// Description : Shipping Container Simulator in C++
//============================================================================


#include <iostream>
#include <string>
using namespace std;


//container class

class Container{

public:

	std::string containerType;
	int weight;
	int unitCount;
	std::string conditions;

	Container(std::string type = "None", int wt = 0, int ct = 0, std::string conds = "None"){
		containerType = type;
		weight = wt;
		unitCount = ct;
		conditions = conds;
	}

	~Container(){
		std::cout << "This container has been destroyed." << "\n";
	}

	void emptyContents(){
		weight = 0;
		unitCount = 0;
	}

	void displaySpecs(){
		cout << "\n" << "CONTAINER TYPE: " << containerType << "\n";
		cout << "WEIGHT: " << weight << "\n";
		cout << "UNIT COUNT: " << unitCount << "\n";
		cout << "CONDITIONS: " << conditions << "\n";
		std::string divider (100, '_'); //THIS MUST BE SINGLE QUOTES
		cout << divider << "\n";
	}

};



class L_Container: public Container{

public:


	L_Container(int wt = 0, int ct = 0){
		containerType = "Liquid";
		weight = wt;
		unitCount = ct;
		conditions = {
				"You must use the slow and steady crane.\n"
				"You must use the pump to load a train car.\n"
				"You must load the contents into a liquid tanker train car.\n"
			};
	}

};



class H_Container: public Container{

public:


	H_Container(int wt = 0, int ct = 0){
		containerType = "Hazmat";
		weight = wt;
		unitCount = ct;
		conditions = {
				"You must use the slow and steady crane.\n"
				"You must spend additional time to carefully load the contents onto the train car.\n"
				"You must load the contents into a specially sealed hazmat train car.\n"
			};
	}

};



//Normal Goods Container
class NG_Container: public Container{

public:


	NG_Container(int wt = 0, int ct = 0){
		containerType = "Normal Goods";
		weight = wt;
		unitCount = ct;
		conditions = {
				"You can use any crane.\n"
				"You can just place the whole container onto a train car and secure it.\n"
				"You must load the container on a special flat lockable shipping container car.\n"
			};;
	}

};




//individual container types

//crane class
//processing facility class


int main() {

	L_Container liquid0(100, 525);

	H_Container hazmat0(200, 36);

	NG_Container normal0(300, 1250);


	liquid0.displaySpecs();

	hazmat0.displaySpecs();

	normal0.displaySpecs();

	return 0;
}
