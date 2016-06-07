#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

bool find_common_substring(string str1, string str2)
{
	map<char, bool> map_str1;
	map<char, bool> map_str2;

	for (char ch = 'a'; ch <= 'z'; ++ch)
	{
		map_str1[ch] = false;
		map_str2[ch] = false;
	}

	int cnt1 = 0, cnt2 = 0;
	for (int i = 0; i < str1.length(); ++i)
	{
		if (cnt1 <= 26)
		{
			map_str1[str1[i]] = true;
			cnt1++;
		}
		else
			break;
	}

	for (int i = 0; i < str2.length(); ++i)
	{
		if (cnt2 <= 26)
		{
			map_str2[str2[i]] = true;
			cnt2++;
		}
		else
			break;
	}

	if (str1.length() < str2.length())
	{
		for (int i = 0; i < str1.length(); ++i)
		{
			if (map_str2[str1[i]])
			{
				return true;
			}
		}
		return false;
	}
	else
	{
		for (int i = 0; i < str2.length(); ++i)
		{
			if (map_str1[str2[i]])
			{
				return true;
			}
		}
		return false;

	}

}

int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	// the shortest substring includes only one letter

	string T_str;
	getline(cin, T_str);
	int T = atoi(T_str.c_str());
	string str1, str2;

	for (int i = 0; i < T; ++i)
	{
		getline(cin, str1);
		getline(cin, str2);
		if (find_common_substring(str1, str2))
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
			

	}


	
	system("pause");
	return 0;
}
