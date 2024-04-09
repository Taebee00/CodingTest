// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
// 	int money[101] = { 0, };
// 	int one, two, three;
// 	int begin, end;
// 	cin >> one >> two >> three;
// 	for (int i = 0;i < 3;i++) {
// 		cin >> begin >> end;
// 		for (int j = begin;j < end;j++)
// 		{
// 			money[j]++;
// 		}
// 	}
// 	int sum = 0;
// 	for (int i : money){
// 		if (i == 3) {
// 			sum +=(3*three);
// 		}
// 		if (i == 2) {
// 			sum += (2*two);
// 		}
// 		if (i == 1) {
// 			sum += one;
// 		}
// 	}
// 	cout << sum;
// }
#include <bits/stdc++.h>

using namespace std;

int main()
{
	int money[4], tm_max=0, sum=0;
	cin >> money[1] >> money[2] >> money[3];
	int arr[101]={0,};
	for (int i=0;i<3;i++){
		pair<int,int> tm;
		cin >> tm.first >> tm.second;
		for (int j=tm.first;j<tm.second;j++){
			arr[j]++;
		}
		if (tm.second>tm_max){
			tm_max=tm.second;
		}
	}
	for (int i=1;i<tm_max;i++){
		sum+=(money[arr[i]]*arr[i]);
	}
	cout << sum;
}