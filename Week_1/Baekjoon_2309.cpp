#include <bits/stdc++.h>
using namespace std;

int main()
{
	int small[9];
	vector<int> rsmall;
	int flag = 0;
	for (int i = 0;i < 9;i++) {
		cin >> small[i];
	}
	for (int i = 0;i < 8;i++){
		for (int j = i + 1;j < 9;j++){
			int sum = 0;
			for (int k = 0;k < 9;k++){
				if (k != i && k != j)
				{
					sum += small[k];
				}
			}
			if (sum == 100){
				for (int k=0;k<9;k++){
					if (k != i && k != j){
						rsmall.push_back(small[k]);
					}
				}
				flag = 1;
				break;
			}
			if (flag == 1) {
				break;
			}
		}
		if (flag == 1) {
			break;
		}
	}
	sort(rsmall.begin(), rsmall.end());
	for (auto i : rsmall) {
		cout << i << "\n";
	}
}
