#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;


int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	string myString = "We promptly judged Antique ivory buckles for the next prize";
//	string myString = "We promptly judged antique ivory buckles for the prize";
	transform(myString.begin(),myString.end(),myString.begin(),::tolower);
	map<char, bool> all_chars;
	int str_len = myString.length();
	for (char ch = 'a'; ch < 'z'; ch++)
	{
		all_chars[ch] = false;
	}
	char temp_char;
	for (int i = 0; i < str_len; ++i)
	{
		temp_char = myString[i];
		if (!all_chars[temp_char])
		{
			all_chars[temp_char] = true;
		}
		
	}

	bool isPangram = true;
	map<char, bool>::const_iterator map_it = all_chars.begin();
	while (map_it != all_chars.end())
	{
		if (!map_it->second)
		{
			isPangram = false;
			break;
		}
		map_it ++;
	}
	
	if (isPangram)
	{
		cout << "pangram" << endl;
	}
	else
		cout << "not pangram" << endl;

	system("pause");

	return 0;
}
