#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool funny_string(string inputString)
{
	bool isFunny = false;
	string inverseString;
	int str_len = inputString.length();
	int originalValue = 0, reversedValed = 0;
	for (int i = 1; i < str_len; ++i)
	{
		originalValue = abs(inputString[i] - inputString[i - 1]);
		reversedValed = abs(inputString[str_len - i] - inputString[str_len - i - 1]);
		if (originalValue != reversedValed)
		{
			isFunny = false;
			break;
		}
		isFunny = true;
	}


	return isFunny;
}


int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	string T_str;
	getline(cin, T_str);
	int T = atoi(T_str.c_str());
	string myString;
	for (int i = 0; i < T; ++i)
	{
		getline(cin, myString);
		if ( funny_string(myString) )
			cout << "Funny" << endl;
		else
			cout << "Not Funny" << endl;
		
	}


	system("pause");
	return 0;
}
