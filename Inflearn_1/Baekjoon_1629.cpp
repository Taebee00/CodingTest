#include <bits/stdc++.h>

using namespace std;

long long A,B,C;

long long multi(long long a){
	if (a==1){
		return A%C;
	}
	else if (a%2==1){
		return ((multi(a/2)*multi(a/2))%C*(A%C))%C;
	}
	else{
		return (multi(a/2)*multi(a/2))%C;
	}
}

int main()
{
	cin >> A >> B >> C;
	cout << multi(B);
}