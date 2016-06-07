#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

map<char, bool> getMap(string str)
{
	map<char, bool> char_map;

	for (char ch = 'a'; ch <= 'z'; ++ch)
	{
		char_map[ch] = false;
	}

	int str_len = str.length();
	int char_count = 0;
	for (int i = 0; i < str_len; ++i)
	{
		if (char_count >=26) // if all 26 letters are included, no need to test the remaining ones
		{
			break;
		}

		if (!char_map[str[i]])
		{
			char_map[str[i]] = true;
			char_count++;
		}
	}

	return char_map;
}

int find_gem(vector<string> inputStrings)
{
	int count = 0;
	int str_num = 0;
	int str_len = 0;
	string oneString;

	str_num = static_cast<int>(inputStrings.size());
	vector< map<char, bool> > myMaps;
	map<char, bool> oneMap;
	

	for (int i = 0; i < str_num; ++i)
	{
		oneString = inputStrings[i];
		oneMap = getMap(oneString);
		myMaps.push_back(oneMap);
	}

	bool flag = false;
	for (char ch = 'a'; ch <= 'z'; ++ch)
	{
		for (int i = 0; i < static_cast<int>(myMaps.size()); ++i)
		{
			oneMap = myMaps[i];
			flag = oneMap[ch];
			if (!flag)
			{
				break;
			}
		}
		if (flag)
		{
			count++;
		}
		

	}



	return count;
}


int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */

	string N_str;
	getline(cin, N_str);
	int N = 0;
	N = atoi(N_str.c_str());
	vector<string> myStrings;
	string oneString;
	for (int i = 0; i < N; ++i)
	{
		getline(cin, oneString);
		myStrings.push_back(oneString);

	}

	int gem_count = 0;
	gem_count = find_gem(myStrings);
	cout << gem_count << endl;

	system("pause");
	return 0;
}
