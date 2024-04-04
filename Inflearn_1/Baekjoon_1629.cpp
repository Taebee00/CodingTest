// #include <bits/stdc++.h>
// using namespace std;

// long long a, b, c;

// long long multi(long long num) {
// 	if (num == 1) {
// 		return a % c;
// 	}
// 	long long sum = (multi(num / 2) * multi(num / 2))%c;
// 	if (num %2) sum*=a%c;
// 	return sum%c;
// }

// int main()
// {
// 	cin >> a >> b >> c;
// 	cout << multi(b);
// }
#include <bits/stdc++.h>

using namespace std;

long long A,B,C;

int multi(int a){
	if (a==1){
		return A%C;
	}
	else if (a%2==1){
		return multi(a/2)*multi(a/2)*(A%C)%C;
	}
	else{
		return multi(a/2)*multi(a/2)%C;
	}
}

int main()
{
	cin >> A >> B >> C;
	cout << multi(B);
}