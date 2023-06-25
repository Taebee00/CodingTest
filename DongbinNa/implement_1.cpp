#include <iostream>

using namespace std;

int main()
{
	int sz,x=1,y=1;
	cin >> sz;
	char* arr = new char[sz];
	for (auto i = 0;i < sz;i++)
	{
		cin >> arr[i];
		if (arr[i] == 'L')
		{
			if (x == 1)
			{
				continue;
			}
			x--;
		}
		else if (arr[i] == 'R')
		{
			if (x == sz)
			{
				continue;
			}
			x++;
		}
		else if (arr[i] == 'U')
		{
			if (y == 1)
			{
				continue;
			}
			y--;
		}
		else if (arr[i] == 'D')
		{
			if (y == sz)
			{
				continue;
			}
			y++;
		}
		cout << y << ' ' << x;
	}
	cout << y << ' ' << x;
}
