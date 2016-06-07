#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int alternate_characters(string inputString)
{
	int count = 0;
	int str_len = inputString.length();
	int left = 0, right = 0;
	for (left = 0, right = 1; right < str_len;)
	{
		if (inputString[left] == inputString[right] )
		{
			right++;
			count++;
		}
		else
		{
		//	count += right - left - 1;
			left = right;
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
		count = alternate_characters(myString);
		cout << count << endl;
	}

	system("pause");
	return 0;
}
