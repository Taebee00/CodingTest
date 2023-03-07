#include <bits/stdc++.h>
using namespace std;

int main()
{
	int num, select_num;
	int temp_arr[100000];
	cin >> num >> select_num;
	for (int i = 0;i < num;i++) {
		cin >> temp_arr[i];
	}
	int standard;
	int max_sum;
	int sum = 0;
	int temp_sum=0;
	for (int i = 0;i < select_num;i++) {
		temp_sum = temp_sum += temp_arr[i];
		max_sum = temp_sum;
	}
	for (int i = 1; i <= num-select_num;i++) {
		temp_sum = temp_sum - temp_arr[i-1] + temp_arr[i + select_num-1];
		if (temp_sum > max_sum) {
			max_sum = temp_sum;
		}
	}
	cout << max_sum;
}
