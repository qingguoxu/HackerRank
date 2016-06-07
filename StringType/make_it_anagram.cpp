#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

int make_it_anagram(string str1, string str2)
{
	int count = 0;
	map<char, int> map_str1;
	map<char, int> map_str2;

	for (char ch = 'a'; ch <= 'z'; ++ch)
	{
		map_str1[ch] = 0;
		map_str2[ch] = 0;
	}

	for (int i = 0; i < str1.length(); ++i)
	{
		map_str1[str1[i]] ++;
	}

	for (int i = 0; i < str2.length(); ++i)
	{
		map_str2[str2[i]] ++;
	}

	for (char ch = 'a'; ch <= 'z'; ++ch)
	{
		count += abs( map_str1[ch] - map_str2[ch] );
	}

	return count;
}

int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	string str1, str2;
	getline(cin, str1);
	getline(cin, str2);

	int count = 0;
	
	count = make_it_anagram(str1, str2);
	
	cout << count << endl;

	system("pause");
	return 0;
}
