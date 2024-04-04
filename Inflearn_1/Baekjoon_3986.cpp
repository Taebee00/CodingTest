// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
// 	int num, cnt=0; string arr[100];
// 	cin >> num;
// 	for (int i = 0;i < num;i++) {
// 		cin >> arr[i];
// 		int j = 0;
// 		while(j<arr[i].length()){
// 			if (arr[i][j] == arr[i][j + 1]) {
// 				arr[i].erase(j, 2);
// 				if (j >= 1) {
// 					j--;
// 				}
// 				else j = 0;
// 			}
// 			else j++;
// 			//cout << arr[i] << endl;
// 		}
// 		if (!arr[i].length()) cnt++;
// 	}
// 	cout << cnt;
// }
#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N ,answer=0;

	cin >> N;

	for (int i=0;i<N;i++){
		stack<char> stk;
		string str;

		cin >> str;

		stk.push(str[0]);

		for (int i=1;i<str.length();i++){
			if (stk.size()&&stk.top()==str[i]){
				stk.pop();
			}
			else stk.push(str[i]);
		}
		
		if (!stk.size()) answer++;
	}
	cout << answer;
}