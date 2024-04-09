// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
// 	string str, ret="", ret_reverse;
// 	cin >> str;
// 	map<char, int> _map;
// 	if (str.length() % 2 == 0) {	
// 		for (auto& i : str) {
// 			if (_map[i] >= 0) {
// 				_map[i]++;
// 			}
// 			else {
// 				_map[i] = 0;
// 			}
// 		}
// 		for (auto& i : _map) {
// 			if (i.second % 2 != 0) {
// 				cout << "I'm Sorry Hansoo";
// 				return 0;
// 			}
// 		}
// 		for (auto& i : _map) {
// 			i.second /= 2;
// 		}
// 		for (auto& i : _map) {
// 			while (i.second > 0) {
// 				ret += i.first;
// 				i.second--;
// 			}
// 		}
// 		cout << ret;
// 		reverse(ret.begin(),ret.end());
// 		cout << ret;
// 	}
// 	else {
// 		for (auto& i : str) {
// 			if (_map[i] >= 0) {
// 				_map[i]++;
// 			}
// 			else {
// 				_map[i] = 0;
// 			}
// 		}
// 		int cnt = 0;
// 		char center;
// 		for (auto& i : _map) {
// 			if (i.second % 2 != 0) {
// 				cnt++;
// 				center = i.first;
// 				if (cnt >= 2) {
// 					cout << "I'm Sorry Hansoo";
// 					return 0;
// 				}		
// 			}
// 		}
// 		for (auto& i : _map) {
// 			i.second /= 2;
// 		}
// 		for (auto& i : _map) {
// 			while (i.second > 0) {
// 				ret += i.first;
// 				i.second--;
// 			}
// 		}
// 		cout << ret;
// 		cout << center;
// 		reverse(ret.begin(), ret.end());
// 		cout << ret;
// 	}
// }
#include <bits/stdc++.h>

using namespace std;

int main()
{
	string name, answer_front, answer_back;
	int cnt=0, center_cnt=0;
	char center='1';
	map<char,int> mp;

	cin >> name;

	for (char i:name)	mp[i]++;

	for (auto i:mp){
		if (i.second%2==1){
			cnt++;
			center=i.first;
			if (cnt>1){
				cout << "I'm Sorry Hansoo"; 
				return 0;
			}
		}
	}
	for (auto i:mp){
		//printf("%c ",i.first);
		for (int j=0;j<i.second/2;j++){
			answer_front+=i.first;
		}	
	}
	answer_back=answer_front;
	answer_front=center!='1'?answer_front+center:answer_front;
	reverse(answer_back.begin(),answer_back.end());
	cout << answer_front+answer_back;
}