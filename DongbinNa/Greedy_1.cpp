#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

int arr[2][100001];

int main()
{
	int arr_num, max_num, over_num;
	int sum = 0;
	int arr[10001];
	cin >> arr_num >> max_num >> over_num;
	for (int i = 0; i < arr_num; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + arr_num);
	int count = 1;
	while (max_num != 0)
	{
		if (count <= over_num)
		{
			sum += arr[arr_num - 1];
			count++;
		}
		else
		{
			sum += arr[arr_num - 2];
			count = 1;
		}
		max_num--;
	}
	cout << sum;
}
