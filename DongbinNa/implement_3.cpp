#include <iostream>

using namespace std;

int main()
{
	char location[3];
	int x, y,cnt=0;
	cin >> location;
	x = location[0] - 'a'+1;
	y = location[1] - '0';
	cout << x << ' ' << y;
	int arr[8][2] = { {2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2} };
	for (int i = 0;i < 8;i++)
	{
		if (x + arr[i][0] >= 1 && x + arr[i][0] <= 8 && y+arr[i][1]>=1&& y+arr[i][1]<=8)
		{
			cnt++;
		}
	}
	cout << cnt;
}
