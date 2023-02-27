#include <bits/stdc++.h>
using namespace std;

int main()
{
	int money[101] = { 0, };
	int one, two, three;
	int begin, end;
	cin >> one >> two >> three;
	for (int i = 0;i < 3;i++) {
		cin >> begin >> end;
		for (int j = begin;j < end;j++)
		{
			money[j]++;
		}
	}
	int sum = 0;
	for (int i : money){
		if (i == 3) {
			sum +=(3*three);
		}
		if (i == 2) {
			sum += (2*two);
		}
		if (i == 1) {
			sum += one;
		}
	}
	cout << sum;
}
