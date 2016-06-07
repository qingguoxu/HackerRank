#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int game_of_thrones(string inputString)
{
	int flag = 1;
	map<char, int> map_str;
	for (char ch = 'a'; ch <= 'z'; ++ch)
	{
		map_str[ch] = 0;
	}

	for (int i = 0; i < inputString.length(); ++i)
	{
		map_str[inputString[i]]++;
	}

	int odd_count = 0;
	for (char ch = 'a'; ch <= 'z'; ++ch)
	{
		if (map_str[ch] % 2) // odd number
		{
			odd_count++;
		}

		if (odd_count > 1)
		{
			flag = 0;
			break;
		}
		
	}

	return flag;
}

// can only have at most 1 letters that have odd count number
int main() {

	string s;
	cin >> s;

	int flag = 0;
	// Assign Flag a value of 0 or 1 depending on whether or not you find what you are looking for, in the given string 

	flag = game_of_thrones(s);

	if (flag == 0)
		cout << "NO" << endl;
	else
		cout << "YES" << endl;

	system("pause");
	return 0;
}
