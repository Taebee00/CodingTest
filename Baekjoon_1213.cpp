#include <bits/stdc++.h>
using namespace std;

int main()
{
	string str, ret="", ret_reverse;
	cin >> str;
	map<char, int> _map;
	if (str.length() % 2 == 0) {	
		for (auto& i : str) {
			if (_map[i] >= 0) {
				_map[i]++;
			}
			else {
				_map[i] = 0;
			}
		}
		for (auto& i : _map) {
			if (i.second % 2 != 0) {
				cout << "I'm Sorry Hansoo";
				return 0;
			}
		}
		for (auto& i : _map) {
			i.second /= 2;
		}
		for (auto& i : _map) {
			while (i.second > 0) {
				ret += i.first;
				i.second--;
			}
		}
		cout << ret;
		reverse(ret.begin(),ret.end());
		cout << ret;
	}
	else {
		for (auto& i : str) {
			if (_map[i] >= 0) {
				_map[i]++;
			}
			else {
				_map[i] = 0;
			}
		}
		int cnt = 0;
		char center;
		for (auto& i : _map) {
			if (i.second % 2 != 0) {
				cnt++;
				center = i.first;
				if (cnt >= 2) {
					cout << "I'm Sorry Hansoo";
					return 0;
				}		
			}
		}
		for (auto& i : _map) {
			i.second /= 2;
		}
		for (auto& i : _map) {
			while (i.second > 0) {
				ret += i.first;
				i.second--;
			}
		}
		cout << ret;
		cout << center;
		reverse(ret.begin(), ret.end());
		cout << ret;
	}
}
