#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N, M;
	vector<string> name_v, answer_v;
	map<string,int> name_mp;

	cin >> N >> M;

	for (int i=1;i<=N;i++){
		string name;
		cin >> name;
		name_mp[name]=i;
		name_v.push_back(name);
	}

	for (int i=0;i<M;i++){
		string input;
		cin >> input;
		if (input[0]>='A'&&input[0]<='Z'){
			answer_v.push_back(to_string(name_mp[input]));
			continue;
		}
		else{
			answer_v.push_back(name_v[stoi(input)-1]);
		}
	}
	for (auto i:answer_v){
		cout << i << " ";
	}
}