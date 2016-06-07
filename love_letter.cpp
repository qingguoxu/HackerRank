#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int love_letter(string inputString)
{
	int count = 0;
	int str_len = inputString.length();
	int left = 0, right = 0;
	if (str_len % 2) // odd 
	{
		left = str_len / 2 - 1;
		right = str_len / 2 + 1;

	}
	else // even
	{
		left = str_len / 2 - 1;
		right = str_len / 2;
	}

	while (left >= 0) // same as right <= str_len
	{
		if ( inputString[left] == inputString[right] )
		{
			left--;
			right++;
		//	continue;
		}
		else
		{
			count += abs( inputString[left] - inputString[right] );
			left--;
			right++;
		}


	}



	return count;
}


int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */

	string T_str;
	cout << "input number:" << endl;
	getline(cin, T_str);
	int T = 0;
	T = atoi(T_str.c_str());

	string myString;
	int count = 0;

	for (int i = 0; i < T; ++i)
	{
		cout << "input string:" << endl;
		getline(cin, myString);
//		cout << myString << endl;
		count = love_letter(myString);
		cout << count << endl;
	}

	system("pause");
	return 0;
}
