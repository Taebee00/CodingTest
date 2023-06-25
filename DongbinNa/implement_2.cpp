#include <iostream>

using namespace std;

int main()
{
	int time,cnt=0,flag=0;
	cin >> time;
	for (int i = 0;i <= time;i++)
	{
		if (i / 10 == 3 || i % 10 == 3)
		{
			cnt += 3600;
			continue;
		}
		for (int j = 0;j < 60;j++)
		{
			if (j / 10 == 3 || j % 10 == 3)
			{
				cnt += 60;
				continue;
			}
			for (int k = 0;k < 60;k++)
			{
				if (k / 10== 3 || k % 10 == 3)
				{
					cnt++;
				}
			}
		}
	}
	cout << cnt;
}
