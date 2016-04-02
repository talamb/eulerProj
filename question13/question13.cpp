/*------------------------------------------------------
 * Filename: question13.cpp
 * Developer: Drew Lamb
 *
 * Created On: 4/1/16
 * Last Updated: 4/2/16
 *
 * Description: Prints the first 10 digits of the sum of a very large number.
 * ---------------------------------------------------------*/

#include <iostream>
#include <cstdlib>//for stol
#include <fstream>
#include <string>
#include <math.h>

using namespace std;

int main(int argc, char* argv[])
{
	//make sure the file is supplied
	if(argc < 2)
	{
		cout<< argv[0] << " requires a file for argument."<< endl;
	}

	short sum[50];
	ifstream fin(argv[1]);
	string cur_num;
	int overflow = 0;

	//initialize sum
	for(int i = 0; i < 50 ; i++)
	{
		sum[i] = 0;
	}
	
	//itterated through the file.
	while(getline(fin, cur_num))
	{
		bool carry = false;
		//simple 3 bit adder.
		for(int i = 49; i >= 0; i--)
		{
			
			//for what ever reason the conversion to short adds 48 to the number.
			sum[i] += (short) cur_num[i] - 48;
			
			//at most an addition can be 9 + 9 + 1 or 19.
			if(carry) 
			{
				sum[i]++;
				carry = false;
			}

			if(sum[i] >= 10)
			{
				carry = true;
				sum[i] -= 10;
			}

		}


		//it's possible to make the sum array 53 long and do addition for the cary at this point but this is less bulky.
		if(carry) overflow++;


	}

	if(overflow > 0)
	{
		cout<< overflow;
	}

	//possible to have a lot of leading 0's, but i'm lazy and this works.
	for( int i = 0; i <50; i++)
	{
		cout<< sum[i];
	}

	cout<< endl;

	return 0;	
	
}
