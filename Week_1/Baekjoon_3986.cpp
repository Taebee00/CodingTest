#include <bits/stdc++.h>
using namespace std;

int main()
{
	int num, cnt=0; string arr[100];
	cin >> num;
	for (int i = 0;i < num;i++) {
		cin >> arr[i];
		int j = 0;
		while(j<arr[i].length()){
			if (arr[i][j] == arr[i][j + 1]) {
				arr[i].erase(j, 2);
				if (j >= 1) {
					j--;
				}
				else j = 0;
			}
			else j++;
			//cout << arr[i] << endl;
		}
		if (!arr[i].length()) cnt++;
	}
	cout << cnt;
}
