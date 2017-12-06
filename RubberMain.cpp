//Christopher Morgan
//Project 6/7
//11/9/2017
//CISP 400 Tues/Weds
#include "RubberArray.h"
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	RubberArray<int> newvec(100);
	//RubberArray<int> newvec1(0);

	try {
		for (unsigned i = 0; i<50; ++i)
		{
			newvec.append(i);
			cout << newvec << endl;
    }

		for (unsigned i = 50; i>0; --i)
		{
			newvec.remove();
			cout << newvec << endl;
    }
		//newvec.add(10000);
		//newvec.add(3,55);
		//cout << "Number of items in array: ";
		//cout << newvec.length();
		//cout << endl << endl;

		//cout << newvec << endl;
    //newvec.remove();
		//cout << newvec << endl;

   // newvec1 = newvec(0,10);

		//cout << newvec1;

	}catch(unsigned a)
	{
	cerr << a << endl;
	}
return 0;
}

