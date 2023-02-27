#include <bits/stdc++.h>
using namespace std;

int main()
{
	int player_num;
	string player[150];
	int arr['z' - 'a' + 1] = { 0, };
	cin >> player_num;
	for (int i = 0;i < player_num;i++)
	{
		cin >> player[player_num];
		arr[player[player_num][0] - 'a']++;
	}
	int flag = 0;
	for (int i=0;i<'z'-'a'+1;i++)
	{
		if (arr[i] >= 5) {
			cout << char(i + 'a');
			flag = 1;
		}
	}
	if (flag == 0) {
		cout << "PREDAJA";
	}
}
