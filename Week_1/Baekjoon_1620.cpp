#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int input_1, input_2; 
	map<int, string> name_1; map<string, int> name_2;
	string str;
	cin >> input_1 >> input_2;
	for (int i = 0;i < input_1;i++) {
		cin >> str;
		name_1[i] = str; name_2[str] = i;
	}
	for (int i = 0;i < input_2;i++) {
		cin >> str;
		if (atoi(str.c_str())) {
			cout << name_1[atoi(str.c_str()) - 1] << '\n';
		}
		else {
			cout << name_2[str] + 1 << '\n';
		}
	}
}
