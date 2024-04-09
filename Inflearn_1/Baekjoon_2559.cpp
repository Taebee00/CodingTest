#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N, K;
	int temperture_arr[100001];
	long long sum_arr[100001];
	long long mx=LONG_LONG_MIN;

	cin >> N >> K;

	for (int i=1;i<=N;i++){
		int temperature;
		cin >> temperture_arr[i];
		sum_arr[i]=sum_arr[i-1]+temperture_arr[i];
	}
	for (int i=0;i<=N-K;i++){
		mx=max(mx,sum_arr[i+K]-sum_arr[i]);
	}
	cout << mx;
}