#include"ZOO.h"
#include<iostream>
#include<random>
#include<ctime>
#include<cstdlib>
#include<cmath>
#include<fstream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;
int main()
{

	Elephant* elephantarr= new Elephant[1];
	Giraffe* giraffearr=new Giraffe[2];
	Monkey* monkeyarr=new Monkey[3];
	AnimalEnclosure animalenclosure_elephant;
	AnimalEnclosure animalenclosure_giraffe; 
	AnimalEnclosure animalenclosure_monkey;
	zoo zoo1;
	zoo1.simulation_all(elephantarr, giraffearr, monkeyarr,animalenclosure_elephant, animalenclosure_giraffe, animalenclosure_monkey);
}