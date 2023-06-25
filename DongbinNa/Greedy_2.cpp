#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

int arr[101][101];
int minarr[101];
int maxnum = 0;

int main()
{
	fill_n(minarr, 101, 100);
	int height,width;
	cin >> height >> width;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			cin >> arr[i][j];
			if (minarr[i] > arr[i][j])
			{
				minarr[i] = arr[i][j];
			}
		}
		if (maxnum < minarr[i])
		{
			maxnum = minarr[i];
		}
	}
	cout << maxnum;
}
