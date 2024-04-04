// #include <bits/stdc++.h>
// using namespace std;

// int main() {
// 	int input, num = 0, cnt=0;
// 	while (cin >> input) {
// 		num=0, cnt = 0;
// 		while (true) {
// 			num = (num * 10) + 1;
// 			cnt++;
// 			if (num % input == 0) {
// 				cout << cnt << "\n";
// 				break;
// 			}
// 			num %= input;
// 		}
// 	}
// }
#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long input;

	while (cin >> input) {
		long long num=1;
		
		for (int i=2;;i++){
			num=(num*10+1)%input;
			if (!num){
				cout << i << "\n";
				break;
			}
		}
	}
}