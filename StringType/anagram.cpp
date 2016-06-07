#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

map<char, int> getMap(string str)
{
	map<char, int> str_map;
	for (char ch = 'a'; ch <= 'z'; ++ch)
	{
		str_map[ch] = 0;
	}

	for (int i = 0; i < str.length(); ++i)
	{
		str_map[str[i]]++;
	}

	return str_map;
}

int compute_anagram(string inputString)
{
	int count = 0;
	int str_len = inputString.length();
	string str1, str2;
	str1 = inputString.substr(0, str_len / 2);
	str2 = inputString.substr(str_len / 2, str_len / 2);
	
	map<char, int> str1_map;
	map<char, int> str2_map;

	str1_map = getMap(str1);
	str2_map = getMap(str2);

	for (char ch = 'a'; ch <= 'z'; ++ch)
	{
		count += abs(str1_map[ch] - str2_map[ch]);
	}

	count = count / 2;

	return count;
}


int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	string T_str;
	getline(cin,T_str);
	int T = atoi(T_str.c_str());
	int count = 0;
	string myString;
	for (int i = 0; i < T; ++i)
	{
		count = -1;
		getline(cin, myString);
		if (myString.length() % 2)
		{
			cout << count << endl;
		}
		else
		{
			count = compute_anagram(myString);
			cout << count << endl;
		}
	}

	system("pause");
	return 0;
}
