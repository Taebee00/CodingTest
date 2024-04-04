#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N, M, answer=0;
	map<int,int> mp;
	
	cin >> N >> M;

	for (int i=0;i<N;i++){
		int num;
		cin >> num;
		auto j=mp.find(M-num);
		if (j==mp.end()){
			mp[num]=1;
		}
		else{
			answer++;
			mp.erase(j);
		}
	}
	cout << answer;
}