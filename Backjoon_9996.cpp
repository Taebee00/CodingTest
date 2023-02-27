#include <bits/stdc++.h>
using namespace std;

int main()
{
	int num; string pattern, pattern_front, pattern_back; string file[100]; 
	cin >> num;
	cin >> pattern;
	for (int i = 0;i < pattern.length();i++) {
		if (pattern[i] == '*') {
			pattern_front = pattern.substr(0, i);
			pattern_back = pattern.substr(i + 1, pattern.length());
		}
	}
	for (int i = 0;i < num;i++) {
		cin >> file[i];
	}
	for (int i = 0;i < num;i++) {
		bool flag = 1;
		for (int j = 0;j < pattern_front.length();j++) {
			if (file[i][j] != pattern_front[j]) {
				flag = 0;
				break;
			}
		}
		for (int j = 1;j <= pattern_back.length() && flag==1 ;j++) {
			if (file[i][file[i].length() - j] != pattern_back[pattern_back.length() - j]) {
				flag = 0;
				break;
			}
		}
		if (flag == 1 && (file[i].length() - pattern_back.length() >= pattern_front.length())) {
			cout << "DA" << endl;
		}
		else cout << "NE" << endl;
	}
}
