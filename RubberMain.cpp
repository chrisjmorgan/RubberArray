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
	RubberArray<char> newvec(0);
	//RubberArray<int> newvec1(0);

	try {
   
  for (unsigned i = 'A'; i < 'A' + 26; ++i)
	{
		newvec.append(i);
	}

	ofstream fout ("test.txt" , ios::out | ios::binary);
	newvec.write(fout);
	fout.close();


	ifstream fin("test.txt" , ios::in | ios::binary);
	RubberArray<char> new1(0);
	new1.read(fin);
	cout << new1 << endl;

	cout << newvec << endl;

	}catch(unsigned a)
	{
	cerr << a << endl;
	}
return 0;
}

