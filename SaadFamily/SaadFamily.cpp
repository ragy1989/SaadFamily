// SaadFamily.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

using namespace std;
#include <iostream>
#include "Sara.h"
#include "Linda.h"
#include "Queen.h"
#include "AboHashima.h"

#include <iostream>
#include <functional>
#include <string>
#include <cmath>  

int main()
{
	char nts1[] = "Test";
	char nts2[] = "Test";
	std::string str1(nts1);
	std::string str2(nts2);

	std::hash<char*> ptr_hash;
	std::hash<std::string> str_hash;

	auto hashed = str_hash(str1);


	AboHashima<std::string, std::string> abo(16);
	abo.add("ragy", "software");
	abo.add("atef", "pharam");
	abo.add("zaky", "eng");
	cout<<abo.exists("atef"); cout << abo.exists("ragy");
	abo.remove("atef"); abo.remove("ragy");
	cout << '\n';
	abo.data();



	
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
