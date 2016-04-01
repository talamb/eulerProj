/*----------------------------------------------
 * filename: question12.cpp
 * developer: Drew Lamb
 *
 * created on: 4/1/16
 * last updated: 4/1/16
 *
 * description: Find the first triangle number with number of divisor greater
 * 	than the first argument
 * ---------------------------------------------*/

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <sstream>

using namespace std;

int questionSolution(int);
int divisorCalc(int);

int main(int argc, char* argv[])
{
	int target;
	
	//see if an argument is supplyed
	if(argc < 2)
	{
		cout << argv[0] << " needs a number as an argument. EX: question12.exe 32"<< endl;
		exit(0);
	}

	//see if the argument is a valid positive integer.
	//create istringstring here to avoid errors
	istringstream ss(argv[1]);

	if(!(ss >> target) || (target < 1) )
	{
		cout << argv[1] << " is an invalid argument."
		<< endl << "Please supply a positive integer." << endl;
	}

	cout << questionSolution(target);

	return 0;
}

//returns the fist triangle number that has a greater number of divisors than the target.
int questionSolution(int target)
{
	int triSequ = 1;
	int divisors = 2;	

	if(target == 1) { return 3;}

	//main loop  first part itterates through the triangle sequence
	for(int i = 2; ; i++)
	{
		triSequ += i;
		
		//calcs the num of divisors of the triSequ
		divisors = divisorCalc(triSequ);

		//returns the fist triangle number with a greater num of divisors than the target.
		if(divisors > target) {return triSequ;}
	}
}

//returns the number of divisors of the num supplied
int divisorCalc(int num)
{
	int divisors = 1;
	int squaroot = ceil(sqrt(num));

	for(int i = 2; i < squaroot; i++)
	{
		if(!(num % i))
		{
			divisors++;
		}
	}

	if(squaroot == floor(sqrt(num)))
	{
		divisors = (divisors * 2) - 1;
	}
	else
	{
		divisors *= 2;
	}
	
	return divisors;
}

