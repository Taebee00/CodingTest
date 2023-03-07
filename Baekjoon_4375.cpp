#include <bits/stdc++.h>
using namespace std;

int main() {
	int input, num = 0, cnt=0;
	while (cin >> input) {
		num=0, cnt = 0;
		while (true) {
			num = (num * 10) + 1;
			cnt++;
			if (num % input == 0) {
				cout << cnt << "\n";
				break;
			}
			num %= input;
		}
	}
}
