#include <bits/stdc++.h>
using namespace std;

int main()
{	
	int num, armor, cnt = 0;
	int arr[15000];
	cin >> num >> armor;
	for (int i = 0;i < num;i++) {
		cin >> arr[i];
	}
	for (int i = 0;i < num - 1;i++) {
		for (int j = i+1;j < num;j++) {
			if (arr[i] + arr[j] == armor) {
				cnt++;
			}
		}
	}
	cout << cnt;
}
