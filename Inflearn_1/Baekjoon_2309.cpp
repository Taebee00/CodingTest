#include <bits/stdc++.h>

using namespace std;

int main()
{
	vector<int> small;
	int sum=0;
	for (int i=0;i<9;i++){
		int n;
		cin >> n;
		small.push_back(n);
		sum+=n;
	}
	for (int i=0;i<8;i++){
		for (int j=i+1;j<9;j++){
			if (sum-(small[i]+small[j])==100){
				small.erase(small.begin()+i); 
				small.erase(small.begin()+j-1);
				sort(small.begin(),small.end());
				for (auto i : small){
					cout << i << "\n";
				}
				return 0;
			}
		}
	}
}