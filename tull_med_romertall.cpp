/* Wrong answer.
 * Score 0/100*/
#include <cstdio>
#include <string>
#include <map>
using namespace std;

map<char,int> value;

int eval(string s)
{
	if (s.length() == 1) return value[s[0]];
	int max_val = 0, max_idx = 0;
	for (int i = 0; i < (int)s.size(); i++)
		if (value[s[i]] > max_val)
			max_val = value[s[i]], max_idx = i;
	if (max_idx == 0) return max_val + eval(s.substr(1,s.length()));
	return eval(s.substr(max_idx,s.length())) - eval(s.substr(0,max_idx));
}

string to_rom(int val)
{
	if (val <= 0) return string("");
	if (val <= 3) return to_rom(val - 1) + "I";
	
	if (val <= 5) return to_rom(5 - val) + "V";
	if (val <= 8) return string("V") + to_rom(val - 5);
	
	if (val <= 10) return to_rom(10 - val) + "X";
	if (val <= 38) return string("X") + to_rom(val - 10);

	if (val <= 50) return to_rom(50 - val) + "L";
	if (val <= 88) return string("L") + to_rom(val - 50);

	if (val <= 100) return to_rom(100 - val) + "C";
	if (val <= 388) return "C" + to_rom(val - 100);

	if (val <= 500) return to_rom(500 - val) + "D";
	if (val <= 888) return "D" + to_rom(val - 500);
	
	if (val <= 1000) return to_rom(1000 - val) + "M";
	return "M" + to_rom(val - 1000);
}

int main()
{
	value['I'] = 1;
	value['V'] = 5;
	value['X'] = 10;
	value['L'] = 50;
	value['C'] = 100;
	value['D'] = 500;
	value['M'] = 1000;

	char a[30],b[30];
	while (scanf("%s %s ", a,b) != EOF)
	{
		string A(a), B(b);
		int ans = eval(A) + eval(B);
		printf("%s\n", to_rom(ans).c_str());	
	}

	return 0;
}
