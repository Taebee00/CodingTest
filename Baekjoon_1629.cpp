#include <bits/stdc++.h>
using namespace std;

long long a, b, c;

long long multi(long long num) {
	if (num == 1) {
		return a % c;
	}
	long long sum = (multi(num / 2) * multi(num / 2))%c;
	if (num %2) sum*=a%c;
	return sum%c;
}

int main()
{
	cin >> a >> b >> c;
	cout << multi(b);
}
