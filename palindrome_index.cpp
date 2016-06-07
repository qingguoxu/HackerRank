#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool isPalindrome(string str)
{
	bool flag = true; 

	int left = 0, right = str.length() - 1;
	while (left < right)
	{
		if (str[left] != str[right])
		{
			flag = false;
			break;
		}

		left++;
		right--;
	}


	return flag;
}

int find_index(string inputString)
{
	int index = -1;
	int str_len = inputString.length();
	int left = 0, right = str_len - 1;

	while ((left < right) && (inputString[left] == inputString[right]))
	{
		left++;
		right--;
	}
	
	if (left < right) // inputString[left] != inputString[right]
	{
		string sub_string1 = inputString.substr(0, left) + inputString.substr(left + 1, str_len - left - 1);
		if ( isPalindrome(sub_string1) )
		{
			index = left;
		}

		string sub_string2 = inputString.substr(0, right) + inputString.substr(right + 1, str_len - right - 1);
		if (isPalindrome(sub_string2))
		{
			index = right;
		}
	}

	return index;
}


int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	string T_str;
	getline(cin, T_str);
	int T = atoi(T_str.c_str());
	int index = 0;
	string myString;

	for (int i = 0; i < T; ++i)
	{
		getline(cin, myString);
		index = find_index(myString);
		cout << index << endl;
	}

	system("pause");
	return 0;
}
